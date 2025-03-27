#pragma once

class UserInput {
private:
	const int* buttonA;
	const int* buttonB;
	const int* buttonC;
public:
	UserInput(const int* buttonA, const int* buttonB, const int* buttonC);

	char awaitButton();
};