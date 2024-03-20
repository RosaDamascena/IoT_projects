// C++ code
//
void setup()
{
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(7));
  
  if (digitalRead(7) == HIGH)
  {
   digitalWrite (8, HIGH); 
  }
  else
  {
   digitalWrite (8, LOW); 
  }
}