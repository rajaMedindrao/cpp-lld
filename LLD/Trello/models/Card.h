#ifndef CARD_H
#define CARD_H

#include "../uuidGenerator/UuidGenerator.h"

#include <vector>
#include <iostream>
using namespace std;

class Card{
private:
    string cardId;
    int cardNo;
    string title;
    string description;
    vector<string> assigneToUserIds;

public:
    Card(string title,string description){
        this->title=title;
        this->description=description;
        this->cardId=UuidGenerator::uuidGenerator("CARD");
        // this->cardNo= increase from board
    }

    void addUserId(string userId){
        assigneToUserIds.push_back(userId);
    }

    void setDescription(string descriptionValue){
        description=descriptionValue;
    }

    string getCardId(){return cardId;}

    void printCard(){
        cout<<"-------------CARD START-------------"<<endl;
        cout<<"CardId: "<<cardId<<endl;
        cout<<"title: "<<title<<endl;
        cout<<"description: "<<description<<endl;
        cout<<"Lists of Assigned User Id: ";
        for(auto str: assigneToUserIds){cout<<str<<" ";}
        cout<<endl;
        cout<<"-------------CARD END-------------"<<endl;
    }

    class CardBuilder{
    public:
        string title="";
        string description="";
        CardBuilder(){}
        CardBuilder* setTitle(string newTitle){
            title=newTitle;
            return this;
        }
        CardBuilder* setDescription(string newDescription){
            description=newDescription;
            return this;
        }
        Card* build(){
            return new Card(title,description);
        }
    };

};

#endif