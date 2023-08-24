#include "./Services/Chess.h"

#include <iostream>
using namespace std;

int main(){
    cout<<"         Welcome To Chess Game"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    Chess* chessClient=new Chess();
    while(1){
        chessClient->printBoard();
        cout<<"\n \nMove "<<chessClient->whoseTurn()<<" Piece"<<endl;
        cout<<"Enter your move here: ";

        string oldpos,newpos;
        cin>>oldpos;
        cin>>newpos;
        if(!chessClient->makeMove(oldpos,newpos)){cout<<"Invalid Move \nTry again"<<endl;}
        
        cout<<"Total Moves Completed: "<<chessClient->totalMoves()<<endl;
        cout<<"\n "<<endl;
    }
}