/********************************************************************
 File name: ass2.cpp

 Purpose: The source code file ass2.cpp provides an implementation of
 the Constructors, Destructor and functions, belonging to the class CardSet, as listed in the
 ass2.h header file. The class provides a template for instantiating objects of the type CardSet.
 It provides instance variables to store the state of the object (number of cards and the Cards
 themselves) in addition to functionality meant to add cards, deal from the card set, shuffle
 the set, merge shuffle it with another set, print the set, deal into multiple hands and
 the like.


 Date: 25 October 2018

 Author: Priya Aswani

 ID Number: 5925502

 Email: pa470@uowmail.edu.au

 ********************************************************************/

#include <iostream>
#include <cstdlib>
#include "CardSet.h"
using namespace std;

//default constructor initialising the instance variables to default values
CardSet::CardSet() :
		Card(NULL), nCards(0) {
}

//constructor accepting parameter to appropriately set the number of cards and the set of cards
//itself for the CardSet object
CardSet::CardSet(int nCards) {
	if (nCards > 0) {
		this->nCards = nCards;
	} else {
		cerr << "Invalid number of cards! Program terminating." << endl;
		exit(1);
	}

	Card = new int[nCards];
	for (int i = 0, j = 0; i < nCards; i++, j++) {
		Card[i] = j;
		if (i == 51) {
			j = -1;
		}
	}

}

//destructor meant to destroy the CardSet object, additionally performing clean up of
//dynamic memory holding the Cards of the CardSet
CardSet::~CardSet() {
	delete[] Card;
}

//function that returns the number of cards for the specific CardSet object
int CardSet::Size() const {
	return nCards;
}

//function that returns a boolean value indicating if the CardSet is empty or otherwise
bool CardSet::IsEmpty() const {
	return (nCards == 0);
}

//function to Shuffle the cards of the CardSet instance
void CardSet::Shuffle() {
	int j;
	for (int i = 0; i < nCards; i++) {
		j = rand() % nCards;
		if (j != i) {
			int temp = Card[i];
			Card[i] = Card[j];
			Card[j] = temp;
		}
	}

}

//function to deal from the Cards of the CardSet object, that returns the first value in the
//CardSet, modifying the stack of cards to hold the remnant cards of the CardSet
int CardSet::Deal() {

	if (nCards == 0) {
		cerr << "Card set empty! Cannot Deal. Program terminating." << endl;
		exit(1);
	}

	int cardToDeal = Card[0];
	int* newCard = new int[nCards - 1];

	for (int i = 0; i < nCards - 1; i++) {
		newCard[i] = Card[i + 1];
	}

	delete[] Card;
	Card = newCard;
	nCards--;

	return cardToDeal;
}

//function meant to deal two hands in the CardSet arguments passed. The specified number
//of cards are placed from the current set into the two hands alternately
void CardSet::Deal(int numberOfCardsToDeal, CardSet& hand1, CardSet& hand2) {

	if (nCards < (numberOfCardsToDeal * 2)) {
		cerr
				<< "Current card set does not have enough cards to deal into two hands."
						" Program terminating!" << endl;
		exit(1);
	}

	int* tempHand1 = new int[hand1.nCards + numberOfCardsToDeal];
	int* tempHand2 = new int[hand2.nCards + numberOfCardsToDeal];

	for (int i = 0; i < hand1.nCards; i++) {
		tempHand1[i] = hand1.Card[i];
	}

	for (int i = 0; i < hand2.nCards; i++) {
		tempHand2[i] = hand2.Card[i];
	}

	int fillerIndexForTempHand1 = hand1.nCards;
	int fillerIndexForTempHand2 = hand2.nCards;

	for (int i = 0; i < numberOfCardsToDeal * 2; i++) {

		if (i % 2 == 0) {
			tempHand1[fillerIndexForTempHand1] = Deal();
			fillerIndexForTempHand1++;
		} else {
			tempHand2[fillerIndexForTempHand2] = Deal();
			fillerIndexForTempHand2++;
		}

	}

	delete[] hand1.Card;
	hand1.Card = tempHand1;
	hand1.nCards += numberOfCardsToDeal;

	delete[] hand2.Card;
	hand2.Card = tempHand2;
	hand2.nCards += numberOfCardsToDeal;

}

