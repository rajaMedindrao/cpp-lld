#ifndef TICTACTOECONTROLLER_H
#define TICTACTOECONTROLLER_H

#include "../models/Board.h"
#include "../models/Player.h"
#include "../models/Position.h"
#include "../constants/ValueConstants.h"
#include "../constants/GameStatus.h"

using namespace std;

class TicTacToeController{
private:
    Board* board;
    Player* player1;
    Player* player2;
    int cnt=0;
    GameStatus GAMESTATUS;
public:
    TicTacToeController(string player1Name, string player2Name){
        this->board=new Board();
        this->player1=new Player(player1Name);
        this->player2 =new Player(player2Name);
        GAMESTATUS=GameStatus::PLAYING;
    }

    void printBoard(){
        this->board->printBoard();

    }

    string getGameStatus(){
        if(GAMESTATUS==GameStatus::PLAYER1WON){
            return player1->getName() + " Won";
        }
        if(GAMESTATUS==GameStatus::PLAYER2WON){
            return player2->getName() + " Won";
        }
        if(GAMESTATUS==GameStatus::DRAW){
            return "GAME DRAW";
        }
        return "Playing";
    }

    void updateGameStatus(){
        if(board->lineSameValues()){
            if(cnt%2==1){
                GAMESTATUS=GameStatus::PLAYER1WON;
            }else{
                GAMESTATUS=GameStatus::PLAYER2WON;
            }
        }
        if(board->isBoardFull()){GAMESTATUS=GameStatus::DRAW;}
    }

    bool updateCell(int x,int y){
        Position* p=new Position(x,y);
        if(GAMESTATUS!=GameStatus::PLAYING){return false;}

        if(!board->isCellEmpty(p)){return false;}
        
        string player;
        ValueConstants valueConstant;
        if(cnt%2==1){player=player2->getName();valueConstant=ValueConstants::O;}
        else{player=player1->getName();valueConstant=ValueConstants::X;}
        if(!board->updateCell(player,valueConstant,p)){return false;}
        cnt++;
        updateGameStatus();
        return true;
    }

    string currentPlayerName(){
        if(cnt%2){return this->player2->getName();}
        return this->player1->getName();
    }
};

#endif