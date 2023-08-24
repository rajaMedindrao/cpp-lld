#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <iostream>
using namespace std;

#include "Topic.h"

class Publisher{
private:
    string name;
public:
    Publisher(string name){
        this->name=name;
    }

    string getName(){return this->name;}

    void publishMessage(string message, Topic* topic){
        topic->publishMessage("By "+name+ " "+message);
    }
};

#endif