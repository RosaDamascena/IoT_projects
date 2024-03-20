// C++ code
//
void setup()
{
  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A0);
  Serial.print("analog Value :");
  Serial.println(value);
  
  if (value > 500)
  {
    digitalWrite (13, HIGH);
  }
  else
  {
    digitalWrite (13, LOW);
  }
}