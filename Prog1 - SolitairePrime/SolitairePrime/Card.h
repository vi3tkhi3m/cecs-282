#ifndef CARD_H
#define CARD_H

class Card {
private:
	char rank;
	char suit;
	enum ranks { ace = 49, two, three, four, five, six, seven, eight, nine, ten = 84, jack = 74, queen = 81, king = 75 };
	bool isRankValid(char r);
	bool isSuitValid(char s);

public:
	Card();
	Card(char r, char s);
	void setCard(char r, char s);
	int getValue();
	void showCard();
};

#endif