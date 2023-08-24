#include "services/TicTacToeController.h"

#include <iostream>

using namespace std;

int main(){
    string player1,player2;
    cout<<"Player 1 Name"<<endl;
    cin>>player1;
    cout<<"Player 2 Name"<<endl;
    cin>>player2;
    cout<<"GAME STARTED"<<endl;
    TicTacToeController ticTacToeController(player1,player2);
    while(1){
        ticTacToeController.printBoard();
        int x,y;
        cout<<ticTacToeController.currentPlayerName()<<"'s turn"<<endl;
        cout<<"Enter x cordinate and y cordinate"<<endl;
        cin>>x;
        cin>>y;
        if(!ticTacToeController.updateCell(x,y)){
            cout<<"Invalid Move"<<endl;    
        }
        if(ticTacToeController.getGameStatus()!="Playing"){
            ticTacToeController.printBoard();
            cout<<ticTacToeController.getGameStatus()<<endl;
            
            break;
        }
    }
}