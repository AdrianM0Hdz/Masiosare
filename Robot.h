/* Complete class that has all functinalities and routines
**
*/

#pragma once

#include "components/Chasis.h"
#include "components/BinaryScreenCounter.h"
#include "components/ColorDetector.h"
#include "components/Gate.h"

class Robot
{
	private:
		Chasis* chasis;
		BinaryScreenCounter* screenCounter;
		ColorDetector* colorDetector;
		Gate* gate;
	public:
		Robot(int forwardLeft, int backwardLeft, 
			  int forwardRight, int backwardRight,
			  int frontTriggerPin, int frontEchoPin, 
			  int leftTriggerPin, int leftEchoPin, 
			  int rightTriggerPin, int frontEchoPin)
		{
			this->chasis = new Chasis(int forwardLeft, int backwardLeft, 
			   						  int forwardRight, int backwardRight,
			   						  int frontTriggerPin, int frontEchoPin, 
			   						  int leftTriggerPin, int leftEchoPin, 
			   						  int rightTriggerPin, int frontEchoPin);
				
			this->ColorDetector = new ColorDetector();
		}
		
		void setup()
		{
			this->chasis.setup();
		}

		void solveStageOne() 
		{
			
		}
		void solveStageTwo()
		{

		}

		void solveStageThree()
		{

		}
};