#include <DHT.h> // importa la libreria DHT sensor library
#define DHT11_PIN 12

DHT dht11(DHT11_PIN, DHT11);

void setup() {
  Serial.begin(9600);
  dht11.begin(); // inicia el sensor de humedad y temperatura
}

void loop() {
  // espera 2 segundos entre cada toma de datos
  delay(2000);

  // lee humedad
  float humedad  = dht11.readHumidity();
  // lee temperatura en centigrados
  float tempC = dht11.readTemperature();
  // lee temperatura en fahrenheit
  float tempF = dht11.readTemperature(true);

  // verifica si hay un error
  if (isnan(humedad) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Error al leer el sensor DHT11");
  } else {
    Serial.print("DHT11# Humedad: ");
    Serial.print(humedad);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperatura: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.println("°F");
  }
}