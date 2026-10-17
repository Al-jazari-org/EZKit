/*
  Course 3: Measuring Distance with HC-SR04 Ultrasonic Sensor
  Measures distance in cm and displays it via the Serial Monitor.
*/

const int trigPin = 5; // Pin for sending sonic pulse
const int echoPin = 4; // Pin for receiving reflected pulse

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600); // Initialize Serial Communication at 9600 baud
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Send a 10 microsecond HIGH pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin (returns travel time in microseconds)
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance in cm: Speed of sound = 0.034 cm/us (duration/2)
  distance = duration * 0.034 / 2;
  
  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(200); // Small pause between readings
}
