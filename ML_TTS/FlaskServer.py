from flask import Flask, request, jsonify
import numpy as np
import tensorflow as tf

model = tf.keras.models.load_model('efficientnetb3_model.h5')

app = Flask(__name__)

@app.route('/predict', methods=['POST'])
def predict():
    data = request.get_json()

    imu = float(data['imu'])
    flex = float(data['flex'])

    input_data = np.array([[imu, flex]])
    input_data = np.expand_dims(input_data, axis=0)

    prediction = model.predict(input_data)
    predicted_class = np.argmax(prediction, axis=1)

    char = chr(predicted_class[0] + 65)

    return jsonify({'character': char})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
