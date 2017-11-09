/*  COM порт используется исходящий COM3  */
#include <PID_v1.h>
#include <Pin.h>

//#define DEBUG
//#define LOOP_TIME_CHECK

Pin sens[] = {4, 3, 2, A5, A4, A3, A2, A1, A0, 13, 11, 8, 7, 12, 6, 5};
int myPinsSize = sizeof(sens) / sizeof(Pin); // Store the length of the array of Pins
Pin button = Pin(A7); Pin battery = Pin(A6);

int speedM1; int speedM2;
byte byteRead;
bool start = false;

// Variables for PID regulator
double Setpoint, Input, Output;
// PID coefficient
double Kp = 0.06, Kd = 0.11, Ki = 0.;
//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
int nom_speed = 255; const int max_speed = 255;       //увеличить время? == скорость реакции мотора

void setup() {
  motorInit();
  Serial.begin(115200);
  //Serial.setTimeout(1000)

  for (int i = 0; i < myPinsSize; i++) sens[i].setInputPullupOn();
  button.setInput(); battery.setInput();

  //initialize the variables we're linked to
  Input = 0;
  Setpoint = 0;
  //turn the PID on
  myPID.SetSampleTime(1);   //время цикла 452мкс
  myPID.SetOutputLimits(-255, 255);
  myPID.SetMode(AUTOMATIC);
}


#ifdef LOOP_TIME_CHECK
unsigned long last = 0;
unsigned long check = 0;
unsigned long last_check = 0;
#endif
#ifdef DEBUG
char line[] = "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n\r";
#endif

void loop() {
#ifdef LOOP_TIME_CHECK
  last_check = micros();
#endif

  // ошибка равна 0, когда оба центральных датчика на линии
  Input = (double)linePosition(sens);
  myPID.Compute();

  speedM1 = nom_speed - Output; speedM2 = nom_speed + Output;
  speedM1 = constrain(speedM1, 0, max_speed); speedM2 = constrain(speedM2, 0, max_speed);
  // ограничение максимальной скорости и исключение работы мотора в обратном направлении

  if (start) motorSpeed(speedM1, speedM2);

  /*  check if data has been sent from the computer: */
  while (Serial.available()) {
    /* read the most recent byte */
    byteRead = Serial.read();
    //Serial.write(byteRead);
    /*Listen for an f sign, stop motors*/
    if (byteRead == 102) {
      start = false;
      motorSpeed(0, 0);
      Serial.println("stop");
    }
    /*Listen for an s sign, start motors*/
    if (byteRead == 115) {
      start = true;
      Serial.println("start");
    }
    /*Listen for an t sign, full power motors*/
    if (byteRead == 116) {
      motorSpeed(255, 255);
      Serial.println("FULL POWER");
    }
    // Receiving 'b', print battery voltage
    if (byteRead == 98) {
      float v = (float)average(battery) * (4.989 / 1024) * 3.;
      Serial.println("Battery voltage = " + String(v));
    }
    // Receiving 'm' before float
    if (byteRead == 109) {
      nom_speed = Serial.parseInt();
      Serial.print("nominal speed = ");
      Serial.println(nom_speed);
    }
    // Receiving 'p' before float
    if (byteRead == 112) {
      Kp = Serial.parseFloat();
      myPID.SetTunings((double)Kp, Ki, Kd);
      Serial.print("new Kp = ");
      Serial.println(myPID.GetKp(), 4);
    }
    // Receiving 'd' before float
    if (byteRead == 100) {
      Kd = Serial.parseFloat();
      myPID.SetTunings(Kp, Ki, (double)Kd);
      Serial.print("new Kd = ");
      Serial.println(myPID.GetKd(), 4);
    }
    // Receiving 'i' before float
    if (byteRead == 105) {
      Ki = Serial.parseFloat();
      myPID.SetTunings(Kp, (double)Ki, Kd);
      Serial.print("new Ki = ");
      Serial.println(myPID.GetKi(), 6);
    }
    /*Listen for an equal sign (byte code 61)*/
    if (byteRead == 61) {
      Serial.print("\nKp = ");
      Serial.print(myPID.GetKp(), 4);
      Serial.print("\tKd = ");
      Serial.print(myPID.GetKd(), 4);
      Serial.print("\tKi = ");
      Serial.print(myPID.GetKi(), 6);
      Serial.print("\tnominal speed = ");
      Serial.println(nom_speed);
    }
  }


  //if (millis() - last > 150) {
  //       last = millis();
  //    // Serial.println(derivative);
  //    Serial.println("Nomspeed = " + String(nom_speed) + "\r");
  //    Serial.println("Input = " + String(Input) + "\r");
  //    Serial.println("Kp = " + String(Kp) + "\r");
  //    Serial.println("Output = " + String(Output) + "\r");
  //    Serial.println("Output = " + String(Output2) + "\r");
  //  //  Serial.println("up * Kp = " + String(up * Kp) + "\r");
  //  //  Serial.println("Kd = " + String(Kd) + "\r");
  //  //  Serial.println("ud = " + String(ud) + "\r");
  //  //  Serial.println("ud * Kd = " + String(ud * Kd) + "\r");
  //    Serial.println("speed M1 = " + String(speedM1) + "\r");
  //    Serial.println("speed M2 = " + String(speedM2) + "\r");
  // }


#ifdef DEBUG
  clearAndHome();
  for (int i = 0, x = 0; i < myPinsSize; i++, x += 2) {
    if (sens[i].getValue()) line[x] = '1';
    else line[x] = '0';
    //Serial.print(sens[i].getValue(), BIN);
    //Serial.print(' ');
  }
  Serial.print(line);
  Serial.print("line position = " + String(linePosition(sens)));
  Serial.print("\n\r");
  delay(150);
#endif
#ifdef LOOP_TIME_CHECK
  check = micros() - last_check;
  Serial.println(check);
#endif
}


