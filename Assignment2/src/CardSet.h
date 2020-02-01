/********************************************************************
 File name: ass2.h

 Purpose: The header file ass2.h provides an overview of the design of the class CardSet
 containing prototypes for constructors, a destructor and sub-routines meant to enable creation,
 manipulation and destruction of a CardSet. Additionally, the Class CardSet contains private
 data members to store the the state of an object of the CardSet type (number of cards in the
 set, as well as the card values themselves). Implementation provided in the ass2.cpp source file


 Date: 6 October 2018

 Author: Priya Aswani

 ID Number: 5925502

 Email: pa470@uowmail.edu.au

 ********************************************************************/

#ifndef CARDSET_H
#define CARDSET_H

class CardSet {
public:
	CardSet();
	CardSet(int);
	~CardSet();
	int Size() const;
	bool IsEmpty() const;
	void Shuffle();
	int Deal();
	void Deal(int, CardSet&, CardSet&);
	void Deal(int, CardSet&, CardSet&, CardSet&, CardSet&);
	void AddCard(int);
	void MergeShuffle(CardSet&);
	void Print() const;

private:

	int* Card;
	int nCards;
	void PrintCard(int c) const;
};

#endif
