#ifndef GROUPLIST_H
#define GROUPLIST_H

#include "group.h"

#include <string>
#include "unordered_map"
using namespace std;

class grouplist{
private:
    unordered_map<string,group*> groups;
public:
    grouplist(){}

    bool newgroup(string group_id,group* group){
        if(groups.find(group_id)!=groups.end()){
            return false;
        }
        groups[group_id]=group;
        return true;
    }

    group* getgroup(string group_id){
        if(groups.find(group_id)!=groups.end()){
            return groups[group_id];
        }
        return nullptr;
    }
};


#endif