//guard code 
#ifndef YAHTZEE_H
#define YAHTZEE_H
// removes printf and scanf warnings 
#define _CRT_SECURE_NO_WARNINGS

// defined constanstants like in PA 3
#define DIE_VALUE 6
#define NUM_DIE 7


// all libraries needed are included 
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h> 

// pauses and clears the screen
void clear(void);

// prints the rules of the game 
void print_rules(void);
// prints the example scorecard with all combinantions to be made
void ex_scorecard(void);
// rolls the 5 dice
int roll_dice(int dice[]);
// sorts the dice 
void sort(int arr[], int size);
// adds up the array
int sum_array(int array[], int size);
// prints the dice roll
void print_die(int dice[], int count);
// if more than one roll is needed 
void next_roll(char* next_roll_ptr);
// see if another roll is being used and which dice are being kept 
void check_roll(int dice[]);
// prints the combo options 
void score_type(int* combo_choice, int check_combo[]);
// get the dice values 
void get_num_die(int dice[], int die_val[]);
// combo scoring options 
void yahtzee(int die_val[], int low[]);
void large_st(int die_val[], int low[]);
void small_st(int die_val[], int low[]);
void full_house(int die_val[], int low[]);
void four_kind(int dice[], int die_val[], int low[]);
void three_kind(int dice[], int die_val[], int low[]);
// add up total from turn
void score_roll(int dice[], int die_val[], int up[], int low[], int check_combo[]);

// end of guard code
#endif