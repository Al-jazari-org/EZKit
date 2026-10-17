/*
  Course 8: Complete Distance Monitoring System (LCD + 3 LEDs + Beeping Buzzer)
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 5;
const int echoPin = 4;
const int greenLedPin = 6;
const int yellowLedPin = 7;
const int redLedPin = 8;
const int buzzerPin = 9;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distance Monitor");
}

void loop() {
  // قياس المسافة
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // تحديث شاشة LCD بالمسافة الحية
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   ");

  // التحكم المتزامن (مصابيح + جرس بنبضات متقطعة)
  if (distance > 30) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    noTone(buzzerPin);
    delay(100); // تأخير بسيط لتحديث الشاشة براحة
  } 
  else if (distance > 15 && distance <= 30) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);

    tone(buzzerPin, 800);
    delay(150);
    noTone(buzzerPin);
    delay(250);
  } 
  else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);

    tone(buzzerPin, 2000);
    delay(80);
    noTone(buzzerPin);
    delay(80);
  }
}
