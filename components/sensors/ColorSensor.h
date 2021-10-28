#pragma once

class ColorSensor
{
	private:
		int ledPin;
		int outPin;
		int s0Pin;
		int s1Pin;
		int s2Pin;
		int s3Pin;
		//                           Lower Upper
		const int[][] colorRanges = {{0, 100}};
	
	public:
		ColorSensor(int ledPin, int outPin, int s0Pin, 
					int s1Pin, int s2Pinm, int s3Pin) 
		{
			this->ledPin = ledPin;
			this->outPin = outPin;
			this->s0Pin = s0Pin;
			this->s1Pin = s1Pin;
			this->s2Pin = s2Pin;
			this->s3Pin = s3Pin;
		}
		
		void setup()
		{
			pinMode(this->ledPin, OUTPUT);
		}

		int[] readRGB() 
		{

		}

		char readColor() 
		{

		}
};	