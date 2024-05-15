#include <Arduino.h>
#include "IRSensor.h"

#define DOOR_IR_PIN A0
#define GARAGE_IR_PIN A1

bool checkDoor()
{
	int r = analogRead(DOOR_IR_PIN);

	if (r > 000) // calibrate
		return true;
	else
		return false;
}

bool checkGarage()
{
	int r = analogRead(GARAGE_IR_PIN);

	if (r > 000) // calibrate
		return true;
	else
		return false;
}
