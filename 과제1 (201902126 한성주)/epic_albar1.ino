// C++ code
//
void setup()
{
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A0);
  int finalvalue = map (value, 0, 1023, 0, 255);
  
  analogWrite(9, finalvalue);
  
  Serial.print ("Value : ");
  Serial.println (value);
  Serial.print ("finalvalue : ");
  Serial.println(finalvalue);
  
  delay(200);
}