#include "Games.h"
#include "Arduino.h"

using namespace std;

int buttonA;
int buttonB;
int buttonC;

const double dealerShoot = 0.5;
const double playerShoot = 1;

int awaitButton() {
	while(true) {
		if (digitalRead(buttonA)) {
			return buttonA;
		}
		if (digitalRead(buttonB)) {
			return buttonB;
		}
		if (digitalRead(buttonC)) {
			return buttonC;
		}
	}
}

// Abstract class to provide a template for other game classes
class ShootLoc {
public:
	int angle;
	int power;
	// no constructor needed, using "ShootLoc {num, num}" will initialize these variables all the same
};

class Game {
protected:
	// ShootLoc for each dealer location
	vector<ShootLoc> dealerLocs;
	// ShootLoc for each player. The index and size of which will be used to determine player count and the ID of each player
	vector<ShootLoc> playerLocs;
public:
	Game(int buttonA, int buttonB, int buttonC) {
    
  }

	virtual void initialize() = 0 {}
	virtual void run() = 0 {}
	virtual void end() = 0 {}
};

// LOAD CARDS FACE DOWN
class Blackjack : Game {
private:
public:
	Blackjack() : Game() {}

	void initialize() {
		while (true) {
			switch (awaitButton()) {
			case buttonA:
				/* rotate turret by some small amount */
				break;
			case buttonB:
				// save current angle and constant power to playerLocs using push_back
				playerLocs.push_back({ 0,0 });
				break;
			case buttonC:
				// exit loop if playerLocs is > 0
				if (playerLocs.size() > 0) {
					goto exitInit;
				}
				break;
			}
		}
	exitInit:
		// Dealer Piles- Default 2 piles for hidden and revealed card.
		dealerLocs = {{0, 0}, {0, 0}};
		
		/* Deal a card to each location twice */
		for (int i = 0; i < 2; i++) {
			/* Shoot card at dealer */
			dealerLocs[i];
			
			for (ShootLoc loc : playerLocs) {
				/* Shoot card at each player */
				loc.angle;
				loc.power;
			}
		}
	}

	void run() {
		int player = 0;
		ShootLoc currShootLoc = playerLocs[player];

		/* rotate to player 0 */

		while (true) {
			switch (awaitButton()) {
			case buttonA:
				/* hit, despense card to currShootLoc */
				break;
			case buttonB:
				/* stay, rotate to next player */
				player++;

				if (player < playerLocs.size()) {
					currShootLoc = playerLocs[player];
				}
				// if final player has been dealt to, switch to dealer hitting mode 
				else if (player == playerLocs.size()) {
					/* Go to dealer locs, incrementing to the side each stay  */
					currShootLoc = dealerLocs[1];
				} else if (player > playerLocs.size()) {
					// dealer stayed, exit game
					goto exitRun;
				}
				break;
			}
		}
		exitRun:

	}
};