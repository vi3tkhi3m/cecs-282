#ifndef GAME_H
#define GAME_H
#include "Deck.h"

class Game {
private:
	bool running = true;
	Deck deck;
	bool isPrime(int num);
	void showInvalidInputErrorMessage();
	void showWinnerDialogIfLastPileIsPrime(int cardValueCounter, int piles);

public:
	void handleUserInput();
	void showMenu();
	void newDeck();
	void displayDeck();
	void shuffleDeck();
	void playGame();
	void resetGame();
	void exitGame();
	void run();
	bool isRunning();
};

#endif