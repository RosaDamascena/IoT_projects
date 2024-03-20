#include <IRremote.h>

IRrecv myRemocon(7);
decode_results result;

void setup()
{
  myRemocon.enableIRIn();
  Serial.begin(9600);
  pinMode (8, OUTPUT);	// Wheel 1 +
  pinMode (9, OUTPUT);	// wheel 1 -
  pinMode (10, OUTPUT);	// wheel 2 +
  pinMode (11, OUTPUT);	// wheel 2 -
}

void loop()
{
  if (myRemocon.decode(&result))
  {
    Serial.println(result.value, HEX);
    
    if (result.value == 0xFD8877)	// FRONT 2
    {
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      digitalWrite (10, HIGH);
      digitalWrite (11, LOW);
    }
    else if (result.value == 0xFD9867)	// BACK 8
    {
      digitalWrite (8, LOW);
      digitalWrite (9, HIGH);
      digitalWrite (10, LOW);
      digitalWrite (11, HIGH);
    }
    else if (result.value == 0xFDA857)	// STOP 5
    {
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (10, LOW);
      digitalWrite (11, LOW);
    }
    else if (result.value == 0xFD28D7)	// LEFT 4
    {
      digitalWrite (8, HIGH);
      digitalWrite (9, LOW);
      digitalWrite (10, LOW);
      digitalWrite (11, LOW);
    }
    else if (result.value == 0xFD6897)	// RIGHT 6
    {
      digitalWrite (8, LOW);
      digitalWrite (9, LOW);
      digitalWrite (10, HIGH);
      digitalWrite (11, LOW);
    }
    
    myRemocon.resume();	// 다음 데이터 처리를 위해
  }
  delay(300);	// 데이터가 깨짐을 방지하기 위해
}