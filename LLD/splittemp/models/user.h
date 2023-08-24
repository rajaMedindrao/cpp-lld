#ifndef USER_H
#define USER_H

#include "usermetadata.h"

#include <unordered_map>
using namespace std;

class user{
private:
    unordered_map<string,usermetadata*> users;
public:
    user(){}

    usermetadata* getuser(string uuid){
        if(users.find(uuid)!=users.end()){
            return users[uuid];
        }
        return nullptr;
    }

    bool setuser(string uuid, usermetadata* userdata){
        if(users.find(uuid)!=users.end()){
            return false;
        }
        users[uuid]=userdata;
        return true;
    }
};

#endif