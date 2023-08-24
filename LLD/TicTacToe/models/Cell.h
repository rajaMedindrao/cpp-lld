#ifndef CELL_H
#define CELL_H

#include "../constants/ValueConstants.h"

#include <string>
using namespace std;

class Cell{
private:
    string player;
    char value;
public:
    Cell(){
        this->player="";
        this->value=' ';
    }
    Cell(string playerValue, char newValue){
        this->player=playerValue;
        this->value=newValue;
    }

    char getValue(){return this->value;}
    void setValue(ValueConstants valueConstant){
        if(int(valueConstant)==0){this->value='X';}
        else{this->value='O';}
    }

    string getPlayer(){return this->player;}
    void setValue(string playerValue){this->player=playerValue;}

    void fillCell(string playerValue, ValueConstants valueConstant){
        this->player=playerValue;
        this->setValue(valueConstant);
    }
};

#endif