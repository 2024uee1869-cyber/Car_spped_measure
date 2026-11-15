# Car Speed Detector Using Arduino

A low-cost speed measurement system built with an Arduino UNO and two IR sensors. It measures the time a moving object (a toy car) takes to travel between two fixed points and calculates its speed in real time.

> Course project: Analysis and Design of Digital Logic Circuits (ADDLC)
> Department of Electrical Engineering, Malaviya National Institute of Technology (MNIT), Jaipur

## Overview

Two IR sensors are placed a known distance apart. When the object crosses the first sensor, the Arduino records a timestamp. When it crosses the second, it records another. Speed is computed from the known distance and the time difference.

**Formulas used**

- Time taken = endTime − startTime
- Speed (m/s) = Distance / Time
- Speed (km/h) = Speed (m/s) × 3.6

## Hardware Components

| Component | Purpose |
|---|---|
| Arduino UNO (ATmega328P) | Timing and speed calculation |
| 2 × IR sensor modules | Object detection at start and end points |
| 16×2 I2C LCD | Real-time display of speed and status (optional) |
| Active 5V buzzer | Audio feedback / overspeed alert (optional) |
| Breadboard and jumper wires | Circuit prototyping |
| USB cable | Power and code upload |
| Toy car | Test object |

## Circuit Connections

| Connection | Arduino Pin |
|---|---|
| IR Sensor 1 OUT | D2 |
| IR Sensor 2 OUT | D3 |
| Sensors VCC / GND | 5V / GND |
| I2C LCD SDA / SCL | A4 / A5 |
| Buzzer (+) | D9 |

![Circuit Diagram](circuit_diagram.png)

## How It Works

1. On power-up, the Arduino starts `millis()` and prints "Car Speed Detector is Ready...".
2. Both IR sensors output HIGH when nothing is detected and LOW when an object passes.
3. When Sensor 1 goes LOW, the start time is stored.
4. When Sensor 2 goes LOW, the end time is stored.
5. The Arduino calculates the speed and prints it in km/h.
6. The system resets and waits for the next object.

## Code

The code is in [`car_speed_detector.ino`](car_speed_detector.ino). The distance between sensors is set at the top of the file:

```cpp
float distance = 0.10; // distance between sensors in meters (10 cm)
```

Change this value if you place the sensors at a different distance.

## How to Run

1. Assemble the circuit as shown above.
2. Open `car_speed_detector.ino` in the Arduino IDE.
3. Select **Board: Arduino UNO** and the correct COM port.
4. Upload the code.
5. Open the Serial Monitor at **9600 baud**.
6. Pass a toy car through both sensors and read the speed.

## Sample Output

```
Car Speed Detector is Ready...
Sensor 1 Triggered!
Sensor 2 Triggered!
Speed: [your measured value] km/h
```

## Applications

- Traffic speed monitoring
- Toll booths and security gates
- Toy car racing and robotics competitions
- Industrial conveyor belt monitoring
- STEM education

## Limitations

- Accuracy depends on sensor placement and sensitivity adjustment.
- `millis()` has 1 ms resolution, so very fast objects reduce accuracy.
- Ambient IR light can cause false triggers.
- Works for small-scale prototypes, not real roads.

## Future Enhancements

- Add LCD and buzzer logic to the code (overspeed alert)
- Use interrupts (`attachInterrupt`) for more precise timing
- Log data to an SD card or send it over Bluetooth / Wi-Fi
- Add a camera module for number plate capture

## Report

Full project report: [`Car_Speed_Detector_Report.pdf`](Car_Speed_Detector_Report.pdf)

## Author

**Nishu Yadav**
B.Tech, Electrical Engineering, MNIT Jaipur
GitHub: [2024uee1869-cyber](https://github.com/2024uee1869-cyber)# Car-Speed-Detector-Arduino
