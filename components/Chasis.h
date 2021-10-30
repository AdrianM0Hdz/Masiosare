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

		char cardinalOrientation;
	
	public:

		Chasis(int forwardLeft, int backwardLeft, 
			   int forwardRight, int backwardRight,
			   int frontTriggerPin, int frontEchoPin, 
			   int leftTriggerPin, int leftEchoPin, 
			   int rightTriggerPin, int frontEchoPin
			   char cardinalOrientation)
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

			this->cardianlOrientation = cardinalOrientation;
		}
		
		void setup()
		{
			// motors
			this->leftMotor->setup();
			this->rightMotor.setup();
			
			// ultrsonics 
			this->frontUltrasonics->setup();
			this->leftUltrsonic->setup();
			this->rightUltrasonic->setup();
		
			// gyro
			this->gyro->setup();
		}


		void turnLeft() 
		{
			this->leftMotor->retreat();
			this->rightMotor->advance();
			// set the angle of the gyro to 0
			this->gyro->resetOrientation();
			double yaw = this->gyro->getYaw();
			const long timeStep = 0.001;

			while (yaw < 90.0) {
				unsigned long timer = millis();
				this->gyro->updateAngles(timeStep, timer); 
				yaw = this->gyro->getYaw();
			}
		
			this->gyro->resetOrientation();
			
			// modify cardinal orientation 
			switch (this->cardinalOrientation) {
				case "N":
					this->cardinalOrientation = "W";
					break;
				case "E":
					this->cardinalOrientation = "N";
					break;
				case "S":
					this->cardinalOrientation = "E";
					break;
				case "W":
					this->cardinalOrientation = "S";
					break;
				default:
					break;
			}		
		}

		void turnRight()
		{
			this->leftMotor->advance();
			this->rightMotor->retreat();
			// set angle of gyro to 0
			this->gyro->resetOrientation();
			
			double yaw = this->gyro->getYaw();
			const long timeStep = 0.001;

			while (yaw > -90.0) {
				unsigned long timer = millis();
				this->gyro->updateAngles(timeStep, timer); 
				yaw = this->gyro->getYaw();
			}
		
			this->gyro->resetOrientation();
			
			// change cardinal orientation
			switch (this->cardinalOrientation) {
				case "N":
					this->cardinalOrientation = "E";
					break;
				case "E":
					this->cardinalOrientation = "S";
					break;
				case "S":
					this->cardinalOrientation = "W";
					break;
				case "W":
					this->cardinalOrientation = "N";
					break;
				default:
					break;
			}
		}
		
		void advanceSquare() 
		{
			this->leftMotor->advance();
			this->rightMotor->advance();
			double startingPos = this->frontUltrasonic->readDistance();
			double currentPos = startingPos;
			while ((startingPos - currentPos) < 30) {
				currentPos = this->frontUltrasonic->readDistance();
			}
		}
		
		void retreatSqure() 
		{
			this->leftMotor->retreat();
			this->rightMotor->retreat();
			double startingPos = this->frontUltrasonic->readDistance();
			double currentPos = startingPos;
			while ((currentPos - startingPos) < 30) {
				currentPos = this->frontUltrasonic->readDistance();
			}
			
		}
		
		void stop()
		{
			this->leftMotor->halt();
			this->rightMotor->halt();
		}

		void moveLeft() 
		{
			this->turnLeft();
			this->advanceSquare();
		}

		void moveRight()
		{
			this->turnRight();
			this->advaceSquare();
		}

		bool checkMove(char move) 
		{
			// Checks if a move is doable
			switch (move) {
				case "F":
					if (this->frontUltrasonic->readDistance() < 20.0) {
						return false;
					}
					break;
				case "L":
					if (this->leftUltrasonic->readDistance() < 20.0) {
						return false;
					}
					break;
				case "R":
					if (this->rightUltrasonic->readDistance() < 20.0) {
						return false;
					}
					break;
				default:
					break;
			}
			return true;
		}
		
		void makeMove(char move)
		{
			// "F" = Front
			// "B" = Back
			// "L" = Left
			// "R" = Right 
			// TODO: IMPLEMENT CHECKING IF THE MOVE IS DOABLE
			if (this->checkMove(move)) {
				switch (move) {
					case "F":
						this->advanceSquare();
						break;
					case "B":
						this->retreatSquare();
						break;
					case "L":
						this->moveLeft();
						break;
					case "R":
						this->moveRight();
						break;
					default:
						break;
				}
			}
		}
		
		void makeOppositeMove(char move) 
		{
			// move opposite
			// We will always do the inverse of a move we have done, thus there is no need to check that
			// it is possible
			switch (move) {
				case "F":
					this->retreatSquare();
					break;
				case "B":
					this->advanceSquare();
					break;
				case "L":
					this->moveRight();
				case "R":
					this->moveLeft();
				default:
					break;
			} 
		}
};