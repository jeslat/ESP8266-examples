#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//TODO: Add the name and the password of the WiFi
char ssid[] = "";
char password[] = "";

ESP8266WebServer server(80);

//Method to handle the http get request
void handleRequest() {
  Serial.println("Request received");
  String body = "<h1>Hello world!</h1>";
  //Send the response with the body
  server.send(200, "text/html", body);
}

//Method to handle the not found case
void handleNotFound() {
  Serial.println("Not found");
  String body = "<h1>Not found :(</h1>";
  server.send(404, "text/html", body);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Server test");

  //Connect to the WiFi using the name and the password
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");

  //Config the web server
  server.on(("/"), handleRequest);
  server.onNotFound(handleNotFound);
  server.begin();

  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();
}
