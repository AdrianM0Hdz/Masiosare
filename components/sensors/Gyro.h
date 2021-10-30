/* we will be using a gyroscope class for the sake of consistency despite using 
** an external library
*/

#pragma once
#include <Wire.h>
#include "ExternalGyroLib/FMPU6050.h"

class Gyro 
{
	private:
		float yaw = 0.0;
		float pitch = 0.0;
		float roll = 0.0;
		unsigned long timer = 0;
		const double timeStep = 0.001; // seconds, one milisecond
		MPU6050 mpu; // inner mpu
	public:
		Gyro() 
		{

		}
		void setup()
		{
			/* We perform initial claibrations
			**
			*/
			while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  			{
  			  Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
  			  delay(500);
  			}

			this->mpu.calibrateGyro();
			this->mpu.setThreshold(3);
		}
		void resetOrientation()
		{
			/* Sets all angles to 0
			**
			*/
			this->yaw = 0.0;
			this->pitch = 0.0;
			this->roll = 0.0;
		}
		void updateAngles(double timeStep)
		{	
			// timer its current time
			// time step is in seconds
			// updates the angles of the gyroscope given a time step
			Vector accs = mpu.readNormalizeGyro();
		    this->pitch += timeStep * accs.XAxis;
		    this->roll += timeStep * accs.YAxis;
		    this->yaw += timeStep * accs.ZAxis;

		    // wait for time step to finish so that it can be updated again

		    delay(timeStep*1000);
		}	
		float getYaw() 
		{
			return this->yaw;
		}
		float getPitch()
		{
			return this->pitch;
		}
		float getRoll()
		{
			return this->roll;
		}
};