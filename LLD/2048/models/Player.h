#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player{
private:
    string name;
public:
    Player(string nameVal){
        this->name=nameVal;
    }

    void setName(string nameVal){this->name=nameVal;}

    string setName(){return this->name;}
};

#endif