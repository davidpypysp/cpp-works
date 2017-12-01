#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;


class Card {
private: 
    string username;
    string password;
    string id;
    int amount;
public: 
    Card() {};
    string GetUserName();
    string GetPassword();
    string GetId();
    int GetAmount() {
        return amount;
    }
    void AddAmount(int value) {
        this->amount += value;
    }

    bool GetAmount(int value) {
        if(value > this->amount) return false;
        this->amount -= value;
        return true;
    }
    
};

class ATM {
private:
    Card *card;
    bool pin_correct;

public:
    ATM() {
        card = nullptr;
        pin_correct = false;
    };
    bool InsertCard(Card *card) {
        if(this->card) return false;
        this->card = card;
        return true;
    }
    bool EnterPin(string password) {
        if(!this->card) {
            Eject();
            return false;
        }
        if(password == card->GetPassword()) {
            pin_correct = true;
            return true;
        }
        return false;
    }
    bool Deposit(int value) {
        if(!this->card) return false;
        card->AddAmount(value);
        return true;
    }
    bool Withdraw(int value) {
        return card->GetAmount(value);
    }

    bool Eject() {
        if(!card) return false;
        card = nullptr;
        pin_correct = false;
        return true;
    }
};


int main() {
    ATM atm;
    Card *card = new Card("name", "1234", "4321", 5000);
    atm.InsertCard(card);
    atm.EnterPin("4321");

    [3, 2, 5, 2, 4, 6]
    [5, 5, 6, 4, 6, 6,]

}