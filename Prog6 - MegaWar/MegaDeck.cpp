#include "MegaDeck.h"

#include <ctime>
#include <random>

void MegaDeck::shuffle()
{
	srand(unsigned(time(0)));
	random_shuffle(getPile().begin(), getPile().end());
}

MegaDeck::MegaDeck()
{
	initDeck(1);
}

void MegaDeck::initDeck(int n)
{
	for (int i = 0; i < n; i++)
		for (int s = 0; s < AMOUNT_OF_SUITS; s++)
			for (int r = 0; r < AMOUNT_OF_CARDS / AMOUNT_OF_SUITS; r++)
				addCard(Card(ranks[r], suits[s]));
	shuffle();
}
