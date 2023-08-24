#ifndef ATTRIBUTES
#define ATTRIBUTES

#include <iostream>
using namespace std;


class Attributes{
private:
    string attributeKey;
    string attributeValueType;
    int intAttributeValue;
    float floatAttributeValue;
    string stringAttributeValue;

public:
    string getAttributeKey()
    {
        return this->attributeKey;
    }

    Attributes(string attributeKey)
    {
        this->attributeKey = attributeKey;
    }

    void setAttributeValue(int attributeValue){
        this->intAttributeValue=attributeValue;
        this->attributeValueType="int";
    }

    void setAttributeValue(float attributeValue){
        
        this->floatAttributeValue=attributeValue;
        this->attributeValueType="float";
    }

    void setAttributeValue(string attributeValue){
        this->stringAttributeValue=attributeValue;
        this->attributeValueType="string";
    }

    string getAttributeValue(){
        if(attributeValueType=="int"){
            return to_string(intAttributeValue);
        }else if(attributeValueType=="float"){
            return to_string(floatAttributeValue);
        }
       return stringAttributeValue;
    
    }

    string getAttributeValueType(){
        return attributeValueType;
    }

    string print(){
        string ans=attributeKey+": ";
        if(attributeValueType=="int"){
            ans+=to_string(intAttributeValue);
        }else if(attributeValueType=="float"){
            ans+=to_string(floatAttributeValue);
        }else if(attributeValueType=="string"){
            ans+=stringAttributeValue;
        }
        return ans;
    }

};

#endif