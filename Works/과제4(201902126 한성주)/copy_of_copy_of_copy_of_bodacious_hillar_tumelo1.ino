#include <Keypad.h>


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

void setup()
{
  pinMode (10, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (13, OUTPUT);
  pinMode (0, OUTPUT);
  pinMode (1, OUTPUT);
}

void loop()
{
  char push = mykeypad.getKey();
  
  if (push == '2' || push == 'A')
  {
    front();
    digitalWrite (0, LOW);
    digitalWrite (1, LOW);
  }
  else if (push == '8' || push == 'C')
  {
    back();
    digitalWrite (0, LOW);
    digitalWrite (1, LOW);
  }
  else if (push == '4' || push == 'B')
  {
    left();
    digitalWrite (0, HIGH);
    digitalWrite (1, LOW);
  }
  else if (push == '6' || push == 'D')
  {
    right();
    digitalWrite (0, LOW);
    digitalWrite (1, HIGH);
  }
  else if (push == '5' || push == '0')
  {
    stop();
    digitalWrite (0, LOW);
    digitalWrite (1, LOW);
  }
  else if (push == '7' || push == '*')
  {
    left_turn();
    digitalWrite (0, LOW);
    digitalWrite (1, LOW);
  }
  else if (push == '9' || push == '#')
  {
    right_turn();
    digitalWrite (0, LOW);
    digitalWrite (1, LOW);
  }
}

void front()
{
  digitalWrite (10, HIGH);
  digitalWrite (11, LOW);
  digitalWrite (12, HIGH);
  digitalWrite (13, LOW);
}

void back()
{
  digitalWrite (10, LOW);
  digitalWrite (11, HIGH);
  digitalWrite (12, LOW);
  digitalWrite (13, HIGH);
}

void stop()
{
  digitalWrite (10, LOW);
  digitalWrite (11, LOW);
  digitalWrite (12, LOW);
  digitalWrite (13, LOW);
}

void left()
{
  digitalWrite (10, HIGH);
  digitalWrite (11, LOW);
  digitalWrite (12, LOW);
  digitalWrite (13, LOW);
}

void right()
{
  digitalWrite (10, LOW);
  digitalWrite (11, LOW);
  digitalWrite (12, HIGH);
  digitalWrite (13, LOW);
}

void right_turn()
{
  digitalWrite (10, LOW);
  digitalWrite (11, HIGH);
  digitalWrite (12, HIGH);
  digitalWrite (13, LOW);
}

void left_turn()
{
  digitalWrite (10, HIGH);
  digitalWrite (11, LOW);
  digitalWrite (12, LOW);
  digitalWrite (13, HIGH);
}






