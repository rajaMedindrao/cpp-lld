#ifndef BOARD_H
#define BOARD_H

#include "BoardList.h"
#include "User.h"
#include "../uuidGenerator/UuidGenerator.h"

#include <iostream>
#include <vector>
using namespace std;

class Board{
private:
    string uid;
    string name;
    bool isPrivate;
    string createdByUid;
    vector<string> membersUid;
    vector<BoardList*> boardLists;
public:
    Board(string name,string createdByUid){
        this->uid=UuidGenerator::uuidGenerator("BOARD");
        this->name=name;
        this->createdByUid=createdByUid;
        this->isPrivate=false;
        addMember(createdByUid);
    }
    void makeBoardPrivate(){
        this->isPrivate=true;
    }
    void addMember(string userUid){
        membersUid.push_back(userUid);
    }

    void addList(BoardList* boardList){
        boardLists.push_back(boardList);
    }

    void removeList(string boardListUid){
        int deleteme=-1;
        for(int i=0; i<boardLists.size();i++){
            if(boardLists[i]->getUid()==boardListUid){
                deleteme=i;
            }
        }
        if(deleteme<0){return;}
        boardLists.erase(boardLists.begin()+deleteme);
    }

    BoardList* getListByListUid(string boardListUid){
        for(auto boardList: boardLists){
            if(boardList->getUid()==boardListUid){
                return boardList;
            }
        }
        return nullptr;
    }

    void printBoard(){
        cout<<"-------------BOARD BEGIN-------------"<<endl;
        cout<<"Board Uid: "<<uid<<endl;
        cout<<"Board Name: "<<name<<endl;
        cout<<"Created By User id: "<<createdByUid<<endl;
        cout<<endl;
        cout<<"Printing all the Lists"<<endl;
        for(auto boardList: boardLists){
            boardList->printBoardList();
        }
        cout<<endl;
        cout<<"Printing all the Members in the board: ";
        for(auto memberUid: membersUid){
            cout<<memberUid<<" ";
        }
        cout<<endl;
        cout<<"-------------BOARD BEGIN-------------"<<endl;
    }
};

#endif