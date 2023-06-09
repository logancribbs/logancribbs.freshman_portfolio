/*
Name: Logan Cribbs
Date: March 25, 2023
Class: CptS 121, Spring 2023
Description: The program simulates the game of battleship vs the computer. Player 1 will chose to either manually place their
ships or randomly place them. Then turn order will be decided at random. Players will take turns chosing locations to
attack. If hit, it will be marked by a *, if miss it will be marked by a 'm'. This will continue untill one players fleet has
been completely destroyered. A file will track all turns and stats from the game.
*/

// start of guard code
#ifndef BS_H
#define BS_H

// remove scanf warnings
#define _CRT_SECURE_NO_WARNINGS

// included libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// used for certain parts of program, got idea from Portfolio Courses on Youtube
#include <stdbool.h>


// defined constants 
#define CARRIER 5
#define BATTLESHIP 4
#define SUB 3
#define CRUISER 3
#define DESTROYER 2
#define HORI 0
#define VERT 1
#define NUM_ROWS 10
#define NUM_COLS 10

// struct for tracking stats in log file 
typedef struct stats
{
	int hits, miss, total;
	double hit_miss;
} Stats;

// function declarations 
void clear(void);
void welcome_screen(void);
void print_rules(void);
void init_board(char board[10][10], int rows, int cols);
void print_board(char board[10][10], int rows, int cols);
int gen_dir(void);
void gen_sp(int dir, int length, int* row, int* col);
void place_ship(char board[][NUM_COLS], int rows, int cols, int length, char ship, int dir, int r_start, int c_start);
int detect_col(char board[][NUM_COLS], int dir, int length, int row, int col);
int go_first(void);
void man_place(char board[][NUM_COLS]);
int check_place(char board[][NUM_COLS], int coords[], int size);
void sort(int arr[], int size);
int win(char board[][NUM_COLS]);
void board_update(char board[][NUM_COLS], int x, int y, int hit);
int check_shot(char board[][NUM_COLS], int x, int y, char* toke);
int check_sunk(char board[][NUM_COLS], char ship);
void output_move(FILE* outfile, int player, int x, int y, int hit, int sunk);
void output_stats(FILE* outfile, Stats p_1, Stats p_2);

// end guard code
#endif
