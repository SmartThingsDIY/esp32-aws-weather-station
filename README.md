# Weather Station with ESP32 board and AWS IOT
<p>This tutorial shows how to use the <a href="https://amzn.to/2Qs9fcV">DHT11</a> and <a href="https://amzn.to/31t7P8l">DHT22</a> temperature and humidity sensors with the <a href="https://amzn.to/3jmCpqx">ESP32</a> using Arduino IDE. We'll go through a quick introduction to these sensors, pinout, wiring diagram, and finally the Arduino sketch (code).</p>

<h1>⚡️ COMPONENTS AND SUPPLIES</h1>

<img align="right" src="https://github.com/isbkch/esp32-aws-weather-station/blob/master/img/esp-32.jpg?raw=true" style="max-width:100%;" height="200">

<ul>
    <li><a href="https://amzn.to/3jmCpqx">ESP32 Board</a></li>
    <li><a href="https://amzn.to/2Ei40tP">Breadboard</a></li>
    <li><a href="https://amzn.to/2Ehh2ru">Jumper Wires</a></li>
    <li><a href="https://amzn.to/2Qs9fcV">DHT11</a> or <a href="https://amzn.to/31t7P8l">DHT22</a> Temp & Humidity Sensor</a></li>
    <li><a href="https://amzn.to/2Qo7vkW">10k Ohm resistor</a></li>

</ul><br>
Or use this <a href="https://amzn.to/3hxR01A">KIT from WayinTop</a> that already contains everything
<br>

<h1>🚀APPS</h1>
<ul>
    <li><a href="https://www.arduino.cc/en/main/software">Arduino IDE</a></li>
    <li><a href="https://docs.aws.amazon.com/cli/latest/userguide/cli-chap-install.html">AWS cli</a></li>
</ul>

<h1>DHT11 vs DHT22 SENSORS</h1>
<img align="center" src="https://github.com/isbkch/esp32-aws-weather-station/blob/master/img/DHT11-DHT22-Temperature-Humidity-Sensor.jpg?raw=true" style="max-width:100%;" height="350">
<p>The <a href="https://amzn.to/2Qs9fcV">DHT11</a> and <a href="https://amzn.to/31t7P8l">DHT22</a> sensors are used to measure temperature and relative humidity. These are very popular among makers and electronics hobbyists.</p>
<p>These sensors contain a chip that does analog to digital conversion and spit out a digital signal with the temperature and humidity. This makes them very easy to use with any microcontroller.</p>
<p>The DHT11 and DHT22 are very similar, but differ in their specifications.</p>

<p>The DHT22 sensor has a better resolution and a wider temperature and humidity measurement range. However, it is a bit more expensive, and you can only request readings with 2 seconds interval.</p>

<p>The DHT11 has a smaller range and it's less accurate. However, you can request sensor readings every second. It's also a bit cheaper.</p>

<p>Despite their differences, they work in a similar way, and you can use the same code to read temperature and humidity. You just need to select in the code the sensor type you're using.</p>

<h1>Schematic Diagram</h1>

<p>Wire the <a href="https://amzn.to/2Qs9fcV">DHT11</a> or <a href="https://amzn.to/31t7P8l">DHT22</a> sensor to the <a href="https://amzn.to/3jmCpqx">ESP32</a> development board as shown in the following schematic diagram.</p>

<img align="center" src="https://github.com/isbkch/esp32-aws-weather-station/blob/master/img/schematic.png?raw=true" style="max-width:100%;" height="600">

<h1>Installing Libraries</h1>
<p>To read from the DHT sensor, we'll use the <a href="https://github.com/adafruit/DHT-sensor-library">DHT library from Adafruit</a>. To use this library you also need to install the <a href="https://github.com/adafruit/Adafruit_Sensor">Adafruit Unified Sensor library</a>. Follow the next steps to install those libraries.</p>

<p>Open your Arduino IDE and go to <strong>Sketch > Include Library > Manage Libraries</strong>. The Library Manager should open.</p>

<p>Search for <strong>"DHT"</strong> on the Search box and install the DHT library from Adafruit.</p>

<img align="center" src="https://github.com/isbkch/esp32-aws-weather-station/blob/master/img/adafruit_dht_library.png?raw=true" style="max-width:100%;" height="600">

<p>After installing the DHT library from Adafruit, type <strong>"Adafruit Unified Sensor"</strong> in the search box. Scroll all the way down to find the library and install it.</p>

<img align="center" src="https://github.com/isbkch/esp32-aws-weather-station/blob/master/img/adafruit_unified_sensor_library.png?raw=true" style="max-width:100%;" height="600">

<p>After installing the libraries, restart your Arduino IDE.</p>

<h1>AWS SETUP</h1>

<p>Now that parts are connected and the libraries are installed, it's time to setup the AWS part.</p>