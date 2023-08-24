#ifndef PAWN_H
#define PAWN_H

#include "./../Board.h"
#include "./../Position.h"
#include "./PieceAbsClass.h"

#include <string>
using namespace std;

class Pawn: public PieceAbsClass{
private:

public:
    static bool validateMove(Board* board, Position* oldpos, Position* newpos){
        if(!checkCommonValidation(board,oldpos,newpos)){return false;}
        char color=(board->getPiece(oldpos))[0];
        int dir=-1;
        if(color=='B'){dir=1;}
        int oldx=oldpos->getx(),newx=newpos->getx();
        if(oldpos->gety()==newpos->gety()){
            if(abs(oldx-newx)>2){return false;}
            if(board->getPiece(newpos)!="--"){return false;}
            if(abs(oldx-newx)==2){
                if(dir==-1){if(oldx!=6){return false;}}else{if(oldx!=1){return false;}}
                if((oldx+2*dir)!=newx){return false;}
                if(board->getPiece(new Position(oldx+dir,oldpos->gety()))!="--"){return false;}
            }else{
                if(oldx+dir!=newx){return false;}
            }
        }else{
            if(oldx+dir!=newx){return false;}
            int oldy=oldpos->gety(),newy=newpos->gety();
            if(abs(oldy-newy)!=1){return false;}
            if(board->getPiece(newpos)=="--"){return false;}
        }
        return true;
    }
};

#endif