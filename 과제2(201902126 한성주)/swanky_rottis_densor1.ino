#include <Servo.h>

Servo myServo;

void setup()
{
  myServo.attach(9);
}

void loop()
{
  //myServo.write(0);
  //delay(1000);
  //myServo.write(179);
  //delay(1000);
  
  for (int i = 0; i < 180; i++)
  {
    myServo.write(i);
    delay(10);
  }
  
  for (int i = 179; i >= 0; i--)
  {
    myServo.write(i);
    delay(10);
  }
}