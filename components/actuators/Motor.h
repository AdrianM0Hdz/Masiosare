#pragma once

class Motor
{
	private:
		int forwardPin;
		int backwardPin;
		int speedPin = -1;
	
	public:
		Motor(int forwardPin, int backeadPin, int speedPin=-1)
		{
			this->forwardPin = forwardPin;
			this->backwardPin = backwardPin;
			if (speedPin > -1) {
				this->speedPin = speedPin;
			}
		}
		
		void setup() 
		{
			pinMode(this->forwardPin, OUTPUT);
			pinMode(this->backwardPin, OUTPUT);
		} 

		void halt()
		{
			digitalWrite(this->backwardPin, LOW);
			digitalWrite(this->forwardPin, LOW);
		}

		void advance()
		{
			digitalWrite(this->backwardPin, LOW);
			digitalWrite(this->forwardPin, HIGH);
		}

		void retreat()
		{
			digitalWrite(this->forwardPin, LOW);
			digitalWrite(this->backwardPin, HIGH);
		}

		void setSpeed(int speed)
		{
			if (this->speedPin > -1) {
				analogWrite(this->speedPin, speed);
			}
		}
};