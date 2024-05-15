#ifndef __AQSENSORS__
#define __AQSENSORS__

float getTemp();
float getHumidity();
float getLPG();
float getCO();
float getSmoke();
void setupSensors();
void updateSensorReadings();

#endif
