// C++ code
//
void setup()
{
  pinMode(8, OUTPUT);	//LED
  pinMode(3, INPUT);	//SWITCH
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(3) == HIGH) //digitalRead(3) != LOW
  {
    digitalWrite(8, HIGH);
    Serial.println(digitalRead(3));
	}
   else
   {
     digitalWrite(8, LOW);
     Serial.println(digitalRead(3));
   }
}