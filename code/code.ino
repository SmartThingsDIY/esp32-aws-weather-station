#include "secrets.h"
#include <WiFiClientSecure.h>
#include <DHT.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"

#define DHT_PIN 4 // pin connected to data pin of DHT11
#define DHT_TYPE DHT11  // Type of the DHT Sensor, DHT11/DHT22

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC   "thing/esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "thing/esp32/sub"

DHT dht(DHT_PIN, DHT_TYPE);

WiFiClientSecure net = WiFiClientSecure();
MQTTClient client = MQTTClient(256);

void connectAWS()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Configure WiFiClientSecure to use the AWS IoT device credentials
  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker on the AWS endpoint we defined earlier
  client.begin(AWS_IOT_ENDPOINT, 8883, net);

  // Create a message handler
  client.onMessage(messageHandler);

  Serial.println("Connecting to AWS IOT");

  while (!client.connect(THINGNAME)) {
    Serial.print(".");
    delay(100);
  }

  if (!client.connected()) {
    Serial.println("AWS IoT Timeout!");
    return;
  }

  // Subscribe to a topic
  client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

  Serial.println("AWS IoT Connected!");
}

void publishMessage()
{
  StaticJsonDocument<200> doc;
  dht.begin();

  float temp      = dht.readTemperature();  // return temperature in °C
  float humidity  = dht.readHumidity(); // return humidity in %
  float heatIndex = dht.computeHeatIndex(temp, humidity, false); // Compute heat index in Celsius (isFahreheit = false)

  // check whether reading was successful or not
  if (temp == NAN || humidity == NAN) { // NAN means no available data
    Serial.println("Reading failed.");
  } else {
    doc["time"]       = String(millis());
    doc["temp"]       = String(temp) + " °C";
    doc["humidity"]   = String(humidity ) + " %";
    doc["heat_index"] = String(heatIndex ) + " %";

    char jsonBuffer[512];
    serializeJson(doc, jsonBuffer); // print to client

    Serial.print("Publishing:- ");
    Serial.println(jsonBuffer);

    client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer); // publish on MQTT topic
  }
}

void messageHandler(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
}

void setup() {
  Serial.begin(9600);
  connectAWS();
}

void loop() {
  publishMessage();
  client.loop();
  delay(15000);
}
