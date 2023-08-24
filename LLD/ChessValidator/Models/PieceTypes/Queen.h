#ifndef Queen_H
#define Queen_H

#include "./../Board.h"
#include "./../Position.h"
#include "./PieceAbsClass.h"
#include "./Rook.h"
#include "./Bishop.h"

#include <string>
using namespace std;

class Queen: public Bishop, virtual Rook{
private:

public:
    static bool validateMove(Board* board, Position* oldpos, Position* newpos){
        if(!checkCommonValidation(board,oldpos,newpos)){return false;}
        if(!((inMiddleOfRookMove(board,oldpos,newpos))
        ||(inMiddleOfBishopMove(board,oldpos,newpos)))){return false;}
        return true;
    }
};

#endif