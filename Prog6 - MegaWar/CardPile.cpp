#include "CardPile.h"
#include "Card.h"

void CardPile::addCard(const Card c)
{
    pile.insert(pile.begin(), c);
}

Card CardPile::removeCard()
{
    Card temp = pile.back();
    pile.pop_back();
    return temp;
}

int CardPile::getPileSize()
{
    return pile.size();
}

void CardPile::clearPile()
{
    pile.clear();
}

vector<Card>& CardPile::getPile()
{
    return pile;
}
