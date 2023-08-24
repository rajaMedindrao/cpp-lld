#ifndef MOVEUP_H
#define MOVEUP_H

#include "BoardMoves.h"
using namespace std;

class MoveUp: public BoardMoves{
    
public:

    static int executeMove(Board* board){
        int moves=0;
        vector<vector<Block* > >  boardValue =board->getBoardValue();
        int size=boardValue.size();
        for(int j=0;j<size;j++){
            vector<int> temp;
            for(int i=0;i<size;i++){
                temp.push_back(boardValue[i][j]->getVal());
            }
            vector<int> ans=compressVector(temp);
            for(int i=0;i<size;i++){
                boardValue[i][j]->setVal(ans[i]);
            }
            if(!elementsEqual(temp,ans)){moves++;}
        }
        return moves;
    }

};

#endif