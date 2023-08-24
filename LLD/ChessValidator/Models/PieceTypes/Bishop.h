#ifndef KNGIHT_H
#define KNGIHT_H

#include "./../Board.h"
#include "./../Position.h"
#include "./PieceAbsClass.h"

#include "math.h"
#include <string>
using namespace std;

class Bishop: public PieceAbsClass{
private:

public:

    static bool inMiddleOfBishopMove(Board* board, Position* oldpos, Position* newpos){
        if(oldpos->getx()==newpos->getx()||oldpos->gety()==newpos->gety()){return false;}

        int oldx=oldpos->getx(),oldy=oldpos->gety();
        int newx=newpos->getx(),newy=newpos->gety();

        if(abs(oldx-newx)!=abs(oldy-newy)){return false;}

        int xdir=oldx-newx,ydir=oldy-newy;
        if(xdir<0){xdir=-1;}else{xdir=1;}
        if(ydir<0){ydir=-1;}else{ydir=1;}

        //Checking pieces in between
        for(int x=oldx+xdir,y=oldy+ydir;x<newx&&y<newy;x+=xdir,y+=ydir){
            if(board->getPiece(new Position(x,oldpos->gety()))!="--"){return false;}
        }
        return true;
    }
    static bool validateMove(Board* board, Position* oldpos, Position* newpos){

        if(!checkCommonValidation(board,oldpos,newpos)){return false;}
        if(!inMiddleOfBishopMove(board,oldpos,newpos)){return false;}

        return true;
    }
};

#endif