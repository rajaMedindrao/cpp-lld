#ifndef KAFKA_QUEUE_CONTROLLER_H
#define KAFKA_QUEUE_CONTROLLER_H

#include <unordered_map>
#include <iostream>
using namespace std;

#include "../models/Topic.h"

class KafkaQueueController{
private:
    unordered_map<string, Topic* > topicsMap;
public:
    KafkaQueueController(){}
    
    void createNewTopic(string topicName){
        Topic* topic=new Topic(topicName);
        topicsMap[topicName]=topic;
    }

    bool isTopicUUIDPresent(string topicName){
        if(topicsMap.find(topicName)!=topicsMap.end()){
            return true;
        }
        return false;
    }

    Topic* getTopic(string topicName){
        if(!isTopicUUIDPresent(topicName)){return nullptr;}
        return topicsMap[topicName];
    }

    void publishMessage(string topicName, string message){
        if(!isTopicUUIDPresent(topicName)){return;}
        topicsMap[topicName]->publishMessage(message);
    }

    void addSubscriber(string topicName, Subscriber* subscriber){
        if(!isTopicUUIDPresent(topicName)){return;}
        topicsMap[topicName]->addSubscriber(subscriber);
    }

    void removeSubscriber(string topicName, Subscriber* subscriber){
        if(!isTopicUUIDPresent(topicName)){return;}
        topicsMap[topicName]->removeSubscriber(subscriber);
    }

    void allTopicsNamesUUID(){
        cout<<"Listing all the topics"<<endl;
        for(auto topicEntry: topicsMap){
            cout<<topicEntry.first<<endl;
        }
        cout<<"End Topics List"<<endl;
    }

};

#endif