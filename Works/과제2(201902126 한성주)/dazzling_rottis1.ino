void setup()
{
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop()
{
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  
  float distance = pulseIn(6, HIGH) / 57.2;
  
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 100)
  {
    digitalWrite(10, HIGH);
  }
  else
  {
    digitalWrite(10, LOW);
  }
}