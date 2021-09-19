from sense_hat import SenseHat
import schedule, requests

sense = SenseHat()

def newRequest():
	pload = {"temperature":str(round(sense.temp,1)),"humidity":str(round(sense.humidity,1))}
	r = requests.post('https://limitless-refuge-99811.herokuapp.com/esp',data = pload)
	print(r.text)

newRequest()
if __file__=='__main___':
	schedule.every(60).minutes.do(newRequest)