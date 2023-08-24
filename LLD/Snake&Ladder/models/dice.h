#ifndef DICE_H
#define DICE_H

#include "stdlib.h"
#include "time.h"

int get_number(int no_of_dice){
    int ans=0;        
    for(int i=0;i<no_of_dice;i++){
        ans+=rand()%6;
        ans++;
    }
    return ans;
}

#endif