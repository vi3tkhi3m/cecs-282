#include <algorithm>
#include <iostream>
#include <map>
#include <iomanip>

#include "MegaWar.h"

using namespace std;

MegaWar::MegaWar()
{
}

bool MegaWar::onePlayerLeft()
{
	int amountOfPlayersStillInTheGame = 0;
	for (auto& it : players)
		if (it.getPileSize() > 0)
			amountOfPlayersStillInTheGame++;

	if (amountOfPlayersStillInTheGame == 1)
		return true;

	return false;
}

void MegaWar::initGame()
{
	cout << "\033[1;36mWelcome to MegaWar!\033[0m\n";
	cout << "Please enter the amount of decks to play with:\n";
	cin >> amountOfDecks;

	while (std::cin.fail() || amountOfDecks < 1) {
		cout << "Please enter a valid number!\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> amountOfDecks;
	}
	
	cout << "Please enter the amount of players to play with:\n";
	cin >> amountOfPlayers;

	while (std::cin.fail() || amountOfPlayers < 2) {
		cout << "Please enter a valid number!\n";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> amountOfPlayers;
	}

	initDecks();
	initPlayers();
	initCardsToPlayers();
}

void MegaWar::run()
{
	initGame();

	int battleCount = 1;

	while (!onePlayerLeft())
	{
		battle(false);
		cout << "Battle " << battleCount << " Stats:\n";
		printStats();
		battleCount++;
	}

	stop();
}

void MegaWar::stop()
{
	running = false;
}

bool MegaWar::isRunning() const
{
	return running;
}

void MegaWar::printStats()
{
	for (auto& it : players)
		cout << "\t" << left << "Player " << it.getId() << ": Fierceness = " << setw(10) << setprecision(3) << it.getFierceness() << "Cards = " << setw(6) << it.getPileSize() << "Battles = " << setw(6) << it.getAmountOfBattles() << "Wins = " << setw(5) << it.getAmountOfWins() << endl;
}

bool cmp(pair<Player*, Card>& a,
	pair<Player*, Card>& b)
{
	return a.second.getValue() > b.second.getValue();
}

void sortPlayerCardFromHighToLow(vector<pair<Player*, Card>>& playerCard)
{
	sort(playerCard.begin(), playerCard.end(), cmp);
}


void MegaWar::playThreeCards()
{
	for (auto& it : playersThatGoToWar)
		for (int i = 0; i < 3; i++)
			warPile.addCard(it->removeCard());
}

void MegaWar::playOneCard(const bool war)
{
	if(!playerCard.empty())
		playerCard.clear();
	
	if(war)
	{
		for (auto& it : playersThatGoToWar)
			playerCard.emplace_back(it, it->removeCard());

		playersThatGoToWar.clear();
	}
	else
	{
		for (auto& it : players) {
			if (it.getPileSize() > 0)
			{
				playerCard.emplace_back(&it, it.removeCard());
				it.addBattle();
			}
		}
	}
}

void MegaWar::addWinAndCardsToWinner()
{
	for (auto& it : playerCard)
		playerCard[0].first->addCard(it.second);

	for (auto& it : warPile.getPile())
		playerCard[0].first->addCard(it);

	playerCard[0].first->addWin();

	clearPlayerAndPiles();
}

void MegaWar::clearPlayerAndPiles()
{
	playersThatGoToWar.clear();
	warPile.clearPile();
	playerCard.clear();
}

void MegaWar::handleWarWinner()
{
	const int WARPILE_SIZE = warPile.getPileSize();
	const int LOST_AND_FOUND_SIZE = lostAndFound.getPileSize();
	for (int i = 0; i < WARPILE_SIZE; i++)
		playersThatGoToWar[0]->addCard(warPile.removeCard());

	if(lostAndFound.getPileSize() > 0)
		for (int i = 0; i < LOST_AND_FOUND_SIZE; i++)
			playersThatGoToWar[0]->addCard(lostAndFound.removeCard());

	playersThatGoToWar[0]->addWin();

	clearPlayerAndPiles();
}

void MegaWar::addCardsToLostAndFound()
{
	for (int i = 0; i < warPile.getPileSize(); i++)
		lostAndFound.addCard(warPile.removeCard());
}

void MegaWar::handleLoserAndPlayersWithHighestCard()
{
	for (auto& it : playerCard) {
		warPile.addCard(it.second);
		// Check if player's card value is the same as the highest card value
		if (playerCard[0].second.getValue() == it.second.getValue())
		{
			// Player goes to the war list if their deck contains 4 or more cards
			// Else add loser cards to the war pile
			if (it.first->getPileSize() >= 4)
				playersThatGoToWar.push_back(it.first);
			else
				for (int i = 0; i < it.first->getPileSize(); i++)
					warPile.addCard(it.first->removeCard());
		}
	}
}

void MegaWar::battle(bool war)
{
	if(war)
		playThreeCards();

	playOneCard(war);

	sortPlayerCardFromHighToLow(playerCard);

	if (playerCard[0].second.getValue() > playerCard[1].second.getValue())
	{
		addWinAndCardsToWinner();
	}
	else
	{
		handleLoserAndPlayersWithHighestCard();

		if (playersThatGoToWar.size() > 1)
			battle(true);

		if (playersThatGoToWar.size() == 1)
			handleWarWinner();

		if (playersThatGoToWar.empty())
			addCardsToLostAndFound();
	}
}

void MegaWar::initDecks()
{
	if (amountOfDecks > 1)
		megaDeck.initDeck(amountOfDecks - 1);
}

void MegaWar::initPlayers()
{
	for (int i = 0; i < amountOfPlayers; i++)
		players.emplace_back(Player(i + 1));
}

void MegaWar::initCardsToPlayers()
{
	const int AMOUNT_OF_CARDS_PER_DECK = 52;
	const int NUMBER_OF_CARDS_PER_PLAYER = floor((amountOfDecks * AMOUNT_OF_CARDS_PER_DECK) / amountOfPlayers);

	for (auto& it : players)
		for(int i = 0; i < NUMBER_OF_CARDS_PER_PLAYER; i++)
			it.addCard(megaDeck.removeCard());
}
