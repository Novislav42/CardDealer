bool digitalRead(const int n) {
	return false;
}

#include "UserInput.h"

UserInput::UserInput(const int* buttonA, const int* buttonB, const int* buttonC) {
	this->buttonA = buttonA;
	this->buttonB = buttonB;
	this->buttonC = buttonC;
}

char UserInput::awaitButton() {
	// If desired, debouncing and input delays may be implemented here
	while (true) {
		if (digitalRead(*buttonA)) {
			return 'A';
		}
		if (digitalRead(*buttonB)) {
			return 'B';
		}
		if (digitalRead(*buttonC)) {
			return 'C';
		}
	}
}