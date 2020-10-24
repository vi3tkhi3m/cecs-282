#include "Card.h"
#ifndef DECK_H
#define DECK_H

class Deck {
private:
	Card storage[52];
	int size;
	char ranks[13] = { 49,50,51,52,53,54,55,56,57,84,74,81,75 };
	char suits[4] = { 'S','C','D','H' };
	const int AMOUNT_OF_CARDS = 52;
	const int AMOUNT_OF_SUITS = 4;

public:
	Deck();
	void refreshDeck();
	Card deal();
	void shuffle();
	int cardsLeft();
	void showDeck();
};

#endif