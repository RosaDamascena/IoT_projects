// C++ code
//
void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A0);
  int finalvalue = map(value, 767, 964, 0, 255);
  
  analogWrite(9, finalvalue);
  
  Serial.println(analogRead(A0));
  
  delay(100);
}