// C++ code
//
void setup()
{
  pinMode (11, OUTPUT);
  pinMode (3, INPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println (digitalRead(3));
  if (digitalRead(3) == HIGH)
  {
    digitalWrite(11, HIGH);
  }
  else
  {
  digitalWrite (11, LOW);
  }
}