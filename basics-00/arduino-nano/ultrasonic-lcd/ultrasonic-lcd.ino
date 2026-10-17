/*
  Course 6: Smart Distance Indicator (HC-SR04 + I2C LCD)
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 5;
const int echoPin = 4;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Smart Distance");
}

void loop() {
  // إرسال نبضة الحساس
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // قياس وقت الارتداد وحساب المسافة
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // عرض المسافة على شاشة LCD
  lcd.setCursor(0, 1);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm   "); // مسافات إضافية لمسح الآثار القديمة للأرقام

  delay(250);
}
