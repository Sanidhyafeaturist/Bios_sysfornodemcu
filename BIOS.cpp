#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <EEPROM.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

ESP8266WebServer server(80);

// Function to initialize hardware
void initializeHardware() {
  Serial.begin(115200);
  EEPROM.begin(512);
}

// Function to connect to Wi-Fi
void connectWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(" Connected!");
  } else {
    Serial.println(" Failed to connect.");
  }
}

// Function to get system information and sensor data as HTML
String getHTML(float sensorValue) {
  String html = "<html><body><h1>NodeMCU Monitoring Tool</h1>";
  html += "<p>Sensor Value: " + String(sensorValue) + "</p>";
  html += "<p>Free Memory: " + String(ESP.getFreeHeap()) + " bytes</p>";
  html += "<p>CPU Frequency: " + String(ESP.getCpuFreqMHz()) + " MHz</p>";
  html += "<form action=\"/update\" method=\"POST\">";
  html += "SSID: <input type=\"text\" name=\"ssid\"><br>";
  html += "Password: <input type=\"password\" name=\"password\"><br>";
  html += "<input type=\"submit\" value=\"Update\">";
  html += "</form></body></html>";
  return html;
}

// Handle root URL
void handleRoot() {
  // Replace with actual sensor reading logic
  float sensorValue = analogRead(A0); // Example: reading from A0 pin
  server.send(200, "text/html", getHTML(sensorValue));
}

// Setup function
void setup() {
  initializeHardware();
  connectWiFi();
  
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

// Loop function
void loop() {
  server.handleClient();
}
