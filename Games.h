#include <vector>

class ShootLoc {

}

class Game {
protected:
	// ShootLoc for each dealer location
	vector<ShootLoc> dealerLocs;
	// ShootLoc for each player. The index and size of which will be used to determine player count and the ID of each player
	vector<ShootLoc> playerLocs;
public:
	Game(int buttonA, int buttonB, int buttonC);
	virtual void initialize();
	virtual void run();
	virtual void end();
};
}