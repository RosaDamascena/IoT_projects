#include <Servo.h>
#include <Keypad.h>
// PW 자동문

const byte ROWS = 4;	// 행
const byte COLS = 4;	// 열

char keymatrix[ROWS][COLS] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte colPins[COLS] = {6, 7, 8, 9};	// 열 가로
byte rowPins[ROWS] = {2, 3, 4, 5};	// 행 가로

Keypad mykeypad = Keypad (
  makeKeymap (
    keymatrix
  ),
  rowPins, 
  colPins, 
  4, 
  4
);

Servo myservo;

char pw[4] = {'1', '2', '3', '4'};
int count = 0;
int tru = 0;

void setup()
{
  Serial.begin(9600);
  myservo.attach(13);
  myservo.write(0);
}

void loop()
{
  char push = mykeypad.getKey();
  
  if (push)
  {
    Serial.println(push);
    if (push == pw[count])	// pw가 맞았을 때
    {
      count++;
      tru++;
    }
    else if (push != pw[count])	// pw가 틀렸을 때
    {
      count++;
    }
    
    if (count == 4)	// pw 정답
    {
      if (tru == 4)
      {
        myservo.write (179);
        Serial.println ("Open the door");
        delay (5000);
        myservo.write (0);
        Serial.println ("Close the door");
      }
      else
      {
        myservo.write (0);
        Serial.println ("PW incorrect!");
      }
      count = 0;
      tru = 0;
    }
  }
}







