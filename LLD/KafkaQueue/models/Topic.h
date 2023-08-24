#ifndef TOPIC_H
#define TOPIC_H

#include "thread"
#include <vector>
#include <iostream>
using namespace std;

#include "Subscriber.h"
#include "../generateUUID/GenerateUUID.h"

class Topic{
private:
    string uuid;
    string name;
    vector< Subscriber* > subscribersList;
    vector<string> messages;

public:
    Topic(string name){
        this->name=name;
        this->uuid=GENERATE_UUID_H("TOPIC");
    }

    string getUUID(){
        return this->uuid;
    }

    string getName(){
        return this->name;
    }

    void threadPublishMessage(Subscriber& subscriber, string message){
        subscriber.recieveMessage(message);
    }

    void publishMessage(string message){
        messages.push_back(message);
        for(auto subscriber: subscribersList){
            thread th1(&Subscriber::recieveMessage,subscriber,message);
            // subscriber->recieveMessage(message);
            // std::thread t = std::thread([this](std::ref(subscriber),message) {
            //         subscriber->recieveMessage(message);
            //     });
            th1.detach();
            // th1.join();
        }
    }
    void addSubscriber(Subscriber* subscriber){
        subscribersList.push_back(subscriber);
    }
    void removeSubscriber(Subscriber* subscriber){
        int remove=-1;
        for(int i=0;i<subscribersList.size();i++){
            if(subscribersList[i]==subscriber){
                remove=i;
            }
        }
        if(remove!=-1){
            subscribersList.erase(subscribersList.begin()+remove);
        }
    }

};

#endif