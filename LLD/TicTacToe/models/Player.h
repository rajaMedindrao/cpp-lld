#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player{
private:
    string name;
public:
    Player(string nameValue){
        this->name=nameValue;
    }
    void setName(string nameValue){this->name=nameValue;}
    string getName(){return this->name;}
};

#endif