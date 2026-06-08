# Radar System With STM32

![Project Hardware](images/hardware.jpg)

An intelligent radar scanning system built using STM32/ESP-based microcontroller, ultrasonic sensor, servo motor, OLED display, and buzzer alert system.

The system continuously scans the surrounding area by rotating the ultrasonic sensor using a servo motor and detects nearby objects in real time.

---

# Features

- 180° radar scanning
- Real-time object detection
- OLED live distance display
- Servo motor sweeping motion
- Buzzer alert for nearby obstacles
- Serial monitor debugging output
- Compact embedded system project

---

# Components Used

| Component | Description |
|---|---|
| Microcontroller | STM32 / ESP8266 |
| Ultrasonic Sensor | HC-SR04 |
| Servo Motor | SG90 Servo |
| OLED Display | SH1106 128x64 I2C |
| Buzzer | Active Buzzer |
| Arduino IDE | Programming Environment |

---

# Hardware Connections

## Ultrasonic Sensor

| HC-SR04 Pin | Controller Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D2 |
| ECHO | D3 |

---

## Servo Motor

| Servo Pin | Controller Pin |
|---|---|
| Signal | D4 |
| VCC | 5V |
| GND | GND |

---

## Buzzer

| Buzzer Pin | Controller Pin |
|---|---|
| Positive | D5 |
| Negative | GND |

---

## OLED Display (I2C)

| OLED Pin | Controller Pin |
|---|---|
| SDA | D14 |
| SCL | D15 |
| VCC | 3.3V / 5V |
| GND | GND |

---

## Working Principle

The Radar System continuously scans its surroundings by rotating an ultrasonic sensor using a servo motor. The sensor sends ultrasonic waves and waits for the reflected echo from nearby objects.

1. The servo motor rotates the ultrasonic sensor from **0° to 180°**.
2. At each angle, the ultrasonic sensor transmits an ultrasonic pulse.
3. When the pulse hits an object, it reflects back to the sensor.
4. The sensor measures the time taken for the echo to return.
5. The microcontroller calculates the distance using the echo time.
6. The measured distance and current scanning angle are displayed on the OLED screen.
7. If an object is detected within **20 cm**, the OLED displays **"OBJECT!"** and the buzzer is activated.
8. After reaching 180°, the servo rotates back to 0° and repeats the scanning process continuously.

---

## Software Libraries Used

### Servo Library (`Servo.h`)
This library is used to control the SG90 servo motor. It allows the microcontroller to rotate the ultrasonic sensor smoothly between 0° and 180° for radar scanning.

### Arduino Core Library (`Arduino.h`)
This is the standard Arduino library that provides basic functions such as:
- GPIO control (`pinMode`, `digitalWrite`)
- Timing functions (`delay`, `delayMicroseconds`)
- Serial communication (`Serial.print`)

### U8g2 Graphics Library (`U8g2lib.h`)
This library is used to interface with the SH1106 OLED display. It enables displaying:
- Radar title
- Servo angle
- Object distance
- Detection warnings

---

## Distance Calculation

The ultrasonic sensor measures the time taken for a sound wave to travel to an object and return back to the sensor.

### Formula

Distance = (Time × Speed of Sound) / 2

Where:

- **Distance** = Distance between sensor and object
- **Time** = Time taken by the echo signal to return
- **Speed of Sound** = Approximately 343 m/s

The result is divided by 2 because the sound wave travels to the object and then returns back to the sensor.

---

## displayData

The `displayData()` function is responsible for updating the OLED display and Serial Monitor.

### Functions Performed

- Displays the current servo angle.
- Displays the measured object distance.
- Shows an **"OBJECT!"** warning when an obstacle is detected within 20 cm.
- Sends angle and distance information to the Serial Monitor for debugging and monitoring.

### Example Output

```text
Angle: 90
Distance: 15 cm
OBJECT!

---

## buzzerAlert

Activates buzzer when object distance is less than 20 cm.

---

# Project Output

## Hardware Setup
![Hardware Setup](images/hardware.jpg)

---

## OLED Output
![OLED Output](images/output.png)

---

## Serial Monitor Output
![Serial Monitor](images/serial.png)

---

# Example Serial Output

```text
Angle: 45 | Distance: 18 cm
Angle: 48 | Distance: 17 cm
Angle: 51 | Distance: 15 cm
```

---

# Applications

- Obstacle detection systems
- Smart surveillance systems
- Robotic navigation
- Mini radar systems
- Security monitoring
- Distance measurement systems

---

# Future Improvements

- Add real radar graphical interface
- Wireless monitoring using WiFi/Bluetooth
- Mobile app integration
- IoT cloud monitoring
- Multiple sensor integration

---


---

# License

This project is licensed under the Apache License 2.0.
