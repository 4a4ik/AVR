// Returns an estimated position of the robot with respect to a line.
// The estimate is made using a weighted average of the sensor indices
// multiplied by 1000, so that a return value of 0 indicates that
// the line is directly below sensor 0, a return value of 1000
// indicates that the line is directly below sensor 1, 2000
// indicates that it's below sensor 2000, etc.  Intermediate
// values indicate that the line is between two sensors.  The
// formula is:
//
//    0*value0 + 1000*value1 + 2000*value2 + ...
//   --------------------------------------------
//         value0  +  value1  +  value2 + ...


long linePosition(Pin *sensor_number)
{
  unsigned long numerator = 0;
  unsigned long denominator = 0;
  static long  x;
  long l, r;
  unsigned long weight[8] = {6000, 1120, 335, 138, 72, 45, 32, 25};   //добавить умножение на 1000

  for (unsigned char i = 0, j = 8; i < 8; i++, j--) {
    unsigned char value = sensor_number[i].getValue();
    numerator += value * j * 1000 * weight[i];
    denominator += value * weight[i];
  }
  if (denominator) l = numerator / denominator;
  else l = 0;

  numerator = 0; denominator = 0;
  for (unsigned char i = 0, j = 8; i < 8; i++, j--) {
    unsigned char value = sensor_number[15 - i].getValue();
    numerator += value * j * 1000 * weight[i];
    denominator += value * weight[i];
  }
  if (denominator) r = numerator / denominator;
  else r = 0;


  if (!l && !r) {
    if (x > 0) return 9000;
    else return -9000;
  }

  x = -l + r;
  return x;
}
