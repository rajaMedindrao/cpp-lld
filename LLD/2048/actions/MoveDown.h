#ifndef MOVEDOWN_H
#define MOVEDOWN_H

#include "BoardMoves.h"
using namespace std;

class MoveDown: public BoardMoves{
    
public:

    static int executeMove(Board* board){
        int moves=0;
        vector<vector<Block* > >  boardValue =board->getBoardValue();
        int size=boardValue.size();
        for(int j=0;j<size;j++){
            vector<int> temp;
            for(int i=size-1;i>=0;i--){
                temp.push_back(boardValue[i][j]->getVal());
            }
            vector<int> ans=compressVector(temp);
            for(int i=size-1;i>=0;i--){
                boardValue[i][j]->setVal(ans[size-1-i]);
            }
            if(!elementsEqual(temp,ans)){moves++;}
        }
        return moves;
    }

};

#endif