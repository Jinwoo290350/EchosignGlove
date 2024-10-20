//Android Code to Receive Bluetooth Data and Use TTS)

package com.example.flexsensor;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;
import android.speech.tts.TextToSpeech;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.InputStream;
import java.util.Locale;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    private BluetoothAdapter bluetoothAdapter;
    private BluetoothSocket bluetoothSocket;
    private InputStream inputStream;
    private TextToSpeech tts;

    // UUID for Bluetooth SPP
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize TTS
        tts = new TextToSpeech(this, status -> {
            if (status == TextToSpeech.SUCCESS) {
                tts.setLanguage(Locale.US);
            }
        });

        // Initialize Bluetooth
        bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        BluetoothDevice device = bluetoothAdapter.getRemoteDevice("ESP32_MAC_ADDRESS"); // Replace with ESP32 MAC address

        try {
            bluetoothSocket = device.createRfcommSocketToServiceRecord(MY_UUID);
            bluetoothSocket.connect();
            inputStream = bluetoothSocket.getInputStream();

            // Start listening for data from ESP32
            listenForData();
        } catch (Exception e) {
            e.printStackTrace();
            Toast.makeText(this, "Error connecting to Bluetooth device", Toast.LENGTH_SHORT).show();
        }
    }

    private void listenForData() {
        byte[] buffer = new byte[1024];
        int bytes;

        while (true) {
            try {
                // Read data from Bluetooth
                bytes = inputStream.read(buffer);
                String data = new String(buffer, 0, bytes);
                processGestureData(data);
            } catch (Exception e) {
                break;
            }
        }
    }

    private void processGestureData(String data) {
        // Split the comma-separated sensor values
        String[] sensorValues = data.split(",");
        int thumb = Integer.parseInt(sensorValues[0]);
        int index = Integer.parseInt(sensorValues[1]);
        int middle = Integer.parseInt(sensorValues[2]);
        int ring = Integer.parseInt(sensorValues[3]);
        int pinky = Integer.parseInt(sensorValues[4]);

        // Recognize the gesture using AI model (placeholder method)
        String recognizedGesture = recognizeGesture(thumb, index, middle, ring, pinky);

        // Convert recognized gesture to speech
        if (recognizedGesture != null) {
            tts.speak(recognizedGesture, TextToSpeech.QUEUE_FLUSH, null, null);
        }
    }

    // Placeholder for gesture recognition logic
    private String recognizeGesture(int thumb, int index, int middle, int ring, int pinky) {
        // Implement AI model prediction here
        // For now, returning a dummy value
        return "Gesture Recognized";
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        try {
            bluetoothSocket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

        if (tts != null) {
            tts.stop();
            tts.shutdown();
        }
    }
}
