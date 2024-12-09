#include <Arduino.h>
#include <ElegantOTA.h>
#include <WebServer.h>
#include <WiFiManager.h>
// #define ssid  "pranacella"
// #define password  "bandung1"
#define OTA_USERNAME "admin"   
#define OTA_PASSWORD "admin123"
WebServer server(80);
WiFiManager wm;
bool res;
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN,OUTPUT);
  // wm.resetSettings();

  res = wm.autoConnect("AutoConnectAP","password");
  if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    }

  Serial.println("");
  Serial.print("connected to: ");
  Serial.println(WiFi.localIP());

  ElegantOTA.begin(&server);
  ElegantOTA.setAuth(OTA_USERNAME, OTA_PASSWORD);
  server.begin();
  Serial.println("HTTP SERVER STARTED");

}

void loop() {
  server.handleClient();
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}
