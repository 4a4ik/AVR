uint16_t average(Pin a) {
  const int sample = 10;
  uint16_t sum = 0;
  for (int i = 0; i < sample; i++) sum += a.getAnalogValue();
  return sum / sample;
}

//9 - левый мотор, 10 - правый мотор
Pin pwmA = Pin(9);  Pin pwmB = Pin(10);
void motorInit() {
  pwmA.setOutput(); pwmB.setOutput();
  pwmA.setDutyCycle(0); pwmB.setDutyCycle(0);
}

void motorSpeed(int speedA, int speedB) {
  //speedA = constrain(speedA, 0, 255);
  //speedB = constrain(speedB, 0, 255);
  pwmA.setDutyCycle(speedA);
  pwmB.setDutyCycle(speedB);
}

#ifdef DEBUG
void clearAndHome()
{
  Serial.write(27);
  Serial.print("[2J"); // clear screen
  Serial.write(27); // ESC
  Serial.print("[H"); // cursor to home
}
#endif
