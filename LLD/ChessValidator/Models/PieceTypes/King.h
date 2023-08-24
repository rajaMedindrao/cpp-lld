#ifndef KING_H
#define KING_H

#include "./../Board.h"
#include "./../Position.h"
#include "./PieceAbsClass.h"

#include <string>
using namespace std;

class King: public PieceAbsClass{
private:

public:
    static bool validateMove(Board* board, Position* oldpos, Position* newpos){
        if(!checkCommonValidation(board,oldpos,newpos)){return false;}
        if(abs(oldpos->getx()-newpos->getx())>1){return false;}
        if(abs(oldpos->gety()-newpos->gety())>1){return false;}
        return true;
    }
};

#endif