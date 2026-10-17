/*
  Course 4: Distance-Based LED Indicators with Arduino Nano
  Lights up different LEDs depending on the distance measured by HC-SR04.
*/

const int trigPin = 5;
const int echoPin = 4;

const int greenLedPin = 6;  // Safe distance (> 30 cm)
const int yellowLedPin = 7; // Warning distance (15 to 30 cm)
const int redLedPin = 8;    // Danger distance (< 15 cm)

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Clear and send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read echo time and calculate distance in cm
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Control LEDs based on distance thresholds
  if (distance > 30) {
    digitalWrite(greenLedPin, HIGH);  // Safe: Green ON
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  } 
  else if (distance > 15 && distance <= 30) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH); // Warning: Yellow ON
    digitalWrite(redLedPin, LOW);
  } 
  else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);    // Danger: Red ON
  }
  
  delay(100); // Update interval
}
