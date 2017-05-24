#include <ESP8266WiFi.h>

//Add the name and the password of the WiFi access point
char ssid[] = "ESP8266_Wifi";
char password[] = "password";

void setup() {
  Serial.begin(9600);
  Serial.println("Wifi access point test!");

  //Create the access point using the name and the password
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  Serial.println("");
  Serial.println("WiFi created");
}

void loop() {
}
