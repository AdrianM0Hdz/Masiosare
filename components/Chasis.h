/* Chasis class to provide a level of abstraction and 
** give an interface with funcionality such as turnLeft or turnRight
*/

#pragma once

#include "actuators/Motor.h"
#include "sensors/Ultrasonic.h"
#include "sensors/Gyro.h"

class Chasis 
{
	private:
		// motors of the chasis
		Motor leftMotor, rightMotor;

		// ultrasonic sensors
		Ultrasonic frontUltrasonic, leftUltrasonic, rightUltrasonic;

		// Gyroscope
		Gyro gyro;
	
	public:
		Chasis()
		{

		}
		void turnLeft() 
		{

		}

		void turnRight()
		{

		}
		
		void advanceSquare() 
		{

		}
		void retreatSqure() 
		{

		}
};