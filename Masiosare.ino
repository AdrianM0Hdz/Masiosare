#include "components/sensors/Gyro.h"
// we define the pins of all the robot

int forwardLeftMotor = 4;
int backwardLeftMotor = 13;

int forwardRightMotor = 12;
int backwardRightMotor = 2;

int leftTriggerPin = 11;
int leftEchoPin = 10;

int frontTriggerPin = 9;
int frontEchoPin = 6;

int rightTriggerPin = 5;
int rightEchoPin = 3; 

/*
Chasis chasis = Chasis(forwardLeftMotor, backwardLeftMotor,
					   forwardRightMotor, backwardRightMotor, 
					   frontTriggerPin, frontEchoPin, 
					   leftTriggerPin, leftEchoPin, 
					   rightTriggerPin, rightEchoPin, 
					   "W");
*/

Gyro gyro = Gyro();

void setup()
{
	Serial.begin(9600);
	Serial.println("Beggining");
	gyro.setup();
	Serial.println("Ended Calibration");
}

void loop()
{
	double timeStep = 0.0155;
	gyro.updateAngles(timeStep);
	float yaw = gyro.getYaw();
	Serial.println(yaw);
}