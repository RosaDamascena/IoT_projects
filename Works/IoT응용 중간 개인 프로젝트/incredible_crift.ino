#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD 핀 연결
LiquidCrystal_I2C lcd(32, 16, 2);

// LED 및 부저 핀 연결

int redPin = 6;
int bluePin = 7;
int greenPin = 8;
int buzzerPin = 9;
int switchPin = 10;

int alarmHour = 0;        // 알람 시간 (시)
int alarmMinute = 0;      // 알람 시간 (분)
int alarmDuration = 5;   // 알람 지속 시간 (초)
int snoozeDuration = 5;

unsigned long previousMillis = 0;
unsigned long interval = 1000;  // 1초마다 갱신

bool alarmTriggered = false;    // 알람 활성화 상태
bool snoozeActive = false;      // 스누즈 활성화 상태
unsigned long snoozeStartTime = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Current Time:");

  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  Serial.println(digitalRead(switchPin));

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // 현재 시간 추출
    unsigned long seconds = currentMillis / 1000;
    unsigned long minutes = (seconds / 60) % 60;
    unsigned long hours = (seconds / 3600) % 24;

    // 현재 시간 표시
    lcd.setCursor(0, 1);
    if (hours < 10) {
      lcd.print('0');
    }
    lcd.print(hours);
    lcd.print(':');
    if (minutes < 10) {
      lcd.print('0');
    }
    lcd.print(minutes);
    lcd.print(':');
    if (seconds < 10) {
      lcd.print('0');
    }
    lcd.print(seconds);

    // 알람 확인
    if (hours == alarmHour && minutes == alarmMinute && !alarmTriggered && !snoozeActive) {
      triggerAlarm();
    }

    // 스누즈 확인
    if (snoozeActive && (currentMillis - snoozeStartTime >= snoozeDuration * 60000)) {
      snoozeActive = false;
      alarmTriggered = false;
    }

    // 알람 해제 스위치 확인
    if (digitalRead(switchPin) == LOW && alarmTriggered) {
      delay(50);
      
      if (digitalRead(switchPin) == LOW) {
      	turnOffAlarm();
      }
    }
  }
}

void triggerAlarm() {
  alarmTriggered = true;
  // 알람 활성화 상태로 전환
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Good Morning :)");
  lcd.setCursor(0, 1);
  lcd.print("Wake up!");

  tone(buzzerPin, 1000);   // 피에조 부저 소리 출력
  blinkLED(redPin, 10);    // LED RGB (빨간색) 깜빡임

  // 일정 시간이 지나면 스누즈 활성화
  snoozeActive = true;
  snoozeStartTime = millis();

  // 스누즈 동안 알람 소리 중단
  noTone(buzzerPin);
}

void turnOffAlarm() {
  // 알람 해제
  alarmTriggered = false;
  snoozeActive = false;

  // LED RGB (빨간색) 끄기
  digitalWrite(redPin, LOW);

  // 알람 해제 알림 표시
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Current Time:");
  lcd.setCursor(0, 1);
  lcd.print("Have a nice day");

  // 파란색 LED 표시 및 1분간 유지
  digitalWrite(bluePin, HIGH);
  delay(60000);
  digitalWrite(bluePin, LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Current Time:");
}

void blinkLED(int pin, int duration) {
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
  delay(500);

  unsigned long startTime = millis();
  while (millis() - startTime < (duration * 1000)) {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(200);
  }
} 