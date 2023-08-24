#ifndef MOVELEFT_H
#define MOVELEFT_H

#include "BoardMoves.h"
using namespace std;

class MoveLeft: public BoardMoves{
    
public:

    static int executeMove(Board* board){
        int moves=0;
        vector<vector<Block* > >  boardValue =board->getBoardValue();
        int size=boardValue.size();
        for(int i=0;i<size;i++){
            vector<int> temp;
            for(int j=0;j<size;j++){
                temp.push_back(boardValue[i][j]->getVal());
            }
            vector<int> ans=compressVector(temp);
            for(int j=0;j<size;j++){
                boardValue[i][j]->setVal(ans[j]);
            }
            if(!elementsEqual(temp,ans)){moves++;}
        }
        return moves;
    }

};

#endif