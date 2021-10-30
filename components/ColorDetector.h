/* Extra level of abstraction to be able to provide interface
** getRightColor and getLefColor 
*/

#pragma once
#include "sensors/ColorSensor.h"

class ColorDetector
{
	private:
		// Left and right color sensors
		ColorSensor *leftColorSensor, *rightColorSensor;
	public:
		ColorDetector() 
		{

		}
		char getLeftColor() 
		{

		}
		char getRightColor()
		{

		}
		char getColor() 
		{
			
		}
};