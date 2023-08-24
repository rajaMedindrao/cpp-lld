#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../models/Board.h"
#include "../models/Player.h"
#include "../actions/MoveDown.h"
#include "../actions/MoveUp.h"
#include "../actions/MoveLeft.h"
#include "../actions/MoveRight.h"
#include "../constants/GameStatus.h"

using namespace std;

class Controller{
private:
    Board* board;
    Player* player;
    GameStatus GAME_STATUS;

    bool moveAction(string key){
        int moves=0;
        switch(key[0]){
            case '8':
                moves=MoveUp::executeMove(board);
                break;
            case '2':
                moves=MoveDown::executeMove(board);
                break;
            case '4':
                moves=MoveLeft::executeMove(board);
                break;
            case '6':
                moves=MoveRight::executeMove(board);
                break;
        }
        return moves>0;
    }

public:
    Controller(){
        board=new Board();
        GAME_STATUS=GameStatus::PLAYING;
    }
    Controller(int size,int value){
        board=new Board(size,value);
        GAME_STATUS=GameStatus::PLAYING;
    }

    void performAction(string key){
        if(GAME_STATUS==GameStatus::ENDED){cout<<"Please play a new game"<<endl;return;}
        
        bool compressed=false;
        if(moveAction(key)){compressed=true;};
        if((!board->isBoardFull())&&(!compressed)){cout<<"No change in old board \nPlease Select another move"<<endl;return;}
        
        if(!board->putNewValue()){cout<<"Game Over"<<endl;GAME_STATUS=GameStatus::ENDED;}
        printBoard();
    }

    void printBoard(){
        board->printBoard();
    }

    void printInstructions(){
        cout<<"------------------------"<<endl;
        cout<<"Please press a button"<<endl;
        cout<<"Press 2 to move numbers down"<<endl;
        cout<<"Press 8 to move numbers up"<<endl;
        cout<<"Press 4 to move numbers left"<<endl;    
        cout<<"Press 6 to move numbers right"<<endl;    
    }
};

#endif