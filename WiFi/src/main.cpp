#include <ESP8266WiFi.h>

//TODO: Add the name and the password of the WiFi
char ssid[] = "";
char password[] = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Wifi test!");

  //Connect to the WiFi using the name and the password
  WiFi.begin(ssid, password);
  //Wait until the connection is ready
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  //Print the local IP of the board
  Serial.println(WiFi.localIP());
}

void loop() {
}
