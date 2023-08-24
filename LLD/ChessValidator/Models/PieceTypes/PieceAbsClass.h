#ifndef PieceAbsClass_H
#define PieceAbsClass_H

#include "./../Board.h"
#include "./../Position.h"

#include <string>
using namespace std;

class PieceAbsClass{
private:

public:
    static bool checkCommonValidation(Board* board, Position* oldpos, Position* newpos){
        if(newpos->getx()<0||newpos->getx()>7||newpos->gety()<0||newpos->gety()>7){return false;}

        string piece=board->getPiece(oldpos);
        string removablepiece=board->getPiece(newpos);

        if(piece.length()<1||piece[0]==removablepiece[0]){return false;}
        
        
        return true;
    }

};

#endif