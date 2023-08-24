#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

class Piece{
private:
    string name; 

public:
    Piece(string newName){
        this->name=newName;
    }
    string getName(){
        return name;
    }

};

#endif