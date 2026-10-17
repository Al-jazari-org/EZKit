/*
  Course 2: Controlling a Passive Buzzer with Arduino Nano
  Generates audio tones using the tone() function.
*/

const int buzzerPin = 9; // Pin connected to the passive buzzer

void setup() {
  // Note: tone() automatically handles pin configuration, 
  // but you can also explicitly define pinMode(buzzerPin, OUTPUT); if preferred.
}

void loop() {
  tone(buzzerPin, 1000);  // Play a 1000 Hz tone on pin 9
  delay(1000);            // Hold the tone for 1 second
  noTone(buzzerPin);      // Stop the tone
  delay(1000);            // Pause for 1 second
}
