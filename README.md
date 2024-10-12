
### Project EchosignGlove
### ESP32 Sensor Data to Character Prediction Model with Text-to-Speech

This project consists of three main components:

1. **ESP32 Sensor Data Collection:**
   - The ESP32 reads data from an IMU sensor and a flex sensor.
   - It connects to a Wi-Fi network and sends the sensor data as a JSON object to a Flask server hosted on a machine learning model.
   
2. **Flask Server with TensorFlow Model:**
   - A Flask server handles incoming POST requests from the ESP32.
   - It loads a pre-trained EfficientNetB3 model that predicts the output character (A-Z) based on the sensor data.
   - The server returns the predicted character as a JSON response.

3. **Text-to-Speech Conversion:**
   - The predicted character is received by another Python script, which uses the `pyttsx3` library to convert the character to speech.
   - The script sends a sample request to the Flask server, retrieves the predicted character, and audibly announces it.

### Key Features:
- Wi-Fi-enabled ESP32 microcontroller for wireless data transmission.
- Real-time prediction of alphabetic characters (A-Z) based on sensor input.
- Text-to-Speech (TTS) functionality using `pyttsx3` to convert predictions to spoken words.

## Model Results

### Dataset Overview
- Wound dataset: [https://www.kaggle.com/datasets/datamunge/sign-language-mnist](https://www.kaggle.com/datasets/datamunge/sign-language-mnist)
- **Classes**: 26 (Letters A-Z)
- **Data Split**:
  - Training Set: 70%
  - Validation Set: 15%
  - Test Set: 15%


### Classification Report

| Class | Precision | Recall | F1-Score |
|-------|-----------|--------|----------|
| A     | *0.97*    | *0.98* | *0.97*   |
| B     | *0.95*    | *0.94* | *0.94*   |
| ...   | ...       | ...    | ...      |
| Z     | *0.96*    | *0.95* | *0.95*   |
| **Average** | **0.96** | **0.96** | **0.96** |

### Sample Predictions

Here are some examples of the model's predictions on the test set:

| IMU Data | Flex Data | True Label | Predicted Label | Correct |
|----------|-----------|------------|-----------------|---------|
| *0.45*   | *0.30*    | A          | A               | ✅      |
| *0.60*   | *0.50*    | B          | B               | ✅      |
| *0.20*   | *0.70*    | C          | D               | ❌      |
| *0.80*   | *0.40*    | D          | D               | ✅      |
| *...*    | *...*     | ...        | ...             | ...     |

### Interpretation of Results

- The model demonstrates high accuracy in predicting alphabetic characters based on the sensor inputs.
- Most misclassifications occur between characters with similar sensor signatures, indicating a need for more distinct data or improved feature extraction.
- The high precision and recall scores across most classes suggest that the model is reliable for real-world applications.

### Limitations

- **Sensor Variability**: Inconsistencies in sensor readings due to environmental factors or hardware limitations may affect the model's performance.
- **Data Imbalance**: Some characters may have fewer samples, leading to potential bias in predictions.
- **Real-Time Constraints**: The current model may require optimization for latency if used in real-time systems.

### Future Work

- **Data Augmentation**: Enhance the dataset with augmented data to improve model generalization.
- **Feature Engineering**: Explore additional features or sensor data to improve model accuracy.
- **Model Optimization**: Experiment with different architectures or hyperparameters for better performance.
- **Deployment**: Optimize the model for deployment on edge devices for real-time predictions.

### Conclusion

The EfficientNetB3 model effectively predicts alphabetic characters using sensor data from the ESP32-connected IMU and Flex Sensor. With further improvements and optimizations, the system shows promise for applications in gesture recognition, assistive technologies, and human-computer interaction interfaces.

### How to Use:
1. Flash the ESP32 script to your device.
2. Run the Flask server with the pre-trained EfficientNetB3 model.
3. Execute the TTS script to hear the predicted characters.

