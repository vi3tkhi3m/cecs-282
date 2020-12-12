// Khiem Pham 
// CECS 282-01
// Program 6 - MegaWar
// Due date: 12/7/2020
// 
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include "MegaWar.h"

int main()
{
    MegaWar game;
	
	while (game.isRunning())
		game.run();

	return 0;
}
