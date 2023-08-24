#ifndef GENERATE_UUID_H
#define GENERATE_UUID_H

#include "uuid/uuid.h"
#include <iostream>
using namespace std;


class GenerateUUID{
public:
    static string generateUUID(string prefix){
        uuid_t uid;
        uuid_string_t stringUid;
        uuid_generate_random(uid);
        uuid_unparse(uid,stringUid);
        string ans=prefix+"_"+stringUid;
        return ans;
    }
};

#endif