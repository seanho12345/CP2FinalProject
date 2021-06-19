#include "sanjuan.h"

int main(){
    srand(time(NULL));
    int players = 4;
    while(1){
        int choice;
        choice = mainmenu();
        if(choice == 1){
            CLEAR
            players = setplayers();
            game_start(players);
        }else if(choice == 2){
            setlanguage();
        }else if(choice == 3){
            CLEAR
            printbanner();
            printf("See you next time!\n");
            break;
        }
    }
    return 0;
}