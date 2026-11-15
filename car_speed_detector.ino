/*
  Car Speed Detector Using Arduino
  Author: Nishu Yadav
  Board: Arduino UNO
  Language: Arduino C/C++

  Two IR sensors are placed a known distance apart.
  The Arduino records the time when the object crosses Sensor 1 and Sensor 2,
  then calculates speed = distance / time and prints it in km/h
  on the Serial Monitor (9600 baud).
*/

const int sensor1 = 2;   // IR Sensor 1 OUT -> D2
const int sensor2 = 3;   // IR Sensor 2 OUT -> D3

unsigned long startTime = 0;
unsigned long endTime = 0;

float distance = 0.10;   // distance between sensors in meters (10 cm)

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

  Serial.println("Car Speed Detector is Ready...");
}

void loop() {
  // Object detected at Sensor 1 -> start timer
  if (digitalRead(sensor1) == LOW) {
    startTime = millis();
    Serial.println("Sensor 1 Triggered!");
    delay(50);
  }

  // Object detected at Sensor 2 -> stop timer and calculate speed
  if (digitalRead(sensor2) == LOW && startTime != 0) {
    endTime = millis();
    Serial.println("Sensor 2 Triggered!");

    unsigned long timeDiff = endTime - startTime;
    float timeInSeconds = timeDiff / 1000.0;
    float speed = distance / timeInSeconds;   // m/s
    float speedKmph = speed * 3.6;            // km/h

    Serial.print("Speed: ");
    Serial.print(speedKmph);
    Serial.println(" km/h");

    startTime = 0;   // reset for next measurement
    delay(500);
  }
}