//function meant to deal four hands in the CardSet arguments passed. The specified number
//of cards are placed from the current set into the four hands alternately
void CardSet::Deal(int numberOfCardsToDeal, CardSet& hand1, CardSet& hand2,
		CardSet& hand3, CardSet& hand4) {

	if (nCards < (numberOfCardsToDeal * 4)) {
		cerr
				<< "Current card set does not have enough cards to deal into four hands."
						" Program terminating!" << endl;
		exit(1);
	}

	int* tempHand1 = new int[hand1.nCards + numberOfCardsToDeal];
	int* tempHand2 = new int[hand2.nCards + numberOfCardsToDeal];
	int* tempHand3 = new int[hand3.nCards + numberOfCardsToDeal];
	int* tempHand4 = new int[hand4.nCards + numberOfCardsToDeal];

	for (int i = 0; i < hand1.nCards; i++) {
		tempHand1[i] = hand1.Card[i];
	}

	for (int i = 0; i < hand2.nCards; i++) {
		tempHand2[i] = hand2.Card[i];
	}
	for (int i = 0; i < hand3.nCards; i++) {
		tempHand3[i] = hand3.Card[i];
	}
	for (int i = 0; i < hand4.nCards; i++) {
		tempHand4[i] = hand4.Card[i];
	}

	int fillerIndexForTempHand1 = hand1.nCards;
	int fillerIndexForTempHand2 = hand2.nCards;
	int fillerIndexForTempHand3 = hand3.nCards;
	int fillerIndexForTempHand4 = hand4.nCards;

	for (int i = 0; i < numberOfCardsToDeal * 4; i++) {

		if (i % 4 == 0) {
			tempHand1[fillerIndexForTempHand1] = Deal();
			fillerIndexForTempHand1++;
		} else if (i % 4 == 1) {
			tempHand2[fillerIndexForTempHand2] = Deal();
			fillerIndexForTempHand2++;
		} else if (i % 4 == 2) {
			tempHand3[fillerIndexForTempHand3] = Deal();
			fillerIndexForTempHand3++;
		} else {
			tempHand4[fillerIndexForTempHand4] = Deal();
			fillerIndexForTempHand4++;
		}
	}

	delete[] hand1.Card;
	hand1.Card = tempHand1;
	hand1.nCards += numberOfCardsToDeal;
	delete[] hand2.Card;
	hand2.Card = tempHand2;
	hand2.nCards += numberOfCardsToDeal;
	delete[] hand3.Card;
	hand3.Card = tempHand3;
	hand3.nCards += numberOfCardsToDeal;
	delete[] hand4.Card;
	hand4.Card = tempHand4;
	hand4.nCards += numberOfCardsToDeal;

}

//function to add a card to the current set. The int value passed is taken as the identifier
//of the card to be added to the end of the current set
void CardSet::AddCard(int cardValue) {

	int* tempCard = new int[nCards + 1];
	for (int i = 0; i < nCards; i++) {
		tempCard[i] = Card[i];
	}
	if (cardValue >= 0 && cardValue < 52) {
		tempCard[nCards] = cardValue;
	} else {
		cerr
				<< "Invalid card value. Card cannot be added to the Card set! Program terminating."
				<< endl;
		exit(1);
	}

	delete[] Card;
	Card = tempCard;
	nCards++;

}

//function takes the current set and merges it with the cards belonging to the argument CardSet
//alternately placing the cards of the latter set with those of the former, to the extent
//it is possible. After the function call terminates, the argument CardSet would be empty
void CardSet::MergeShuffle(CardSet& otherCardSet) {

	int totalNumberOfCards = otherCardSet.nCards + this->nCards;
	int* tempCard = new int[totalNumberOfCards];
	for (int i = 0; i < totalNumberOfCards; i++) {
		if (i % 2 == 0) {
			if (!this->IsEmpty()) {
				tempCard[i] = this->Deal();
			} else {
				tempCard[i] = otherCardSet.Deal();
			}
		} else {
			if (!otherCardSet.IsEmpty()) {
				tempCard[i] = otherCardSet.Deal();
			} else {
				tempCard[i] = this->Deal();
			}
		}
	}

	delete[] Card;
	Card = tempCard;
	nCards = totalNumberOfCards;

}

//function that prints the cards belonging to the CardSet, five cards to a line
void CardSet::Print() const {
	for (int i = 0; i < nCards; i++) {
		if (i % 5 == 0 && i != 0) {
			cout << endl;
		}
		PrintCard(Card[i]);
		cout << "\t" << flush;
	}

	cout << endl << endl;
}

//private function to print a card in the manner appropriate
void CardSet::PrintCard(int c) const {
	int Rank = c % 13;
	int Suit = c / 13;
	const char NameSuit[5] = "SCDH";
	const char NameRank[14] = "23456789XJQKA";
	cout << NameRank[Rank] << NameSuit[Suit];
}

