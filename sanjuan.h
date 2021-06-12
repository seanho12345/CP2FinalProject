#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#pragma once

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
#define RESET "\033[0m"

#define setcolor(x) printf("%s", x); //Set text color
#define INVALID printf("%sInvalid Input%s\n",RED_BACK,RESET); //Print invalid message
#define CLEAR system("clear"); //Clean Console
#define PAUSE printf("Press Enter key to continue..."); fgetc(stdin);  
#define FLUSH while(getchar() != '\n');

typedef char string[600];

typedef struct _player{
    int buildings[13];
    int deck[12];
    int builds;
    int cards,maxcard;
    int isbot;
}player;

//print menu stuff
void printbanner();
int mainmenu();
int setlanguage();

//game stuff
void main_game(int);
void game_start(int);
void printdeck(int);

//role stuff
void builder(int, int);
void producer(int, int);
void trader(int, int);
void councilor(int, int);
void prospector(int, int);