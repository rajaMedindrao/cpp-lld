#include "services/BoardHandler.h"
#include "services/UserHandler.h"

#include<iostream>
using namespace std;

int main(){
    cout<<"WELCOME TO TRELLO"<<endl;
    BoardHandler* boardHandler;
    UserHandler* userHandler=new UserHandler();
    int i=10;
    while(i--){
        cout<<"Press 1 to create the board"<<endl;
        cout<<"Press 2 to create a user"<<endl;
        cout<<"Press 3 to add a list to the board"<<endl;
        cout<<"Press 4 to add a card to the list on the board"<<endl;
        cout<<"Press 5 to show the card on the list on the board"<<endl;
        cout<<"Press 6 to delete a card on the list on the board"<<endl;
        cout<<"Press 7 to show the list on the board"<<endl;
        cout<<"Press 8 to delete the list on the board"<<endl;
        cout<<"Press 9 to print the board"<<endl;
        cout<<"Press 10 to print the users"<<endl;
        int x;
        cin>>x;

        if(x==1){
            string name;
            string createdByUid;            
            cout<<"Enter Board Name: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter Created By Uid"<<endl;
            cin>>createdByUid;
            boardHandler=new BoardHandler(name,createdByUid);
        }
        if(x==2){
            string name;
            string emailId;            
            cout<<"Enter User Name"<<endl;
            cin>>name;
            cout<<"Enter Email Id"<<endl;
            cin>>emailId;
            string uid=userHandler->createUser(name,emailId);
            cout<<"New User Uid: "<<uid<<endl;
        }
        if(x==3){
            string name;        
            cout<<"Enter List Name"<<endl;
            getline(cin,name);
            boardHandler->addList(name);
            continue;
        }
        if(x==4){
            string listUid;
            string title;            
            string description;            
            cout<<"Enter List Uid"<<endl;
            cin>>listUid;
            cout<<"Enter Title"<<endl;
            cin>>title;
            cout<<"Enter Description"<<endl;
            cin>>description;
            boardHandler->addCard(listUid,title,description);
        }
        if(x==5){
            string listUid;
            string cardUid;         
            cout<<"Enter List Uid"<<endl;
            cin>>listUid;         
            cout<<"Enter Card Uid"<<endl;
            cin>>cardUid;
            boardHandler->printCard(listUid,cardUid);
        }
        if(x==6){
            string listUid;
            string cardUid;         
            cout<<"Enter List Uid"<<endl;
            cin>>listUid;         
            cout<<"Enter Card Uid"<<endl;
            getline(cin,cardUid);
            boardHandler->deleteCard(listUid,cardUid);
        }
        if(x==7){
            string listUid;      
            cout<<"Enter List Uid"<<endl;
            cin>>listUid; 
            boardHandler->printList(listUid);
        }
        if(x==8){
            string listUid;      
            cout<<"Enter List Uid"<<endl;
            cin>>listUid; 
            boardHandler->removeListFromBoard(listUid);
        }
        if(x==9){
            boardHandler->printBoard();
        }
        if(x==10){
            userHandler->listAllUsers();
        }
    }
}