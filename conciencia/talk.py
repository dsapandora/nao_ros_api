from naoqi import ALProxy
tts = ALProxy("ALTextToSpeech", "192.168.0.104", 9559)
tts.say("tengo pereza")
