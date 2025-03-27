// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int dirPin = 2;
const int stepPin = 3;

// Define motor interface type
#define motorInterfaceType 1

// Creates an instance
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

void setup() {
	// set the maximum speed, acceleration factor,
	// initial speed and the target position
	myStepper.setMaxSpeed(1000);
	myStepper.setAcceleration(500);
	myStepper.setSpeed(1000);
	myStepper.moveTo(0);
}

void runToPosition(float position) {
	myStepper.runToNewPosition(position);
	
}

void runToIncrementedPosition(float increment) {
	myStepper.runToNewPosition(increment + myStepper.currentPosition());
	
}

void loop() {
	
	while(myStepper.currentPosition() < 150) {
		runToIncrementedPosition(30);
		delay(500);
	}
	
	runToPosition(0);
	delay(3000);
		
}

