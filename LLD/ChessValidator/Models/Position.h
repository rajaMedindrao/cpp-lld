#ifndef POSITION_H
#define POSITION_H

#include <string>
using namespace std;

class Position{
private:
    int x,y;
public:
    Position(int newx,int newy){
        this->x=newx;
        this->y=newy;
    }
    int getx(){
        return this->x;
    }
    int gety(){
        return this->y;
    }

};

#endif