#include <Servo.h>
#include <Arduino.h>
#include <U8g2lib.h>

// =====================================
// OLED Hardware I2C
// SDA -> D14
// SCL -> D15
// =====================================
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

// =====================================
// Pin Definitions
// =====================================
#define TRIG_PIN   D2
#define ECHO_PIN   D3
#define SERVO_PIN  D4
#define BUZZER_PIN D5

Servo radarServo;

long duration;
int distance;

// =====================================
// Setup
// =====================================
void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);

  pinMode(ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  radarServo.attach(SERVO_PIN);

  // OLED Start
  u8g2.begin();

  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_6x12_tr);

  u8g2.drawStr(20, 30, "RADAR SYSTEM");

  u8g2.sendBuffer();

  delay(2000);

  Serial.println("Radar Started");
}

// =====================================
// Main Loop
// =====================================
void loop() {

  // Sweep Left -> Right
  for(int angle = 0; angle <= 180; angle += 3) {

    radarServo.write(angle);

    delay(15);

    distance = getDistance();

    displayData(angle, distance);

    buzzerAlert();
  }

  // Sweep Right -> Left
  for(int angle = 180; angle >= 0; angle -= 3) {

    radarServo.write(angle);

    delay(15);

    distance = getDistance();

    displayData(angle, distance);

    buzzerAlert();
  }
}

// =====================================
// Distance Function
// =====================================
int getDistance() {

  digitalWrite(TRIG_PIN, LOW);

  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  int distanceCm = duration * 0.034 / 2;

  return distanceCm;
}

// =====================================
// OLED Display
// =====================================
void displayData(int angle, int distance) {

  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_6x12_tr);

  // Title
  u8g2.drawStr(18, 10, "RADAR SYSTEM");

  // Angle
  u8g2.setCursor(0, 30);
  u8g2.print("Angle: ");
  u8g2.print(angle);

  // Distance
  u8g2.setCursor(0, 50);
  u8g2.print("Dist: ");
  u8g2.print(distance);
  u8g2.print(" cm");

  // Object Detection
  if(distance > 0 && distance < 20) {

    u8g2.drawStr(70, 50, "OBJECT!");
  }

  u8g2.sendBuffer();

  // Serial Monitor
  Serial.print("Angle: ");
  Serial.print(angle);

  Serial.print(" | Distance: ");
  Serial.print(distance);

  Serial.println(" cm");
}

// =====================================
// Buzzer Alert
// =====================================
void buzzerAlert() {

  if(distance > 0 && distance < 20) {

    digitalWrite(BUZZER_PIN, HIGH);
  }
  else {

    digitalWrite(BUZZER_PIN, LOW);
  }
}