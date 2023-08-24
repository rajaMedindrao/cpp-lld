#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class player{
private:
    string name;
public:
    player(string name_val){
        name=name_val;
    }
    string getname(){return name;}
    void setname(string name_val){name=name_val;}
};

#endif