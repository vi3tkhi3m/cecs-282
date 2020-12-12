#ifndef CARD_H
#define CARD_H

enum class Rank { ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };
enum class Suit { spades, clubs, diamonds, hearts };

class Card {
private:
	Rank rank;
	Suit suit;

public:
	Card();
	Card(Rank r, Suit s);
	void setCard(Rank r, Suit s);
	int getValue() const;
};

#endif