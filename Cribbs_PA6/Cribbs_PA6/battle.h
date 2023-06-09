/*
Name: Logan Cribbs 
Date: March 25, 2023
Class: CptS 121, Spring 2023
Description: The program simulates the game of battleship vs the computer. Player 1 will chose to either manually place their 
ships or randomly place them. Then turn order will be decided at random. Players will take turns chosing locations to 
attack. If hit, it will be marked by a *, if miss it will be marked by a 'm'. This will continue untill one players fleet has
been completely destroyered. A file will track all turns and stats from the game.
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_C 10
#define CARRIER 5
#define BATTLE 5
#define CRUISER 3
#define SUB 3
#define DESTROYER 2



void welcome_screen(void);
void clear(void);
void print_rules(void);
void init_board(char board[][MAX_C], int num_rows, int num_cols);
void print_board(char board[][MAX_C], int num_rows, int num_cols);
int roll_die(int die1, int die2, int* roll1, int* roll2);
char man_or_ran(void);
int manuel_place_ships(char board[][MAX_C]);
