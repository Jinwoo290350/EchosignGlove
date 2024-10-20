#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
const int flexPin1 = 34;  // พินสำหรับ Flex Sensor ที่ติดกับหัวแม่มือ
const int flexPin2 = 35;  // พินสำหรับนิ้วชี้
const int flexPin3 = 32;  // พินสำหรับนิ้วกลาง
const int flexPin4 = 33;  // พินสำหรับนิ้วนาง
const int flexPin5 = 25;  // พินสำหรับนิ้วก้อย

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Gesture");  // ชื่ออุปกรณ์ Bluetooth
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

  // ส่งข้อมูล Flex Sensor ไปยังมือถือผ่าน Bluetooth
  String data = String(sensorValue1) + "," + String(sensorValue2) + "," +
                String(sensorValue3) + "," + String(sensorValue4) + "," + 
                String(sensorValue5);
  SerialBT.println(data);

  delay(100);  // ปรับค่า delay ตามความต้องการ
}
