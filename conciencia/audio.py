import time
from naoqi import ALProxy


ROBOT_IP = "127.0.0.1"

# Creates a proxy on the speech-recognition module
asr = ALProxy("ALSpeechRecognition", ROBOT_IP, 9559)

asr.setLanguage("Spanish")

# Example: Adds "yes", "no" and "please" to the vocabulary (without wordspotting)
vocabulary = ["hola", "no", "ayuda"]
asr.setVocabulary(vocabulary, False)

# Start the speech recognition engine with user Test_ASR
asr.subscribe("Test_ASR")
print 'Speech recognition engine started'
time.sleep(20)
asr.unsubscribe("Test_ASR")
