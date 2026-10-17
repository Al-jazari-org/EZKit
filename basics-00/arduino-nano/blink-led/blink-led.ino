/*
  Course 1: Controlling an LED with Arduino Nano
  Turns an external LED on and off at 1-second intervals.
*/

const int ledPin = 6; // Pin connected to the LED through a 220 ohm resistor

void setup() {
  // Configure the digital pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);   // Turn the LED ON (apply 5V)
  delay(1000);                  // Wait for 1 second (1000 milliseconds)
  digitalWrite(ledPin, LOW);    // Turn the LED OFF (cut power to 0V)
  delay(1000);                  // Wait for 1 second
}
