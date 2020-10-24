#include "Card.h"
#include <iostream>

using namespace std;

/**
 * Checks whether the given char is a valid rank.
 *
 * @param r The rank of the card.
 * @return true if the rank is valid, else returns false.
 */
bool Card::isRankValid(char r)
{
	if (r >= 49 && r < 58 || r == 74 || r == 81 || r == 75 || r == 84)
	{
		return true;
	}
	return false;
}

/**
 * Checks whether the given char is a valid suit.
 *
 * @param s The suit of the card.
 * @return true if the suit is valid, else returns false.
 */
bool Card::isSuitValid(char s)
{
	if (s == 'S' || s == 'D' || s == 'H' || s == 'C')
	{
		return true;
	}
	return false;
}

Card::Card()
{
	rank = ' ';
	suit = ' ';
}

Card::Card(char r, char s)
{
	if (isRankValid(r))
	{
		if (isSuitValid(s))
		{
			rank = r;
			suit = s;
		} else
		{
			rank = ' ';
			suit = ' ';
		}
	}
}

void Card::setCard(char r, char s)
{
	if(isRankValid(r))
	{
		if(isSuitValid(s))
		{
			rank = r;
			suit = s;
		}
	}
}

int Card::getValue()
{
	switch (rank)
	{
		case ace:
			return 1;
		case two:
			return 2;
		case three:
			return 3;
		case four:
			return 4;
		case five:
			return 5;
		case six:
			return 6;
		case seven:
			return 7;
		case eight:
			return 8;
		case nine:
			return 9;
		case ten:
		case jack:
		case queen:
		case king:
			return 10;
		default:
			return 0;
	}
}

void Card::showCard()
{
	string temp;

	switch (rank)
	{
		case ace:
			temp = "A";
			break;
		case ten:
			temp = "10";
			break;
		default:
			temp = rank;
			break;
	}

	temp += suit;

	cout << temp;
}