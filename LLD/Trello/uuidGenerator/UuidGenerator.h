#ifndef UUID_GENERATOR_H
#define UUID_GENERATOR_H

#include <iostream>
#include <uuid/uuid.h>
using namespace std;

class UuidGenerator{
public:
    static string uuidGenerator(string type){
        uuid_t uid;
        uuid_string_t ust;
        uuid_generate_random(uid);
        uuid_unparse(uid,ust);
        string ans=type+(string)ust;
        return ans;
    }
};

#endif