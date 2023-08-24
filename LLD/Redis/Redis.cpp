#include <iostream>
using namespace std;

#include "controllers/StoreService.h"

int main(){
    cout<<"Welcome to Key Value Store"<<endl;
    StoreService* storeService=new StoreService();
    while(1){
        string type;
        string input;
        cin>>type;
        if(type=="put"){
            cin.ignore(); 
            getline(cin,input);
            storeService->addValue(input);
        }
        if(type=="get"){
            cin.ignore(); 
            getline(cin,input);
            cout<<storeService->print(input)<<endl;
        }
        if(type=="print"){
            cout<<storeService->print()<<endl;
        }
        if(type=="keys"){
            cout<<"------BEGIN-------"<<endl;            
            for(auto str: storeService->getKeys()){
                cout<<str<<endl;
            }
            cout<<"------END-------"<<endl;
        }
        if(type=="delete"){
            cin.ignore(); 
            getline(cin,input);
            storeService->deleteValue(input);
        }
        if(type=="search"){
            string key,value;
            cin>>key;
            cin>>value;
            vector<string> ans=storeService->search(key,value);
            cout<<"---START---"<<endl;
            for(auto str: ans){
                cout<<str<<endl;
            }
            cout<<"---END---"<<endl;
        }
    }
    return 0;
}