#pragma once
#define SOUND_SPEED  0.0343

class Ultrasonic 
{
	private:
		int triggerPin;
		int echoPin;

	public:
		Ultrasonic(int triggerPin, int echoPin) 
		{
			this->triggerPin = triggerPin;
			this->echoPin = echoPin;
		}
	
		void setup()
		{
			pinMode(this->triggerPin, OUTPUT);
			pinMode(this->echoPin, INPUT);
		}
	
		double readDistance() 
		{
			digitalWrite(this->triggerPin, LOW);
			delayMicroseconds(2);
			digitalWrite(this->triggerPin, HIGH);
			delayMicroseconds(10);
			digitalWrite(this->triggerPin, LOW);

			double pulseDuration = pulseIn(this->echoPin, HIGH);
			double distance = pulseDuration * SOUND_SPEED / 2; 
			return distance;
		}
};