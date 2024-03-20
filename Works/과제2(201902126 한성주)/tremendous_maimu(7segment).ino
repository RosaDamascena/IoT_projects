#define A 4
#define B 5
#define C 12
#define	D 11
#define	E 10
#define	F 3
#define	G 2
#define	DP 13

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
}
void loop()
{
  number_0();
  delay(1000);
  number_1();
  delay(1000);
  number_2();
  delay(1000);
  number_3();
  delay(1000);
  number_4();
  delay(1000);
  number_5();
  delay(1000);
  number_6();
  delay(1000);
  number_7();
  delay(1000);
  number_8();
  delay(1000);
  number_9();
  delay(1000);
}

void number_0() 
{
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, HIGH);
  digitalWrite (DP, HIGH);
}

void number_1() 
{
  digitalWrite (A, HIGH);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
  digitalWrite (DP, HIGH);
}

void number_2() 
{
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, HIGH);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, HIGH);
  digitalWrite (G, LOW);
  digitalWrite (DP, HIGH);
}

void number_3() 
{
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, LOW);
  digitalWrite (DP, HIGH);
}

void number_4() 
{
  digitalWrite (A, HIGH);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
  digitalWrite (DP, HIGH);
}

void number_5() 
{
  digitalWrite (A, LOW);
  digitalWrite (B, HIGH);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, HIGH);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
  digitalWrite (DP, HIGH);
}

void number_6() 
{
  digitalWrite (A, LOW);
  digitalWrite (B, HIGH);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
  digitalWrite (DP, HIGH);
}

void number_7() 
{
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, HIGH);
  digitalWrite (E, HIGH);
  digitalWrite (F, HIGH);
  digitalWrite (G, HIGH);
  digitalWrite (DP, HIGH);
}

void number_8() 
{
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, LOW);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
  digitalWrite (DP, HIGH);
}

void number_9() 
{
  digitalWrite (A, LOW);
  digitalWrite (B, LOW);
  digitalWrite (C, LOW);
  digitalWrite (D, LOW);
  digitalWrite (E, HIGH);
  digitalWrite (F, LOW);
  digitalWrite (G, LOW);
  digitalWrite (DP, HIGH);
}





