# ESP32 Flex Sensor Gesture Recognition with Bluetooth & TTS

This project allows an ESP32 to read data from flex sensors attached to five fingers, recognize hand gestures using AI, and send the recognized gestures to a mobile phone via Bluetooth. The mobile phone then uses Text-to-Speech (TTS) to convert the recognized gesture into audible speech.

## Features
- **Flex Sensor Integration**: Detects bending of fingers using flex sensors.
- **Bluetooth Communication**: Sends sensor data from ESP32 to a mobile phone.
- **AI Gesture Recognition**: Uses a trained AI model to recognize hand gestures.
- **Text-to-Speech (TTS)**: Converts recognized gestures into speech on the mobile phone.

## Components
- **ESP32**: Microcontroller used to read flex sensor data and send it via Bluetooth.
- **Flex Sensors**: Attached to five fingers (thumb, index, middle, ring, pinky) to detect their bending positions.
- **Mobile Phone**: Receives data via Bluetooth and performs gesture recognition and TTS.

## Project Structure
```
/ESP32_Flex_Sensor
├── src
│   ├── esp32_flex_sensor.ino        # ESP32 code to read sensor data and send via Bluetooth
│   └── model_training.ipynb          # Notebook for AI model training (optional)
    └── model_training(HaveData).ipynb          # Notebook for AI model training (HaveData)
├── app
│   ├── MainActivity.java             # Android code to receive Bluetooth data and use TTS
│   └── tts_service.java              # Android service for Text-to-Speech
├── models
│   └── gesture_model.tflite          # Trained TensorFlow Lite model for gesture recognition
└── README.md                         # Project documentation
```

## Getting Started

### 1. Hardware Setup
- Attach flex sensors to each of the five fingers (thumb, index, middle, ring, pinky).
- Connect the flex sensors to the analog input pins of the ESP32.

### 2. ESP32 Setup
- Flash the `esp32_flex_sensor.ino` to your ESP32.
- The code will read the analog values from the flex sensors and send them as a comma-separated string via Bluetooth to the paired mobile phone.
  
**Example:**
```cpp
34,35,32,33,25
```

### 3. Mobile Application
- Develop an Android app (or use the example provided) that can connect to the ESP32 via Bluetooth.
- Implement AI gesture recognition using TensorFlow Lite, or use simple conditional statements based on the sensor values.
- Use the TTS feature on the phone to convert recognized gestures into speech.

### 4. AI Model Training
- Collect data from the flex sensors for various gestures (as shown in the image).
- Train a TensorFlow model using this data to recognize specific gestures.
- Convert the trained model to TensorFlow Lite format and deploy it to the mobile app.

### 5. Running the Project
- Power the ESP32 and make sure it’s connected to the flex sensors.
- Pair the mobile phone with the ESP32 via Bluetooth.
- The mobile app will receive the sensor data, recognize the gesture, and speak out the corresponding text.

## Example Gestures
- **A**: Thumb up
- **B**: Hand in a fist
- **C**: Open hand
- **D**: Pointing with index finger

## Dependencies
- **Arduino IDE**: For flashing code to the ESP32.
- **Android Studio**: For developing the mobile app (if using Android).
- **TensorFlow Lite**: For running the AI model on the mobile phone.
- **TextToSpeech API**: For converting recognized text into speech.

## Future Work
- Implement gesture recognition for more complex hand gestures.
- Improve the accuracy of the AI model with more training data.
- Add support for iOS using CoreBluetooth and AVSpeechSynthesizer for TTS.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
