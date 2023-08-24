#include "./models/group.h"
#include "./models/grouplist.h"
#include "./models/user.h"
#include "./models/usermetadata.h"
#include "./models/whomandhowmuch.h"

#include<iostream>
using namespace std;

void print_info(){
    cout<<"Press 1 to form a group with group id"<<endl;
    cout<<"Press 2 add expenses to a group with group_id & statement"<<endl;
    cout<<"Press 3 to show balance of all users in a group"<<endl;
    cout<<"Press 4 to show balance of a user in a group"<<endl;
}

int main(){
    int resp=0,cnt=0;
    grouplist* groupList= new grouplist();
    while(cnt<10){
        cnt++;
        print_info();
        cin>>resp;
        cout<<resp<<endl;
        if(resp==1){
            string group_id;
            cout<<"Enter group_id"<<endl;
            cin>>group_id;
            groupList->newgroup(group_id, new group(group_id));
        }else if(resp==2){
            cout<<"Please enter statement"<<endl;
            string group_id,from_uuid;
            cin>>group_id;
            cin>>from_uuid;
            cout<<from_uuid<<" hello"<<endl;
            double amount;
            cin>>amount;
            int no_to;
            cout<<"hi"<<endl;
            cin>>no_to;
            vector<string> to_uuid;
            for(int i=0;i<no_to;i++){
                string temp;
                cin>>temp;
                to_uuid.push_back(temp);
            }
            string whichstat;
            cin>>whichstat;
            cout<<"HI"<<endl;
            if(whichstat=="EQUAL"){
                groupList->getgroup(group_id)->add_equal_expense(from_uuid,amount,to_uuid);
            }else if(whichstat=="PERCENT"){
                vector<int> percents;
                for(int i=0;i<no_to;i++){
                    int temp;cin>>temp;
                    percents.push_back(temp);
                }
                groupList->getgroup(group_id)->add_percent_expense(from_uuid,amount,percents,to_uuid);
            }else if(whichstat=="EXACT"){
                vector<double> partialamounts;
                for(int i=0;i<no_to;i++){
                    double temp;cin>>temp;
                    partialamounts.push_back(temp);
                }
                groupList->getgroup(group_id)->add_exact_expense(from_uuid,amount,partialamounts,to_uuid);
            }
            cout<<"finished"<<endl;
        }else if(resp==3){
            cout<<"Enter group id"<<endl;
            string group_id;
            cin>>group_id;
            groupList->getgroup(group_id)->getallexpenses();
        }else if(resp==4){
            cout<<"Enter group id & user id"<<endl;
            string group_id,user_id;
            cin>>group_id;
            cin>>user_id;
            groupList->getgroup(group_id)->getexpense(user_id);
        }
    }

}
