#ifndef GROUP_H
#define GROUP_H

#include "user.h"
#include "usermetadata.h"
#include "whomandhowmuch.h"

#include <set>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class group{
private:
    string group_id;
    // vector<user_id>
    set<string> users_in_this_group;
    // map<user_id, whomandhowmuch>
    unordered_map<string, vector<whomandhowmuch*> > topay;
public:
    group(string group_id){this->group_id=group_id;}

    bool add_user(string user_id){users_in_this_group.insert(user_id);return true;}
// write get_users vector


    bool update_whomandhowmuch(string from_uuid, string to_uuid, double amount){
        // checking opposite

        if(from_uuid==to_uuid){return true;}

        for(int i=0;i<topay[from_uuid].size();i++){
            if(topay[from_uuid][i]->get_to_uuid()==to_uuid){
                int prev_amount=topay[from_uuid][i]->get_amount();
                if(prev_amount>=amount){
                    topay[from_uuid][i]->set_amount(prev_amount-amount);
                    return true;
                }else{
                    topay[from_uuid][i]->set_amount(0);
                    amount-=prev_amount;
                }
            }
        }

        cout<<to_uuid<<" to uuid "<<amount<<endl;
        // General update
        for(int i=0;i<topay[to_uuid].size();i++){
            if(topay[to_uuid][i]->get_to_uuid()==from_uuid){
                int prev_amount=topay[to_uuid][i]->get_amount();
                topay[to_uuid][i]->set_amount(prev_amount+amount);
                return true;
            }
        }
        topay[to_uuid].push_back(new whomandhowmuch(from_uuid,to_uuid,amount));
        return true;
    }

    bool add_equal_expense(string from_uuid,double amount, vector<string> to_uuids){
        double partial_amount=amount/to_uuids.size();
        double firstamount=amount-partial_amount*(to_uuids.size()-1);
        bool first=true;
        users_in_this_group.insert(from_uuid);
        for(string to_uuid: to_uuids){
            users_in_this_group.insert(to_uuid);
            if(first){
                update_whomandhowmuch(from_uuid,to_uuid,firstamount);
                first=false;
                continue;
            }
            update_whomandhowmuch(from_uuid,to_uuid,partial_amount);
        }
        return true;
    }

    bool add_percent_expense(string from_uuid, double amount, vector<int> percent, vector<string> to_uuids){
        int total=0;
        for(int temp_perc: percent){total+=temp_perc;}
        if(total!=100){cout<<"Percents are not adding up to 100"<<endl;return false;}
        users_in_this_group.insert(from_uuid);
        for(int i=0;i<to_uuids.size();i++){
            string to_uuid=to_uuids[i];
            users_in_this_group.insert(to_uuid);
            update_whomandhowmuch(from_uuid,to_uuid,(double)((amount*percent[i])/100));
        }
        return true;
    }

    bool add_exact_expense(string from_uuid, double amount, vector<double> partialamounts, vector<string> to_uuids){
        double total=0;
        for(double temp_perc: partialamounts){total+=temp_perc;}
        if(total!=amount){cout<<"Exact amounts are not adding to given amount"<<endl;return false;}
        users_in_this_group.insert(from_uuid);
        for(int i=0;i<to_uuids.size();i++){
            string to_uuid=to_uuids[i];
            users_in_this_group.insert(to_uuid);
            update_whomandhowmuch(from_uuid,to_uuid,partialamounts[i]);
        }
        return true;
    }

    void getexpense(string user_id){
        for(whomandhowmuch* temp: topay[user_id]){
            if(temp->get_amount()!=0){
                cout<<user_id<<" should pay "<<temp->get_to_uuid()<<" "<<temp->get_amount()<<endl;
            }
        }
    }

    void getallexpenses(){
        for(string user_id: users_in_this_group){
            getexpense(user_id);
        }
    }
};


#endif