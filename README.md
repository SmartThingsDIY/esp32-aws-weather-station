# Weather Station with ESP32 board and AWS IOT
<p>This tutorial shows how to use the <a href="https://amzn.to/2Qs9fcV">DHT11</a> and <a href="https://amzn.to/31t7P8l">DHT22</a> temperature and humidity sensors with the <a href="https://amzn.to/3jmCpqx">ESP32</a> using Arduino IDE. We'll go through a quick introduction to these sensors, pinout, wiring diagram, and finally the Arduino sketch (code).</p>

<h1>⚡️ COMPONENTS AND SUPPLIES</h1>

<img align="right" src="https://github.com/isbkch/esp32-aws-weather-station/blob/master/img/esp-32.jpg?raw=true" style="max-width:100%;" height="350">

<ul>
    <li><a href="https://amzn.to/3jmCpqx">ESP32 Board</a></li>
    <li><a href="https://amzn.to/2Ei40tP">Breadboard</a></li>
    <li><a href="https://amzn.to/2Ehh2ru">Jumper Wires</a></li>
    <li><a href="https://amzn.to/2Qs9fcV">DHT11 Temperature Humidity Sensor</a></li>
</ul><br>
Or use this <a href="https://amzn.to/3hxR01A">KIT from WayinTop</a> that already contains everything
<br>

<h1>WHAT IS A HUMIDITY SENSOR</h1>
<img align="center" src="https://github.com/isbkch/esp32-aws-weather-station/blob/master/img/DHT11-DHT22-Temperature-Humidity-Sensor.jpg?raw=true" style="max-width:100%;" height="350">
<p>The <a href="https://amzn.to/2Qs9fcV">DHT11</a> and <a href="https://amzn.to/31t7P8l">DHT22</a> sensors are used to measure temperature and relative humidity. These are very popular among makers and electronics hobbyists.</p>
<p>These sensors contain a chip that does analog to digital conversion and spit out a digital signal with the temperature and humidity. This makes them very easy to use with any microcontroller.</p>