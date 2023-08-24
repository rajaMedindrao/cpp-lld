#ifndef POSITION_H
#define POSITION_H

using namespace std;

class Position{
private:
    int xCordinate,yCordinate;
public:
    Position(int xCordinateValue,int yCordinateValue){
        this->xCordinate=xCordinateValue;
        this->yCordinate=yCordinateValue;
    }

    int getXCordinate(){return xCordinate;}
    int getYCordinate(){return yCordinate;}

};

#endif