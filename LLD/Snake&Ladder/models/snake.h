#ifndef SNAKE_H
#define SNAKE_H

#include <stdlib.h>
#include <time.h>

class snake{
private:
    int start, end;
public:
    snake(){
        int start=1,end=1;
        srand(time(NULL));
        while(start==1||end==1||start<=end){
            start=rand()%98+2;
            end=rand()%98+2;
        }
    }
    snake(int start_val,int end_val){
        start=start_val,end=end_val;
    }
    int getstart(){return start;}
    void setstart(int start_val){start=start_val;}
    int getend(){return end;}
    void setend(int end_val){end=end_val;}
};

#endif