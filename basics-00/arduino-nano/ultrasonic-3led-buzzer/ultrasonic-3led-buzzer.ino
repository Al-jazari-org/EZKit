/*
  Project: Multi-Phase Ultrasonic Distance Alert (3 LEDs + Buzzer)
  Scales LED indicators and synchronized beeping sound across 3 distance phases.
*/

const int trigPin = 5;
const int echoPin = 4;
const int greenLedPin = 6;  // Phase 1: Safe (> 30 cm)
const int yellowLedPin = 7; // Phase 2: Warning (15 to 30 cm)
const int redLedPin = 8;    // Phase 3: Danger (< 15 cm)
const int buzzerPin = 9;    // Passive buzzer for audio feedback

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // إرسال النبضة الصوتية من الحساس
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // قياس زمن الارتداد وحساب المسافة بالسنتيمتر
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // التحكم بالمراحل الثلاث (المصابيح + الصوت المتابع لها)
  if (distance > 30) {
    // المرحلة الأولى (آمن): إضاءة الأخضر وحده ولا يوجد صوت
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    noTone(buzzerPin);
  } 
  else if (distance > 15 && distance <= 30) {
    // المرحلة الثانية (تحذير): إضاءة الأصفر وحده مع صوت متقطع متوسط السرعة
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    
    tone(buzzerPin, 700);   // نغمة متوسطة التردد (700 هرتز)
    delay(200);             // مدة بقاء الصوت
    noTone(buzzerPin);
    delay(300);             // فترة التوقف بين النبضات
  } 
  else {
    // المرحلة الثالثة (خطر): إضاءة الأحمر وحده مع صوت متقطع سريع وحاد
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    
    tone(buzzerPin, 2000);  // نغمة حادة وعالية الخطر (2000 هرتز)
    delay(80);              // صوت سريع جداً
    noTone(buzzerPin);
    delay(80);              // توقف قصير لتسارع الإنذار
  }
}
