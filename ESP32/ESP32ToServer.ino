#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
const char* serverUrl = "http://<your_server_ip>:5000/predict";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  float imu_data = analogRead(34);
  float flex_data = analogRead(35);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    StaticJsonDocument<200> jsonDoc;
    jsonDoc["imu"] = imu_data;
    jsonDoc["flex"] = flex_data;

    String requestBody;
    serializeJson(jsonDoc, requestBody);

    int httpResponseCode = http.POST(requestBody);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(response);
    } else {
      Serial.printf("Error occurred: %s\n", http.errorToString(httpResponseCode).c_str());
    }
    http.end();
  }

  delay(3000);
}
