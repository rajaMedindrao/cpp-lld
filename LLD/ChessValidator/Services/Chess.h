#ifndef CHESS_H
#define CHESS_H

#include "./../Models/Board.h"
#include "./../Models/Position.h"
#include "./../Models/PieceTypes/Rook.h"
#include "./../Models/PieceTypes/Knight.h"
#include "./../Models/PieceTypes/King.h"
#include "./../Models/PieceTypes/Queen.h"
#include "./../Models/PieceTypes/Bishop.h"
#include "./../Models/PieceTypes/Pawn.h"


#include <string>
using namespace std;

class Chess{
private:
    Board* b;
    // Even->White, Odd->Black
    int cnt;
public:
    Chess(){
        b=new Board();
        cnt=0;
    }

    void printBoard(){
        b->printBoard();
    }

    string whoseTurn(){
        if(cnt%2==0){return "White";}
        return "Black";
    }
    
    Position* makePos(string pos){
        int xpos=pos[1]-'1';
        xpos=7-xpos;
        int ypos=pos[0]-'a';
        return new Position(xpos,ypos);
    }

    bool makeMove(string oldposString, string newposString){
        Position* oldpos=makePos(oldposString);
        Position* newpos=makePos(newposString);
        if(!validMove(oldpos,newpos)){return false;}
        b->updatePiece(oldpos,newpos);
        cnt++;
        return true;
    }

    int totalMoves(){return cnt;}

private: 
    bool validMove(Position* oldpos, Position* newpos){
        string piece=b->getPiece(oldpos);
        if(piece=="--"){return false;}
        if(cnt%2==0){
            if(piece[0]=='B'){return false;}
        }else{
            if(piece[0]=='W'){return false;}
        }
        
        bool isvalid=true;
        switch(piece[1]){
            case 'B':
                cout<<"Its a Bishop"<<endl;
                isvalid=Bishop::validateMove(b,oldpos,newpos);
                break;
            case 'K':
                isvalid=King::validateMove(b,oldpos,newpos);
                break;
            case 'N':
                isvalid=Knight::validateMove(b,oldpos,newpos);
                break;
            case 'P':
                cout<<"Its a Pawn"<<endl;
                isvalid=Pawn::validateMove(b,oldpos,newpos);
                break;
            case 'Q':
                isvalid=Queen::validateMove(b,oldpos,newpos);
                break;
            case 'R':
                isvalid=Rook::validateMove(b,oldpos,newpos);
                break;
        }

        return isvalid;
    }

    

};

#endif