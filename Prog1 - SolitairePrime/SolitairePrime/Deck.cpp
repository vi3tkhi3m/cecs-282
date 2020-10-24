#include "Deck.h"
#include <ctime>
#include <iostream>

Deck::Deck()
{
	refreshDeck();
}

void Deck::refreshDeck()
{
	size = AMOUNT_OF_CARDS;
	int currentIndex = 0;

	for (int s = 0; s < AMOUNT_OF_SUITS; s++)
	{
		for (int r = 0; r < AMOUNT_OF_CARDS / AMOUNT_OF_SUITS; r++)
		{
			storage[currentIndex] = Card(ranks[r], suits[s]);
			currentIndex++;
		}
	}
}

Card Deck::deal()
{
	return storage[--size];
}

void Deck::shuffle()
{
	srand(time(0));
	
	for(int i = 0; i < AMOUNT_OF_CARDS; i ++)
	{
		int randomIndexToSwap = rand() % AMOUNT_OF_CARDS;
		Card temp = storage[randomIndexToSwap];
		storage[randomIndexToSwap] = storage[i];
		storage[i] = temp;
	}
}

int Deck::cardsLeft()
{
	return size;
}

void Deck::showDeck()
{
	std::cout << "\033[1;33mNote: Showing deck from bottom to top.\033[0m\n";
	for(int i = 0; i < AMOUNT_OF_CARDS; i++)
	{
		if (i % (AMOUNT_OF_CARDS / AMOUNT_OF_SUITS) == 0)
		{
			std::cout << "\n";
		}
		storage[i].showCard();
		std::cout << " ";
	}
	std::cout << "\n\n";
}
