#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "DHT.h"

const char *ssid = "";
const char *password = "";

//Some settings for the DHT22 sensor
#define DHTTYPE DHT22

    uint8_t DHTPin = D8;

DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;

//We start the program
void setup(){
  Serial.begin(115200);

  pinMode(DHTPin, INPUT);

  dht.begin();

  //Connect to the wi-fi network
  WiFi.begin(ssid, password);

  //check if we're connected to the wi-fi network
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
}

void loop(){

  Temperature = dht.readTemperature(); // Gets the values of the temperature
  Humidity = dht.readHumidity();       // Gets the values of the humidity

  HTTPClient http; //Declare object of class HTTPClient

  http.begin("http://192.168.1.33/esp"); //Specify request destination
  http.addHeader("Content-Type", "application/json"); //Specify content-type header
  //text/plain

  int httpCode = http.POST("{\"text\":\"mag\ "}"); //Send the request
  String payload = http.getString();                //Get the response payload

  Serial.println(httpCode); //Print HTTP return code
  Serial.println(payload);  //Print request response payload

  http.end(); //Close connection

  delay(30000); //Send a request every 30 seconds
}