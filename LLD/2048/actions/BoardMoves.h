#ifndef BOARDMOVES_H
#define BOARDMOVES_H

#include "../models/Block.h"
#include "../models/Board.h"

#include <deque>
using namespace std;

class BoardMoves{
public:
    static int elementsEqual(vector<int> a,vector<int> b){
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){return false;}
        }
        return true;
    }
    static void printColumnDeq(deque<int> column){
        cout<<" came to print deque"<<endl;
        while(!column.empty()){
            cout<< column.front() <<endl;
            column.pop_front();
        }
        cout<<"finished printing"<<endl;
    }
    static vector<int> compressVector(vector<int> arr){
        deque<int> column;
        vector<int> ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){continue;}
            if(column.size()>0 && column.back()==arr[i]){
                column.pop_back();
                column.push_back(2*arr[i]);
                column.push_back(-1);
            }
            else{
                column.push_back(arr[i]);
            }

        }
        for(int i=0;i<arr.size();i++){
            while((!column.empty())&&column.front()==-1){column.pop_front();}
            if(column.empty()){break;}
            ans[i]=column.front();
            column.pop_front();
        }
        return ans;
    }

    static void executeMove(Board* board){}
};


#endif