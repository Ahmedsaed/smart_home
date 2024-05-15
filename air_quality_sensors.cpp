#include <dht.h> // DHTlib
#include <Arduino.h>

// DHT11 Sensor
dht DHT;

#define DHT_PIN A0

float getTemp()
{
  return DHT.temperature;
}

float getHumidity()
{
  return DHT.humidity;
}

// MQ-2 Sensor
#define MQ2_PIN A1

float getLPG()
{
  return analogRead(MQ2_PIN);
}

// MQ-7 Sensor
#define MQ7_PIN A2

float getCO()
{
  return analogRead(MQ7_PIN);
}

// MQ-135
#define MQ135_PIN A3

float getSmoke()
{
  return analogRead(MQ135_PIN);
}

// Main Functions
void setupSensors()
{
  pinMode(MQ2_PIN, INPUT);
  pinMode(MQ7_PIN, INPUT);
  pinMode(MQ135_PIN, INPUT);
}

void updateSensorReadings()
{
  int chk = DHT.read11(DHT_PIN);
}
