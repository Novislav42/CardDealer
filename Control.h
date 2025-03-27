#pragma once

using namespace std;

class Control {
private:
	const int* pivotID;
	const int* shooterID;
	const int* cardPinID;
public:
	Control(const int* pivotID, const int* shooterID, const int* cardPinID);

	void setTurretAngle(double angle);
	void incrementTurretAngle(double angle);
	void setShooterPower(double power);
	void shootCard(double distance);
	void setCardPinAngle(double angle);
};