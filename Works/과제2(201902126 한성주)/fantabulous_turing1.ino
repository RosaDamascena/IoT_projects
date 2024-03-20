void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.print ("CDS: ");
  Serial.println (analogRead(A0));
  
  if (analogRead(A0) < 100) 
  {
    for (int i = 0; i <= 255; i++)
    {
    digitalWrite (9, i);
    delay(10);
    }
  }
  if (analogRead(A0) > 100)
  {
    for (int i = 255; i >= 0; i--)
    {
    digitalWrite (9, i);
    delay(10);
    }
  }
}