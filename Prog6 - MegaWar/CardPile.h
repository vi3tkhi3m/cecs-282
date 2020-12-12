#ifndef CARDPILE_H
#define CARDPILE_H
#include "Card.h"
#include "vector"

using namespace std;

class CardPile
{
private:
	vector<Card> pile;

public:
    void addCard(const Card c);
    Card removeCard();
    int getPileSize();
    void clearPile();
    vector<Card>& getPile();
};

#endif