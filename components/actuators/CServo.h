/* There already exists a standard servo libary in arduino, we are just 
** adapting it to the form of out components for the sake of consistency
** CServo stands for Custom Servo
*/

#pragma once 

#include <Servo.h>

class CServo 
{
	private:
		int pwnPin;
		Servo innerServo;
	public:
		CServo(int pwnPin) 
		{
			this->pwnPin;
		}
	
		void setup()
		{
			this->innerServo.attach(this->pwnPin);
		}

		void setPosition(int theta)
		{
			this->innerServo.write(theta);
		}
};