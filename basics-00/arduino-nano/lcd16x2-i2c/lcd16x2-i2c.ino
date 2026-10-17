/*
  Course 5: Displaying Information on an I2C LCD with Arduino Nano
  Initializes an I2C 16x2 LCD and prints custom text messages.
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 (common) or 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize the LCD
  lcd.init();                      
  // Turn on the backlight illumination
  lcd.backlight();
  
  // Set cursor to column 0, row 0 (First line)
  lcd.setCursor(0, 0);
  lcd.print("Arduino Nano");
  
  // Set cursor to column 0, row 1 (Second line)
  lcd.setCursor(0, 1);
  lcd.print("LCD Course 5!");
}

void loop() {
}
