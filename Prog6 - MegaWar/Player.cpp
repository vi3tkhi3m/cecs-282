#include "Player.h"

Player::Player(const int id)
{
	this->id = id;
}

int Player::getId()
{
	return id;
}

double Player::getFierceness()
{
	double temp = 0.0;
	
	for (auto& it : getPile()) {
		temp += it.getValue();
	}

	if (getPile().empty())
		return temp;

	return temp / getPileSize();
}

int Player::getAmountOfBattles()
{
	return battles;
}

int Player::getAmountOfWins()
{
	return wins;
}

void Player::addBattle()
{
	battles++;
}

void Player::addWin()
{
	wins++;
}
