#ifndef ATTRIBUTEVECTOR_H
#define ATTRIBUTEVECTOR_H

#include "Attributes.h"

#include <vector>
using namespace std;

class AttributeVector{
private:
    vector< Attributes* > attributes;

    string trimColons(string input){
        return input.substr(1,input.size()-2);
    }

public:
    void pushAttribute(Attributes* attribute){
        attributes.push_back(attribute);
    }
    string print(){
        string ans="";
        for(auto attribute: attributes){
            ans=ans+attribute->print()+", ";
        }
        return ans;
    }
    bool search(string key,string value){
        bool ans=false;
        for(auto attribute: attributes){
            if(attribute->getAttributeKey()==trimColons(key)){
                if(value[0]=='\"'){
                    if(attribute->getAttributeValueType()=="string"){
                        if(trimColons(value)==attribute->getAttributeValue()){
                            ans=true;
                            break;
                        }
                    }
                }else{
                    if(stof(value)==stof(attribute->getAttributeValue())){
                        ans=true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

#endif