# Mag's Fantastic Thermometer

This is a project that involves two main technologies: Arduino and Web.

The code that I have right now is being used in a ESP8266 board, NodeMCU V3 (ESP-12E) model, alongside the DHT22 temperature and humidity sensor.
The ESP board creates a web server that shows a page where you can see the temperature and the humidity in real time.

The final goal with this project is having the ESP board read data from different sensors, humidity, light, temperature... As many as I can add.
Later, for that data to be sent in JSON format via an HTTP POST request to the [magnitopic.com NodeJS server](https://github.com/magnitopic/magnitopic.com-express) and stored in the MongoDB database.
The [magnitopic.com](https://www.magnitopic.com/) website will later have a web page from which to show the changes in real time, and some graphs and charts to go along with it.