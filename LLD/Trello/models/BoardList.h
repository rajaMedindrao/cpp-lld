#ifndef BOARD_LIST_H
#define BOARD_LIST_H

#include "Card.h"
#include "../uuidGenerator/UuidGenerator.h"

#include <iostream>
using namespace std;

class BoardList{
private:
    string boardListUid;
    string name;
    vector<Card*> cards;
public:
    BoardList(string name){
        this->name=name;
        this->boardListUid=UuidGenerator::uuidGenerator("LIST");
    }
    string getUid(){
        return boardListUid;
    }
    void addCard(Card* card){
        cards.push_back(card);
    }
    void setName(string name){
        this->name=name;
    }
    Card* getCardByCardUid(string cardUid){
        for(auto card: cards){
            if(card->getCardId()==cardUid){
                return card;
            }
        }
        return nullptr;
    }

    void deleteCard(string cardUid){
        int deleteme=-1;
        for(int i=0;i<cards.size();i++){
            if(cards[i]->getCardId()==cardUid){
                deleteme=i;
            }
        }
        if(deleteme<0){return;}
        cards.erase(cards.begin()+deleteme);
    }
    void printBoardList(){
        cout<<"-------------LIST BEGIN-------------"<<endl;
        cout<<"List Name: "<<name<<endl;
        cout<<"Board List Uid: "<<boardListUid<<endl;
        cout<<"printing Cards Present:"<<endl;
        cout<<endl;
        for(auto card: cards){
            card->printCard();
        }
        cout<<endl;
        cout<<"-------------LIST END-------------"<<endl;
    }
};

#endif