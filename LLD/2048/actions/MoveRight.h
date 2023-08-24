#ifndef MOVERIGHT_H
#define MOVERIGHT_H

#include "BoardMoves.h"
using namespace std;

class MoveRight: public BoardMoves{
    
public:

    static int executeMove(Board* board){
        int moves=0;
        vector<vector<Block* > >  boardValue =board->getBoardValue();
        int size=boardValue.size();
        for(int i=0;i<size;i++){
            vector<int> temp;
            for(int j=size-1;j>=0;j--){
                temp.push_back(boardValue[i][j]->getVal());
            }
            vector<int> ans=compressVector(temp);
            for(int j=size-1;j>=0;j--){
                boardValue[i][j]->setVal(ans[size-1-j]);
            }
            if(!elementsEqual(temp,ans)){moves++;}
        }
        return moves;
    }

};

#endif