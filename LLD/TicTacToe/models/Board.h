#ifndef BOARD_H
#define BOARD_H

#include "../models/Player.h"
#include "../models/Position.h"
#include "../models/Cell.h"
#include "../constants/ValueConstants.h"

#include <iostream>
#include <vector>
using namespace std;

class Board{
private:
    vector<vector<Cell*> > boardValue;
    int size;
public:
    Board(){
        for(int i=0;i<3;i++){
            vector<Cell *> temp;
            for(int j=0;j<3;j++){
                temp.push_back(new Cell());
            }
            this->boardValue.push_back(temp);
        }
        this->size=3;
    }

    bool isCellEmpty(Position* p){
        if(getCellContent(p)!=' '){
            return false;
        }
        return true;
    }

    bool updateCell(string player,ValueConstants valueConstant,Position* p){
        if(!isCellEmpty(p)){return false;}
        boardValue[p->getXCordinate()][p->getYCordinate()]->fillCell(player,valueConstant);
        return true;
    }

    char getCellContent(Position* p){
        return boardValue[p->getXCordinate()][p->getYCordinate()]->getValue();
    }

    void printBoard(){
        cout<<endl;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(boardValue[i][j]->getValue()==' '){cout<<"-  ";}
                else{cout<<boardValue[i][j]->getValue()<<"  ";}
            }
            cout<<endl;
            cout<<endl;
        }
    }

    bool isBoardFull(){
        bool ans=true;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(isCellEmpty(new Position(i,j))){ans=false;}
            }
        }
        return ans;
    }

    bool lineSameValues(){
        bool same=false;
        for(int i=0;i<3;i++){
            bool tempans=true;
            for(int j=1;j<3;j++){
                if(isCellEmpty(new Position(i,j))){tempans=false;}
                if(boardValue[i][j]->getValue()!=boardValue[i][j-1]->getValue()){
                    tempans=false;
                }
            }
            if(tempans){same=tempans;}
        }

        for(int j=0;j<3;j++){
            bool tempans=true;
            for(int i=1;i<3;i++){
                if(isCellEmpty(new Position(i,j))){tempans=false;}
                if(boardValue[i][j]->getValue()!=boardValue[i-1][j]->getValue()){
                    tempans=false;
                }
            }
            cout<<endl;
            if(tempans){same=tempans;}
        }
        if(!isCellEmpty(new Position(1,1))){
            if((boardValue[0][0]->getValue()==boardValue[1][1]->getValue())
            &&
            (boardValue[0][0]->getValue()==boardValue[2][2]->getValue())){
                same=true;
            }
            if((boardValue[0][2]->getValue()==boardValue[1][1]->getValue())
            &&
            (boardValue[0][2]->getValue()==boardValue[2][0]->getValue())){
                same=true;
            }
        }

        return same;
    }
};

#endif