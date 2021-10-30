/* Gate to capture the cube and 
** and release it
*/

#pragma once 
#include "actuators/CServo.h"

class Gate
{
	private:
		int pin;
		CServo* servo;
	public:
		Gate(int pin) 
		{
			this->servo = new CServo(pin);
		}

		void setup()
		{
			this->servo->setup();
		}

		void open()
		{
			this->servo->setPosition(0); // tentative position (might change during calibration)
		}

		void close()
		{
			this->servo->setPosition(180); // tentative position (might change during calibration)
		}
};