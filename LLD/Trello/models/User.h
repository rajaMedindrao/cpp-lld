#ifndef USER_H
#define USER_H

#include "../uuidGenerator/UuidGenerator.h"

#include <iostream>
using namespace std;



class User{

private:
    string name;
    string emailId;
    string userId;
    
    User(string newName,string newEmailId,string newUserId){
        name=newName;
        emailId=newEmailId;
        userId=newUserId;
    }

public: 
   
    string getName(){return name;}
    string getEmailId(){return emailId;}
    string getUserId(){return userId;}
    
    void printUser(){
        cout<<"-----------User Data Begin--------------"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Email Id: "<<emailId<<endl;
        cout<<"User Id: "<<userId<<endl;
        cout<<"-----------User Data End--------------"<<endl;
    }

    class UserBuilder{
    
    public:
        string name="";
        string userId="";
        string emailId="";

        UserBuilder* setName(string newName){
            this->name=newName;
            return this;
        }  
        UserBuilder* setEmailId(string newEmailId){
            this->emailId=newEmailId;
            return this;
        }

        User* build(){
            this->userId=UuidGenerator::uuidGenerator("USER");
            return new User(name,userId,emailId);
        }
    };
};



#endif