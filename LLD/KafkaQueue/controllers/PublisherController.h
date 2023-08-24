#ifndef PUBLISHER_CONTROLLER_H
#define PUBLISHER_CONTROLLER_H

#include <vector>
#include <iostream>
using namespace std;

#include "../models/Topic.h"
#include "../models/Publisher.h"

class PublisherController{
private:
    vector< Publisher* > publishers;
public:
    PublisherController(){
    }
    void newPublisher(string name){
        publishers.push_back(new Publisher(name));
    }

    void publishMessage(string publisherName,string message, Topic* topic){
        for(auto publisher: publishers){
            if(publisherName==publisher->getName()){
                publisher->publishMessage(message, topic);
            }
        }
    }
    
    void getAllPublishers(){
        cout<<"Publishers List Begin"<<endl;
        for(auto publisher: publishers){
            cout<<publisher->getName()<<endl;
        }
        cout<<"Publishers List End"<<endl;
    }

};

#endif