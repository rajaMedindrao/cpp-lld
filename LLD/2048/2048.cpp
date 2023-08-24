#include <iostream>

#include "services/Controller.h"

using namespace std;

int main(){
    Controller* game2048Controller= new Controller();
    game2048Controller->printBoard();
    while(true){
        string input;
        game2048Controller->printInstructions();
        cin>>input;
        game2048Controller->performAction(input);
    }
    return 0;
}