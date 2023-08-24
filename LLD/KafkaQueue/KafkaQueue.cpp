#include <iostream>
using namespace std;

#include "controllers/KafkaQueueController.h"
#include "controllers/SubscriberController.h"
#include "controllers/PublisherController.h"

int main(){
    cout<<"WELCOME TO KAFKA CONTROLLER"<<endl;
    KafkaQueueController* kafkaQueueController = new KafkaQueueController();
    SubscriberController* subscriberController = new SubscriberController();
    PublisherController* publisherController = new PublisherController();

    cout<<"Creating 2 new topics, 3 publishers and 5 subscribers"<<endl;
    kafkaQueueController->createNewTopic("Topic1");
    kafkaQueueController->createNewTopic("Topic2");

    publisherController->newPublisher("pub1");
    publisherController->newPublisher("pub2");
    publisherController->newPublisher("pub3");

    subscriberController->addSubscriber("sub1",3);
    subscriberController->addSubscriber("sub2",4);
    subscriberController->addSubscriber("sub3",1);
    subscriberController->addSubscriber("sub4",20);
    subscriberController->addSubscriber("sub5",6);

    Subscriber* subscriber=subscriberController->getSubscriber("sub1");
    kafkaQueueController->addSubscriber("Topic1",subscriber);
    subscriber=subscriberController->getSubscriber("sub2");
    kafkaQueueController->addSubscriber("Topic1",subscriber);
    subscriber=subscriberController->getSubscriber("sub3");
    kafkaQueueController->addSubscriber("Topic1",subscriber);
    subscriber=subscriberController->getSubscriber("sub4");
    kafkaQueueController->addSubscriber("Topic1",subscriber);
    subscriber=subscriberController->getSubscriber("sub5");
    kafkaQueueController->addSubscriber("Topic1",subscriber);

    subscriber=subscriberController->getSubscriber("sub1");
    kafkaQueueController->addSubscriber("Topic2",subscriber);
    subscriber=subscriberController->getSubscriber("sub3");
    kafkaQueueController->addSubscriber("Topic2",subscriber);
    subscriber=subscriberController->getSubscriber("sub5");
    kafkaQueueController->addSubscriber("Topic2",subscriber);

    Topic* topic1=kafkaQueueController->getTopic("Topic1");
    Topic* topic2=kafkaQueueController->getTopic("Topic2");
    
    publisherController->publishMessage("pub1","This is a test message",topic1);
    publisherController->publishMessage("pub2","This is a hi message",topic1);
    publisherController->publishMessage("pub1","This is a welcome message",topic2);
    publisherController->publishMessage("pub3","This is a pass message",topic1);
    publisherController->publishMessage("pub3","This is a working message",topic2);
    while(1){}
}