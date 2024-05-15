#include <Arduino.h>
#include <Servo.h>

#define DOOR_PIN 9
#define GARAGE_PIN 10
#define WINDOW_PIN 11

Servo door;
Servo garage;
Servo window;

void setupServos()
{
	door.attach(DOOR_PIN);
	garage.attach(GARAGE_PIN);
	window.attach(WINDOW_PIN);
}

void openDoor()
{
	door.write(90);
}

void openGarage()
{
	garage.write(90);
}

void openWindow()
{
	window.write(100);
}

void closeDoor()
{
	door.write(0);
}

void closeGarage()
{
	garage.write(0);
}

void closeWindow()
{
	window.write(0);
}
