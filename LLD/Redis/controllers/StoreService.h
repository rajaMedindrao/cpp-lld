#ifndef KEY_VALUE_STORE_H
#define KEY_VALUE_STORE_H

#include <iostream>
using namespace std;

#include "../models/Store.h"

class StoreService{
private:
    Store* storeModel;

    string trimColons(string input){
        return input.substr(1,input.size()-2);
    }

public:
    StoreService(){
        storeModel= new Store();
    }

    void addValue(string input){
        // parsethis & add attribute type
        vector<string> inputs;
        string temp="";
        for(int i=0;i<input.size();i++){
            if(input[i]==' '){
                if(temp!=""){
                    inputs.push_back(temp);
                    temp="";
                }
            }else{
                temp+=input[i];
            }
        }
        if(temp!=""){
            inputs.push_back(temp);
            temp="";
        }
        storeModel->addNewValue(inputs);
    }

    void deleteValue(string key){
        storeModel->deleteValue(trimColons(key));
    }

    string print(){
        return storeModel->print();
    }

    string print(string key){
        if(!storeModel->hasKey(trimColons(key))){
            return "No value for "+ key;
        }
        return storeModel->print(trimColons(key));
    }

    vector<string> getKeys(){
        return storeModel->getKeys();
    }

    vector<string> search(string key,string value){
        return storeModel->search(key,value);
    }
};

#endif