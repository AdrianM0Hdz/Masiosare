/*
** This program is made to run tests on our Gyroscope Class
*/

#include "../components/sensors/Gyro.h"
#include <Wire.h>

// the robot in general will have a standarized refersh rate so that we can perform
// operations such as numeric integration 

const double delta_time = 0.0000625; 

void setup()
{
	// Setup the registers 
	Wire.beginTransmission(0x68);
	Wire.write(0x0B);
	Wire.write(0x00);
	Wire.endTrassmission();

	//setup

	Serial.begin(9600);
}

void loop()
{

}