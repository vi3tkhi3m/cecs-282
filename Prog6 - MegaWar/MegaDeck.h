#ifndef MEGADECK_H
#define MEGADECK_H
#include "CardPile.h"

class MegaDeck : public CardPile {
private:
	Rank ranks[13] = { Rank::ace, Rank::two, Rank::three, Rank::four, Rank::five, Rank::six, Rank::seven, Rank::eight, Rank::nine, Rank::ten, Rank::jack, Rank::queen, Rank::king };
	Suit suits[4] = { Suit::spades, Suit::clubs, Suit::diamonds, Suit::hearts };
	const int AMOUNT_OF_CARDS = 52;
	const int AMOUNT_OF_SUITS = 4;
	void shuffle();

public:
	MegaDeck();
	void initDeck(int n);
};

#endif