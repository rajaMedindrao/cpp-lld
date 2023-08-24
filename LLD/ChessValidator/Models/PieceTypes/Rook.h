#ifndef ROOK_H
#define ROOK_H

#include "./../Board.h"
#include "./../Position.h"
#include "./PieceAbsClass.h"

#include "math.h"
#include <string>
using namespace std;

class Rook: public PieceAbsClass{
private:

public:
    static bool inMiddleOfRookMove(Board* board, Position* oldpos, Position* newpos){
        if(oldpos->getx()!=newpos->getx()&&oldpos->gety()!=newpos->gety()){return false;}

        //Checking pieces in between
        int fromPlace=min(oldpos->getx(),newpos->getx()),toPlace=min(oldpos->getx(),newpos->getx());
        for(int x=fromPlace+1;x<toPlace;x++){
            if(board->getPiece(new Position(x,oldpos->gety()))!="--"){return false;}
        }
        fromPlace=min(oldpos->gety(),newpos->gety()),toPlace=min(oldpos->gety(),newpos->gety());
        for(int y=fromPlace+1;y<toPlace;y++){
            if(board->getPiece(new Position(oldpos->getx(),y))!="--"){return false;}
        }
        return true;
    }

    static bool validateMove(Board* board, Position* oldpos, Position* newpos){

        if(!checkCommonValidation(board,oldpos,newpos)){return false;}
        if(!inMiddleOfRookMove(board,oldpos,newpos)){return false;}
        
        return true;
    }

};

#endif