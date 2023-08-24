#ifndef BOARD_HANDLER_H
#define BOARD_HANDLER_H

#include "../models/Board.h"
#include "../models/BoardList.h"
#include "../models/Card.h"
#include "../models/User.h"

#include <iostream>
using namespace std;

class BoardHandler{
private:
    Board*  board;
public:
    BoardHandler(string name,string createdByUid){
        board=new Board(name,createdByUid);
    }

    void makeBoardPrivate(){
        board->makeBoardPrivate();
    }

    void addList(string boardListName){
        BoardList* boardList= new BoardList(boardListName);
        board->addList(boardList);
    }

    void removeListFromBoard(string boardListUid){
        board->removeList(boardListUid);
    }

    void addCard(string listUid,string title,string description){
        Card* card= Card::CardBuilder().setTitle(title)->setDescription(description)->build();
        BoardList* boardListToAddCard = board->getListByListUid(listUid);
        boardListToAddCard->addCard(card);
    }

    void deleteCard(string listUid,string cardUid){
        BoardList* boardListToDeleteCard = board->getListByListUid(listUid);
        boardListToDeleteCard->deleteCard(cardUid);
    }

    void printBoard(){
        board->printBoard();
    }

    void addAssigneeToCard(string listUid,string cardUid,string userId){
        BoardList* boardList = board->getListByListUid(listUid);
        Card* card= boardList->getCardByCardUid(cardUid);
        card->addUserId(userId);
    }

    void printList(string listUid){
        BoardList* boardList = board->getListByListUid(listUid);
        boardList->printBoardList();
    }

    void printCard(string listUid,string cardUid){
        BoardList* boardList = board->getListByListUid(listUid);
        Card* card= boardList->getCardByCardUid(cardUid);
        card->printCard();
    }
};

#endif