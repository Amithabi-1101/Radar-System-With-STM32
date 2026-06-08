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

# Working Principle

1. The servo motor rotates from 0° to 180°.
2. The ultrasonic sensor measures object distance.
3. Distance data is displayed on the OLED screen.
4. If an object is detected within 20 cm:
   - OLED displays "OBJECT!"
   - Buzzer turns ON
5. The servo sweeps back from 180° to 0° continuously.

---

# Software Libraries Used

```cpp
#include <Servo.h>
#include <Arduino.h>
#include <U8g2lib.h>
```

---

## getDistance()

Calculates object distance using ultrasonic sensor echo timing.

Formula Used:

Distance = Time × Speed of Sound / 2

Where:

- \( d \) = Distance
- \( t \) = Echo Time
- \( v \) = Speed of Sound

---

## displayData()

Displays:
- Current servo angle
- Measured distance
- Object detection warning

Also prints data to Serial Monitor.

---

## buzzerAlert()

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
