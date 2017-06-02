#include <DHT.h>

//Select the  digital pin
#define DHTPIN 2
#define DHTTYPE DHT22

// Initialize DHT sensor library.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 test!");

  dht.begin();
}

void loop() {
  delay(2000);
  //Read humidity
  float humidity = dht.readHumidity();
  //Read temperature as Celsius
  float celsiusTemperature = dht.readTemperature();
  //Read temperature as Fahrenheit
  float fahrenheitTemperature = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(celsiusTemperature) || isnan(fahrenheitTemperature)) {
    Serial.println("Failed to read from DHT22 sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" % ");
  Serial.print("   Temperature: ");
  Serial.print(celsiusTemperature);
  Serial.print(" °C ");
  Serial.print(fahrenheitTemperature);
  Serial.println(" °F");
}
