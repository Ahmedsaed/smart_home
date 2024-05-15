#include <string.h>
#include <Arduino.h>
#include "lcd.h"
#include "air_quality_sensors.h"
#include "servo.h"

#define MODE_PIN 2
#define BUZZER_PIN 3

/*
  air_quality_sensors.ino:
  - updateReadings()
  - getTemp()
  - getHumidity()
*/

int screenIndex = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(MODE_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  setupLCD();
  setupSensors();
  setupServos();
}

void loop()
{
  updateSensorReadings();
  SmokeWarning(getSmoke());
  displayScreen(screenIndex);
  debug();

  if (digitalRead(MODE_PIN) == LOW)
  {
    screenIndex = (screenIndex + 1) % 5;
    Serial.println("Screen: " + String(screenIndex));
    // delay(200);
    while (digitalRead(MODE_PIN) == LOW)
    {
    }
  }
  else
  {
    delay(1000);
  }
}

void debug()
{
  Serial.println("-----------------------------------------");
  Serial.println("Temp: " + String(getTemp()));
  Serial.println("Humidity: " + String(getHumidity()));
  Serial.println("LPG: " + String(getLPG()));
  Serial.println("CO: " + String(getCO()));
  Serial.println("Smoke: " + String(getSmoke()));
}

float calprecentage(int v, int min = 0, int max = 1024)
{
  if (min >= max || v < min || v > max)
  {
    // Invalid input, return 0 or some error indicator
    return 0.0f; // Or you can return -1 or any other suitable error indicator
  }

  float range = max - min;
  float percentage = ((v - min) / range) * 100.0f;
  return percentage;
}

void displayScreen(int index)
{
  switch (index)
  {
  case 0:
    displayInfo("Temp: " + String(getTemp()) + "C");
    break;
  case 1:
    displayInfo("Humidity: " + String(getHumidity()) + "%");
    break;
  case 2:
    displayInfo("LPG: " + String(calprecentage(getLPG())) + "%");
    break;
  case 3:
    displayInfo("CO: " + String(calprecentage(getCO())) + "%");
    break;
  case 4:
    displayInfo("Smoke: " + String(calprecentage(getSmoke())) + "%");
    break;
  }
}

void SmokeWarning(float smokeLevel)
{
  if (smokeLevel > 200)
  {
    displayInfo("Warning! Run run.");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(2500);
    digitalWrite(BUZZER_PIN, LOW);
  }
}
