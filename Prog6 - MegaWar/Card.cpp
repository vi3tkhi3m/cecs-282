#include "Card.h"

using namespace std;

Card::Card()
{
	rank = Rank::ace;
	suit = Suit::clubs;
}


Card::Card(const Rank r, const Suit s)
{
	setCard(r, s);
}

void Card::setCard(const Rank r, const Suit s)
{
	rank = r;
	suit = s;
}

int Card::getValue() const
{
	switch (rank)
	{
		case Rank::ace:
			return 1;
		case Rank::two:
			return 2;
		case Rank::three:
			return 3;
		case Rank::four:
			return 4;
		case Rank::five:
			return 5;
		case Rank::six:
			return 6;
		case Rank::seven:
			return 7;
		case Rank::eight:
			return 8;
		case Rank::nine:
			return 9;
		case Rank::ten:
			return 10;
		case Rank::jack:
			return 11;
		case Rank::queen:
			return 12;
		case Rank::king:
			return 13;
		default:
			return 0;
	}
}
