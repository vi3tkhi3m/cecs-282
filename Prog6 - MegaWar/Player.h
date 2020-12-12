#ifndef PLAYER_H
#define PLAYER_H
#include "CardPile.h"


class Player : public CardPile {
private:
	int id;
	double fierceness = 0.0;
	int battles = 0;
	int wins = 0;

public:
	Player(int id);
	int getId();
	double getFierceness();
	int getAmountOfBattles();
	int getAmountOfWins();
	void addBattle();
	void addWin();
};

#endif