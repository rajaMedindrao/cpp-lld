#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "snake.h"
#include "ladder.h"
using namespace std;

class board{
private:
    int row, column;
    vector<snake*> snakes;
    vector<ladder*> ladders;
    vector<string> board_val;

public:
    board(){
        row=10;
        column=10;
        board_val.assign(row*column,"");
    }
    board(int row_val,int column_val){
        row=row_val;
        column=column_val;
        board_val.assign(row*column,"");
    }

    int getrow(){return row;}
    void setrow(int row_val){row=row_val;}
    int getcolumn(){return column;}
    void setcolumn(int column_val){column=column_val;}
    
    void inputsnake(snake* snake_val){
        snakes.push_back(snake_val);
        board_val[snake_val->getstart()]="snake";
    }
    void inputladder(ladder* ladder_val){
        ladders.push_back(ladder_val);
        board_val[ladder_val->getstart()]="ladder";
    }

    string getboardval(int num){
        return board_val[num];
    }

    int gotbitebysnake(int num){
        int ret=num;
        for(snake* snake_temp:snakes){
            if(snake_temp->getstart()==num){
                ret=snake_temp->getend();
            }
        }
        return ret;
    }

    int climbedtheladder(int num){
        int ret=num;
        for(ladder* ladder_temp:ladders){
            if(ladder_temp->getstart()==num){
                ret=ladder_temp->getend();
            }
        }
        return ret;
    }
};

#endif
