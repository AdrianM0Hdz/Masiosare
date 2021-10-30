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
		Motor *leftMotor, *rightMotor;

		// ultra sonic sensors
		Ultrasonic *frontUltrasonic, *leftUltrasonic, *rightUltrasonic;

		// Gyroscope
		Gyro *gyro;
	
	public:
		Chasis(int forwardLeft, int backwardLeft, 
			   int forwardRight, int backwardRight,
			   int frontTriggerPin, int frontEchoPin, 
			   int leftTriggerPin, int leftEchoPin, 
			   int rightTriggerPin, int frontEchoPin)
		{
			// motors
			this->leftMotor = new Motor(forwardLeft, backwardLeft);
			this->rightMotor = new Motor(forwardRight, backwardRight);

			// ultrasonics
			this->frontUltrasonic = new Motor(frontTriggerPin, frontEchoPin);
			this->leftUltrasonic = new Motor(leftTriggerPin, leftEchoPin);
			this->rightUltrasonic = new Motor(rightTriggerPin, rightEchoPin);
		
			// gyroscope
			this->gyro = new Gyro();
		}
		
		void setup()
		{
			// motors
			this->leftMotor.setup();
			this->rightMotor.setup();
			
			// ultrsonics 
			this->frontUltrasonics.setup();
			this->leftUltrsonic.setup();
			this->rightUltrasonic.setup();
		
			// gyro
			this->gyro.setup();
		}


		void turnLeft() 
		{
			this->leftMotor.retreat();
			this->rightMotor.advance();
			// set the angle of the gyro to 0
			this->gyro.resetOrientation();
			double yaw = this->gyro.getYaw();
			const long timeStep = 0.001;

			while (yaw < 90.0) {
				unsigned long timer = millis();
				this->gyro.updateAngles(timeStep, timer); 
				yaw = this->gyro.getYaw();
			}
		
			this->gyro.resetOrientation();
		}

		void turnRight()
		{
			this->leftMotor.advance();
			this->rightMotor.retreat();
			// set angle of gyro to 0
			this->gyro.resetOrientation();
			
			double yaw = this->gyro.getYaw();
			const long timeStep = 0.001;

			while (yaw > -90.0) {
				unsigned long timer = millis();
				this->gyro.updateAngles(timeStep, timer); 
				yaw = this->gyro.getYaw();
			}
		
			this->gyro.resetOrientation();
		}
		
		void advanceSquare() 
		{
			this->leftMotor.advance();
			this->rightMotor.advance();
			double startingPos = this->frontUltrasonic.readDistance();
			double currentPos = startingPos;
			while ((startingPos - currentPos) < 30) {
				currentPos = this->frontUltrasonic.readDistance();
			}
		}
		
		void retreatSqure() 
		{
			this->leftMotor.retreat();
			this->rightMotor.retreat();
			double startingPos = this->frontUltrasonic.readDistance();
			double currentPos = startingPos;
			while ((currentPos - startingPos) < 30) {
				currentPos = this->frontUltrasonic.readDistance();
			}
			
		}
		
		void stop()
		{
			this->leftMotor.halt();
			this->rightMotor.halt();
		}
};