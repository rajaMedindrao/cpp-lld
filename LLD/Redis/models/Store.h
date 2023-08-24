#ifndef STORE_H
#define STORE_H

#include <utility>
#include <set>
#include <iostream>
#include <unordered_map>
using namespace std;

#include "Attributes.h"
#include "AttributeVector.h"

class Store{
private:
    unordered_map<string, AttributeVector* > storeMap;
    unordered_map<string,string> attributeTypesHashMap;

    string trimColons(string input){
        return input.substr(1,input.size()-2);
    }

public:
    void addNewValue(vector<string> inputs){
        string key=trimColons(inputs[0]);
        storeMap[key]=new AttributeVector();
        for(int i=1;i<(inputs.size());i+=2){
            string tempKey=trimColons(inputs[i]);
            string tempValue=inputs[i+1];
            Attributes* tempAttributes=new Attributes(tempKey);
            if(tempValue[0]=='\"'){
               tempAttributes->setAttributeValue(trimColons(tempValue)); 
               attributeTypesHashMap[tempKey]="string";
            }else{
                if(tempValue.find(".")==-1){
                    tempAttributes->setAttributeValue(stoi(tempValue));
                    attributeTypesHashMap[tempKey]="int";
                }else{
                    tempAttributes->setAttributeValue(stof(tempValue));
                   attributeTypesHashMap[tempKey]="float";
                }
            }
            storeMap[key]->pushAttribute(tempAttributes);
        }
        
    }

    bool hasKey(string key){
        if(storeMap.find(key)!=storeMap.end()){
            return true;
        }
        return false;
    }

    AttributeVector* getAttributeVector(string key){
        return storeMap[key];
    }

    void deleteValue(string key){
        storeMap.erase(key);
    }

    string print(string key){
        string ans="";
        ans=storeMap[key]->print();
        return ans;
    }

    string print(){
        string ans="";
        for(auto entry:storeMap){
            ans=ans+entry.first+" -> "+print(entry.first);
            ans+="\n";
        }
        return ans;
    }

    vector<string> getKeys(){
        vector<string> ans;
        for(auto keyValue:storeMap){
            ans.push_back(keyValue.first);
        }
        return ans;
    }
    
    string getAttibuteType(string key){
        return attributeTypesHashMap[key];
    }

    bool hasAttibuteType(string key){
        if(attributeTypesHashMap.find(key)!=attributeTypesHashMap.end()){
            return true;
        }
        return false;
    }

    void setAttributeType(string key,string value){
        attributeTypesHashMap[key]=value;
    }

    vector<string> search(string key,string value){
        vector<string> ans;
        for(auto keyValue: storeMap){
            if(keyValue.second->search(key,value)){
                ans.push_back(keyValue.first);
            }
        }
        return ans;
    }
};

#endif