#ifndef USER_HANDLER_H
#define USER_HANDLER_H

#include "../models/User.h"

#include <vector>
using namespace std;


class UserHandler{
private:
    vector<User*> users;
public:
     string createUser(string name,string emailId){
        User* newUser=User::UserBuilder().setName(name)->setEmailId(emailId)->build();
        users.push_back(newUser);
        return newUser->getUserId();
    }
    string getUserIdbyName(string name){
        string uid="-1";
        for(auto user: users){
            if(user->getName()==name){
                uid=user->getUserId();
            }
        }
        return uid;
    }
    string getUserIdbyEmailId(string emailId){
        string uid="-1";
        for(auto user: users){
            if(user->getEmailId()==emailId){
                uid=user->getUserId();
            }
        }
        return uid;
    }
    void listAllUsers(){
        cout<<"Printing all the users"<<endl;
        cout<<endl;
        for(auto user: users){
            user->printUser();
        }
        cout<<endl;
    }
};

#endif