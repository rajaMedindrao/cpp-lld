#ifndef BOARD_H
#define BOARD_H

#include "Block.h"

#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

class Board{
private:
    vector<vector<Block* > > boardValue;
    int value;

    void assignValuesToBlock(int size){
        for(int i=0;i<size;i++){
            vector<Block*> temp;
            for(int j=0;j<size;j++){
                temp.push_back(new Block(0));
            }
            this->boardValue.push_back(temp);
        }
    }
public:
    Board(){
        assignValuesToBlock(4);
        this->value=2;
        putNewValue();
    }

    Board(int siz,int newValue){
        assignValuesToBlock(siz);
        this->value=newValue;
        putNewValue();
    }

    void printBoard(){
        int siz=boardValue.size();
        for(int i=0;i<siz;i++){
            for(int j=0;j<siz;j++){
                if(boardValue[i][j]->getVal()==0){
                    cout<<"-  ";
                }else{cout<<boardValue[i][j]->getVal()<<"  ";}
            }
            cout<<endl;
        }
    }
    
    vector<vector<Block* > > getBoardValue(){
        return boardValue;
    }

    bool isBoardFull(){
        bool ans=true;
        int siz=boardValue.size();
        for(int i=0;i<siz;i++){
            for(int j=0;j<siz;j++){
                if(boardValue[i][j]->getVal()==0){
                    ans=false;
                }
            }
        }
        return ans;
    }

    bool putNewValue(){
        vector<pair<int,int> > temp;
        int siz=boardValue.size();
        for(int i=0;i<siz;i++){
            for(int j=0;j<siz;j++){
                if(boardValue[i][j]->getVal()==0){
                    pair<int,int> p(i,j);
                    temp.push_back(p);
                }
            }
        }
        int limit=temp.size();
        if(limit==0){return false;}

        int random=rand()%limit;
        
        int newValue=-1;
        if(random%2){newValue=value;}else{newValue=2*value;}

        pair<int,int> newpos=temp[random];
        boardValue[newpos.first][newpos.second]->setVal(newValue);
        cout<<"newValue "<<newValue<<" is placed in position "<<newpos.first<<" "<<newpos.second<<endl;
        return true;
    }
};

#endif
