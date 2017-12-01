#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct Suit {

};


class Card {
public: 
    Card(int card, Suit suit) : card(card), suit(suit) {
    }

    int Value() {
        return card;
    }

private: 
    int card;
    Suit suit;


};


class BlackJackCard : Card {
    BlackJackCard(int card, Suit suit) : Card(card, suit) {

    };

    bool IsAce() {
        return this->Card::Value();
    }
};
