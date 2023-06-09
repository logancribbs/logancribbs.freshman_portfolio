/*
Name: Logan Cribbs 
Date: Feb. 20, 2023
Class: CPTS 121, Spring 2023
Description: This program runs the game craps. A bank balance is set and that is what you can 
use to place wager. If you lose the money is subtracted, if you win the money is awarded to your
balance. The game lets you see your balance, set your balance if there is no money, and display
the rules of the game.
*/


//start of guard code
#ifndef CRAPS_H // part of guard code
#define CRAPS_H // part of guard code

#define _CRT_SECURE_NO_WARNINGS // to ignore _s unsafe warnings

// including libraries for assignment 
#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <time.h>


// function declarations
// all double functions 
double get_bank_balance(void);
double get_wager_amount(void);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_sub);

// print functions 
void print_game_rules(void);
void chatter_messages(int number_rolls, int point, double initial_bank_balance, int message);

// int function
int valid(int option, int num_items, int min_items);
int check_wager_amount(double wager_amount, double bank_balance);
int roll_die(void);
int sum_of_dice(int die1, int die2);
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_roll, int point_value);

#endif // end of guard code
