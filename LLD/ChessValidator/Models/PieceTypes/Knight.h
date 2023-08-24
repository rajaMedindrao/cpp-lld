#ifndef BISHOP_H
#define BISHOP_H

#include "./../Board.h"
#include "./../Position.h"
#include "./PieceAbsClass.h"

#include <string>
using namespace std;

class Knight: public PieceAbsClass{
private:

public:
    static bool validateMove(Board* board, Position* oldpos, Position* newpos){
        if(!checkCommonValidation(board,oldpos,newpos)){return false;}

        int xdif=oldpos->getx()-newpos->getx(),ydif=oldpos->gety()-newpos->gety();
        if(!((abs(xdif)==2&&abs(ydif)==1)||(abs(ydif)==2&&abs(xdif)==1))){return false;}
        return true;
    }
};

#endif