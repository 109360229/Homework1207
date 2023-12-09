/*
#include <iostream>
#include <stdio.h>

struct card {

	const char *face;
	const char *suit;
};

int main(void)
{
	struct card aCard;
	struct card *cardPtr;

	aCard.face = "Ace";
	aCard.suit = "Spades";

	cardPtr = &aCard;
	printf("%s%s%s\n%s%s%s\n%s%s%s\n", aCard.face, " of ", aCard.suit, cardPtr->face, " of ", cardPtr->suit, (*cardPtr).face, " of ", (*cardPtr).suit);
	return 0;

}
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card {

	const char* face;
	const char* suit;
};

typedef struct card Card;
void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal(const Card* const wDeck);

int main(void)
{
	Card deck[52];
	const char* face[] = { "Ace", "Deuce","Three", "Four", "Five", "Six"
	," Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	const char* suit[] = { "Hearts", "Diamonds", "Clubd", "Spades" };
	srand(time(NULL));
	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
	return 0;
}

void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[])
{
	int i;
	for (i = 0; i <= 51; i++) {
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];

	}

}

void shuffle(Card* const wDeck) {

	int i, j;
	Card temp;

	for (i = 0; i <= 51; i++) {

		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}

}

void deal(const Card* const wDeck) {

	int i;
	for (i = 0; i <= 51; i++) {

		printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? "  " : "\n");
	}
}
