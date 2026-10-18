/*
  Lesson 2: Climate Temperature & Humidity Monitor (DHT11 + I2C LCD)
  Target Board: Arduino Uno
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2     // سلك البيانات موصول بالمنفذ D2
#define DHTTYPE DHT11   // تحديد نوع الحساس DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Climate Monitor");

  dht.begin();
  delay(2000); // منح الحساس وقتاً للاستقرار بعد الإقلاع
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature(); 

  // فحص سلامة القراءة من الحساس
  if (isnan(hum) || isnan(temp)) {
    lcd.setCursor(0, 1);
    lcd.print("Sensor Error!   ");
    delay(1000);
    return;
  }

  // عرض الحرارة والرطوبة على الشاشة
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print((int)temp);
  lcd.print("C Hum:");
  lcd.print((int)hum);
  lcd.print("% ");

  delay(2000);
}
