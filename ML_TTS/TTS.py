import pyttsx3
import requests

engine = pyttsx3.init()
engine.setProperty('rate', 150)
engine.setProperty('volume', 1)

def speak(text):
    engine.say(text)
    engine.runAndWait()

url = 'http://<your_server_ip>:5000/predict'
response = requests.post(url, json={'imu': 0.5, 'flex': 0.2})
character = response.json()['character']

print(f'Predicted Character: {character}')
speak(f'The character is {character}')
