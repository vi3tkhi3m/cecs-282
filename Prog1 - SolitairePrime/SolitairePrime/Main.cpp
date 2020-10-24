// Khiem Pham 
// CECS 282-01
// Program 1 - Solitaire Prime
// Due date: 9/14/2020

// I certify that this program is my own original work. I did not copy any part of this program from            
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include "Game.h"

using namespace std;

int main() {

	Game game;

	while(game.isRunning())
	{ 
		game.run();
	}
	
	return 0;
}