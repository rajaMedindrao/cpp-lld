#include "models/snake.h"
#include "models/ladder.h"
#include "models/board.h"
#include "models/player.h"
#include "models/dice.h"

#include <deque>
#include <map>

using namespace std;

int main(){
    int row=10,col=10;
    int no_of_snakes=0,no_of_ladders=0;
    int start=0,end=0;
    int no_of_players=0;
    int no_of_dice=1;
    cout<<"Please input row & col for the snake & ladders board"<<endl;
    cin>>row>>col;
    board b1(row,col);

    
    cout<<"Please input number of snakes for this board"<<endl;
    cin>>no_of_snakes;
    for(int i=0;i<no_of_snakes;i++){
        cout<<"Please give head & tail of the snake "<<i<<". | head > tail"<<endl;
        cin>>start>>end;
        b1.inputsnake(new snake(start,end));
    }


    cout<<"Please input number of ladders for this board"<<endl;
    cin>>no_of_ladders;
    for(int i=0;i<no_of_ladders;i++){
        cout<<"Please give head & tail of the ladder "<<i<<". | head < tail"<<endl;
        cin>>start>>end;
        b1.inputsnake(new snake(start,end));
    }


    cout<<"please input number of dice"<<endl;
    cin>>no_of_dice;


    deque<string> players;
    cout<<"Please enter no of players"<<endl;
    cin>>no_of_players;
    for(int i=0;i<no_of_players;i++){
        cout<<"Please give the player "<<i<<" a name "<<endl;
        string name;
        cin>>name;
        players.push_back(name);
    }

    map<string,int> position;
    int finalpos=row*col;
    while(!players.empty()){
        string name=players.front();
        players.pop_front();
        int new_position=position[name]+get_number(no_of_dice);
        if(new_position>finalpos){
            cout<<name<<" new position is greater than final position"<<endl;
            players.push_back(name);
            continue;
        }
        cout<<name<<" moved from "<<position[name]<<" to "<<new_position<<endl;

        if(new_position==finalpos){
            cout<<name<<" won"<<endl;
            cout<<"************************************"<<endl;
            position[name]=new_position;
            continue;
        }
        if(b1.getboardval(new_position)==""){
            position[name]=new_position;
        }
        while(b1.getboardval(new_position)!=""){
            if(b1.getboardval(new_position)=="snake"){
                cout<<"Got bite by snake"<<endl;
                int new_position_temp=b1.gotbitebysnake(new_position);
                cout<<name<<" snake moved from "<<new_position<<" to "<<new_position_temp<<endl;
                new_position=new_position_temp;
            }
            if(b1.getboardval(new_position)=="ladder"){
                cout<<"Climbed the ladder"<<endl;
                int new_position_temp=b1.climbedtheladder(new_position);
                cout<<name<<" ladder moved from "<<new_position<<" to "<<new_position_temp<<endl;
                new_position=new_position_temp;
            }            
        }
        players.push_back(name);
    }
    return 0;
}