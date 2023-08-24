#ifndef SUBSCRIBER_CONTROLLER_H
#define SUBSCRIBER_CONTROLLER_H

#include <iostream>
using namespace std;

#include "../models/Subscriber.h"

class SubscriberController{
private:
    vector<Subscriber* > subscribersList;
public:
    SubscriberController(){}

    void addSubscriber(string name,int seconds){
        subscribersList.push_back(new Subscriber(name,seconds));
    }

    void getAllSubscribers(){
        cout<<"Subscribers List Begin"<<endl;
        for(auto subscriber: subscribersList){
            cout<<subscriber->getName()<<endl;
        }
        cout<<"Subscribers List End"<<endl;
    }

    Subscriber* getSubscriber(string name){
        for(auto subscriber: subscribersList){
            if(subscriber->getName()==name){
                return subscriber;
            }
        }
        return nullptr;
    }
};

#endif