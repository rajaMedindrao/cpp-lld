#ifndef BOARD_H
#define BOARD_H

#include "./Position.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board{
private:
    vector<vector<string> > board;
    vector<vector<int> > v;

public:
    Board(){
        v.assign(3,vector<int>(3,0));
        string piece;
        for(int i=0;i<8;i++){
            
            vector<string> temp;
            
            if(i<2){piece='B';}
            else if(i>5){piece="W";}
            string oldpiece=piece;
            if(i==0||i==7){
                for(int j=0;j<8;j++){
                    // piece=oldpiece;
                    if(j==0||j==7){piece+="R";}
                    else if(j==1||j==6){piece+="N";}
                    else if(j==2||j==5){piece+="B";}
                    else if(j==3){piece+="Q";}
                    else{piece+="K";}
                    temp.push_back(piece);
                }
            }else if(i==1||i==6){
                piece+="P";
                for(int j=0;j<8;j++){
                    temp.push_back(piece);
                }
            }else{
                temp.assign(8,"--");
            }
            board.push_back(temp);
        }
    }

    void printAbc(){
        cout<<"   ";
        for(int i=0;i<8;i++){cout<<(char)('a'+i)<<"  ";}
        cout<<endl;
    }

    void printBoard(){
        printAbc();
        for(int i=0;i<8;i++){
            cout<<8-i<<"  ";
            for(int j=0;j<8;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<" "<<8-i;
            cout<<endl;
        }
        printAbc();
    }

    void updatePiece(Position* oldpos, Position* newpos){
        string temp=board[oldpos->getx()][oldpos->gety()];
        board[newpos->getx()][newpos->gety()]=temp;
        board[oldpos->getx()][oldpos->gety()]="--";
    }

    string getPiece(Position* pos){
        return board[pos->getx()][pos->gety()];
    }
};

#endif