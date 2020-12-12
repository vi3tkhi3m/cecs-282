#ifndef MEGAWAR_H
#define MEGAWAR_H

#include "MegaDeck.h"
#include "Player.h"

class MegaWar {
private:
	MegaDeck megaDeck;
	CardPile lostAndFound;
	// playerCard is used the store the player and his/hers drawn card
	vector<pair<Player*, Card>> playerCard;
	CardPile warPile;
	vector<Player*> playersThatGoToWar;
	vector<Player> players;
	bool running = true;
	int amountOfDecks = 1;
	int amountOfPlayers = 2;
	void initGame();
	void printStats();
	void initDecks();
	void initPlayers();
	void initCardsToPlayers();
	bool onePlayerLeft();
	void playThreeCards();
	void playOneCard(bool war);
	void addWinAndCardsToWinner();
	void clearPlayerAndPiles();
	void handleWarWinner();
	void addCardsToLostAndFound();
	void handleLoserAndPlayersWithHighestCard();
	void battle(bool war);

public:
	MegaWar();
	void run();
	void stop();
	bool isRunning() const;
};

#endif