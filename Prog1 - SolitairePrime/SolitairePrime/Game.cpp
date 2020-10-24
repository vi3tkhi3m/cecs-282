#include "Game.h"
#include <iostream>

/**
 * Check whether the given number is a prime number.
 *
 * @param num Container whose values are summed.
 * @return prime Returns true if num is a prime, else returns false.
 */
bool Game::isPrime(int num)
{
	// 0 and 1 are not prime numbers!
	if(num == 0 || num == 1)
	{
		return false;
	}
	
	bool prime = true;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

void Game::showInvalidInputErrorMessage()
{
	std::cout << "\033[1;31mPlease enter a valid number (1-5):\033[0m\n";
}

void Game::handleUserInput()
{
	int input;
	std::cin >> input;

	while (std::cin.fail() || input > 5 || input < 0) {
		showInvalidInputErrorMessage();
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;
	}
	
	switch (input)
	{
		case 1:
			newDeck();
			break;
		case 2:
			displayDeck();
			break;
		case 3:
			shuffleDeck();
			break;
		case 4:
			playGame();
			break;
		case 5:
			exitGame();
			break;
		default:
			showInvalidInputErrorMessage();
			break;
	}
}

void Game::showMenu()
{
	std::cout << "\033[1;36mWelcome to Solitaire Prime! Please choose one of the following options:\033[0m\n";
	std::cout << "1) New Deck\n";
	std::cout << "2) Display Deck\n";
	std::cout << "3) Shuffle Deck\n";
	std::cout << "4) Play Solitaire Prime\n";
	std::cout << "5) Exit Game\n";
}

void Game::newDeck()
{
	std::cout << "\033[1;32mNew deck has been created!\033[0m\n";
	deck.refreshDeck();
}

void Game::displayDeck()
{
	std::cout << "\033[1;32mDisplaying Deck:\033[0m\n";
	deck.showDeck();
}

void Game::shuffleDeck()
{
	std::cout << "\033[1;32mDeck has been shuffled!\033[0m\n";
	deck.shuffle();
}

void Game::showWinnerDialogIfLastPileIsPrime(int cardValueCounter, int piles)
{
	if (isPrime(cardValueCounter))
	{
		std::cout << "\nWinner in " << piles << " piles!\n\n";
	}
}

void Game::playGame()
{
	system("CLS");
	std::cout << "\033[1;32mPlaying Solitaire Prime!\033[0m\n\n";

	int cardValueCounter = 0;
	int piles = 0;

	while(deck.cardsLeft() > 0)
	{
		// Reset this to 0 every time a prime is hit
		cardValueCounter = 0;
		
		while(!isPrime(cardValueCounter) && deck.cardsLeft() > 0)
		{
			Card card = deck.deal();
			cardValueCounter += card.getValue();
			card.showCard();
			std::cout << ", ";
		}

		if(isPrime(cardValueCounter))
		{
			std::cout << "Prime: " << cardValueCounter << "\n";
			piles++;
		} else
		{
			std::cout << "Loser\n\n";
		}
	}
	
	showWinnerDialogIfLastPileIsPrime(cardValueCounter, piles);
	resetGame();
}

void Game::resetGame()
{
	deck.refreshDeck();
}

void Game::exitGame()
{
	running = false;
}

void Game::run()
{
	showMenu();
	handleUserInput();
}

bool Game::isRunning()
{
	return running;
}
