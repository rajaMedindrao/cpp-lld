#ifndef USERMETADATA_H
#define USERMETADATA_H

#include <vector>
#include <string>
using namespace std;

class usermetadata{
private:
    string name;
    string uuid;
    string email;
    vector<string> groups_present;
public:
    usermetadata(string name, string uuid, string email){
        this->name=name;
        this->uuid=uuid;
        this->email=email;    
    }
    string getname(){return this->name;}
    string getuuid(){return this->uuid;}
    string getemail(){return this->email;}


    bool ispartofgroup(string group_id){
        for(string tempgroupid: groups_present){
            if(tempgroupid==group_id){
                return true;
            }
        }
        return false;
    }

    bool addgroup(string group_id){
        if(ispartofgroup(group_id)){return false;}
        groups_present.push_back(group_id);
        return true;
    }

    vector<string> getgroup_ids(){
        return groups_present;
    }


};

#endif