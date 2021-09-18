from sense_hat import SenseHat
import requests

sense = SenseHat()

def newRequest():
	pload = {"temperature":str(round(sense.temp)),"humidity":str(round(sense.humidity))}
	r = requests.post('https://limitless-refuge-99811.herokuapp.com/esp',data = pload)
	print(r.text)

newRequest()