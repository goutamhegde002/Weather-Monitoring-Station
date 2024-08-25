#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace these with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Initialize DHT sensor
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Initialize BMP180 sensor
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified();

// Initialize Wi-Fi and web server
ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Couldn't find BMP180 sensor");
    while (1);
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to Wi-Fi");

  // Start web server
  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float temperature = event.temperature;
  
  dht.humidity().getEvent(&event);
  float humidity = event.relative_humidity;

  sensors_event_t bmp_event;
  bmp.getEvent(&bmp_event);
  float pressure = bmp_event.pressure;

  String html = "<html><body>";
  html += "<h1>Weather Monitoring Station</h1>";
  html += "<p>Temperature: " + String(temperature) + " &deg;C</p>";
  html += "<p>Humidity: " + String(humidity) + " %</p>";
  html += "<p>Pressure: " + String(pressure) + " hPa</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}
