#ifndef WHOMANDHOWMUCH_H
#define WHOMANDHOWMUCH_H

#include <vector>
#include <string>
using namespace std;

class whomandhowmuch{
private:
    string from_uuid;
    string to_uuid;
    double amount;
public:
    whomandhowmuch(string from_uuid,string to_uuid, double amount){
        this->from_uuid=from_uuid;
        this->to_uuid=to_uuid;
        this->amount=amount;
    }
    string get_from_uuid(){return from_uuid;}
    string get_to_uuid(){return from_uuid;}
    double get_amount(){return amount;}

    void set_amount(double amount){this->amount=amount;}
};

#endif