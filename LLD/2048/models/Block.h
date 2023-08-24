#ifndef BLOCK_H
#define BLOCK_H

using namespace std;

class Block{
private:
    int val;
    
public:
    Block(){
        this->val=-1;
    }

    Block(int newVal){
        this->val=newVal;
    }

    void setVal(int newVal){this->val= newVal;}

    int getVal(){return this->val;}

};

#endif