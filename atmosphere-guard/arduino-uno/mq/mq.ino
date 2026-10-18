/*
  Lesson 1: Air Quality & Gas Monitor (MQ-135 + I2C LCD)
  Target Board: Arduino Uno
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int mqPin = A0; // المنفذ التناظري المخصص لقراءة حساس الغاز

void setup() {
  pinMode(mqPin, INPUT);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Gas & Air Mon");
}

void loop() {
  // قراءة القيمة التناظرية لحساس الغاز (من 0 إلى 1023)
  int airValue = analogRead(mqPin);

  // عرض القيمة على شاشة LCD
  lcd.setCursor(0, 1);
  lcd.print("Gas PPM: ");
  lcd.print(airValue);
  lcd.print("   "); // مساحات فارغة لمسح الآثار القديمة للأرقام

  delay(500); // تحديث دوري سريع
}
