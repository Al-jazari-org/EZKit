/*
  Lesson 3: Complete Autonomous Environmental Station
  Components: Arduino Uno + MQ-135 + DHT11 + I2C LCD
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2     
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int mqPin = A0;

void setup() {
  dht.begin();
  pinMode(mqPin, INPUT);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("EcoStation Init");
  delay(2000);
}

void loop() {
  // قراءة المعطيات البيئية الشاملة (غازات + مناخ)
  int airValue = analogRead(mqPin);
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  // الصفحة الأولى: عرض درجة الحرارة والرطوبة المناخية
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print((int)temp);
  lcd.print("C Hum:");
  lcd.print((int)hum);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("Climate Status");

  delay(3000); // عرض الصفحة الأولى لمدة 3 ثوانٍ

  // الصفحة الثانية: عرض مؤشر الغازات وجودة الهواء
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Air Pollution");

  lcd.setCursor(0, 1);
  lcd.print("Gas PPM: ");
  lcd.print(airValue);

  delay(3000); // عرض الصفحة الثانية لمدة 3 ثوانٍ
}
