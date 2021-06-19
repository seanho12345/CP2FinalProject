#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#ifndef SANJUAN_H
#define SANJUAN_H

typedef char string[600];

#define i8 int8_t
#define u8 uint8_t
#define i16 int16_t
#define u16 uint16_t
#define i32 int32_t
#define u32 uint32_t
#define i64 int64_t
#define u64 uint64_t

//Colored Text
#define RED   "\033[31m"
#define GRN   "\033[32m"
#define YEL   "\033[33m"
#define BLU   "\033[34m"
#define MAG   "\033[35m"
#define CYN   "\033[36m"
#define WHT   "\033[37m"
#define RED_BACK   "\033[41m"
#define GRN_BACK   "\033[42m"
#define YEL_BACK   "\033[43m"
#define BLU_BACK   "\033[44m"
#define MAG_BACK   "\033[45m"
#define CYN_BACK   "\033[46m"
#define RESET "\033[0m"

#define setcolor(x) printf("%s", x); //Set text color
#define INVALID printf("%s%s%s\n",RED_BACK,invalidtext[language],RESET); //Print invalid message
#define CLEAR system("clear"); //Clean Console
#define PAUSE printf("Press Enter key to continue..."); fgetc(stdin);  
#define FLUSH while(getchar() != '\n');



typedef struct _player{
    int buildings[12];
    int hasgoods[12];
    int deck[20];
    int builds;
    int cards,maxcard;
    int isbot;
    int chapelvp;
}player;

//print menu stuff
void printbanner();
int mainmenu();
void setlanguage();

//game stuff
void main_game(int);
void game_start(int);
void printdeck(int);
void caculatevp(int *, int);
void cardoverflow(int);
void checkstat(int);

//role stuff
void builder(int);
void producer(int);
void trader(int);
void councilor(int);
void prospector(int);

//card stuff
int smithy(int, int);
void tower(int, int);
void poorhouse(int);
int blackmarket(int, int);
void carpenter(int, int);
int quarry(int, int);
void well(int, int);
int aqueduct(int);
void marketstand(int, int);
void markethall(int);
int tradingpost(int);
int prefecture(int);
void goldmine(int);
int guildhall(int);
int cityhall(int);
int triumhalarch(int);
int palace(int, int);
void chapels(int);

#endif