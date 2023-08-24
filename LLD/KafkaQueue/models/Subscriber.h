#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

#include "Topic.h"

class Subscriber{
private:
    string name;
    int secondsSleep;
    std::mutex sub_mutex_lock;

public:    
    Subscriber(string name,int seconds){
        this->name=name;
        this->secondsSleep=seconds;
    }
    void recieveMessage(string message){
        sub_mutex_lock.lock();
        string printMe="I am "+name+" Recieved message :  "+message;
        cout<<printMe<<endl;
        this_thread::sleep_for(chrono::seconds(secondsSleep));
        sub_mutex_lock.unlock();
    }
    string getName(){
        return this->name;
    }
};

#endif