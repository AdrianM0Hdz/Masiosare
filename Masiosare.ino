#include "components/actuators/Motor.h"

Motor motor = Motor(13, 12);

void setup()
{
	motor.setup();
}

void loop()
{
	motor.advance();
}