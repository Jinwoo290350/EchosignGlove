// (ESP32 Code to Read Sensor Data and Send via Bluetooth)
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
const int flexPin1 = 34;  // Thumb
const int flexPin2 = 35;  // Index finger
const int flexPin3 = 32;  // Middle finger
const int flexPin4 = 33;  // Ring finger
const int flexPin5 = 25;  // Pinky finger

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Gesture");  // Bluetooth device name
  pinMode(flexPin1, INPUT);
  pinMode(flexPin2, INPUT);
  pinMode(flexPin3, INPUT);
  pinMode(flexPin4, INPUT);
  pinMode(flexPin5, INPUT);
}

void loop() {
  int sensorValue1 = analogRead(flexPin1);
  int sensorValue2 = analogRead(flexPin2);
  int sensorValue3 = analogRead(flexPin3);
  int sensorValue4 = analogRead(flexPin4);
  int sensorValue5 = analogRead(flexPin5);

  // Send sensor values via Bluetooth as a comma-separated string
  String data = String(sensorValue1) + "," + String(sensorValue2) + "," + 
                String(sensorValue3) + "," + String(sensorValue4) + "," +
                String(sensorValue5);
  SerialBT.println(data);

  delay(100);  // Adjust delay as needed
}
