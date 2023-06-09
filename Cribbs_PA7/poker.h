/*
* Name: Logan Cribbs
* Class: Cpts 121, Spring 2023
* Assignment: Poker
* Description: This is a program that runs a game of 5 card poker against the dealer(computer). You will be dealt 5 cards and you
* cannot see the dealers cards. You will have the chance to swap up to 3 cards, if done you will receive random cards in return.
* Whoever has the best hand wins the game. Rules for the game with combinations are in the rules section in the menu.
*/


// start of guard code
#ifndef POKER_H
#define POKER_H
// get rid of scanf warnings 
#define _CRT_SECURE_NO_WARNINGS

// included libraires
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


// defined constants 
#define HAND 6
#define FACE 13
#define SUIT 4

// struct for card
typedef struct card {
	int face;
	int suit;
} Card;

// struct for hand
typedef struct hand {
	Card hand_array[5];
} Hand;

// void functions 
void shuffle(int deck[][13]);
void deal(const int deck[][13], const char* face[], const char* suit[], Card hand[], Card house_hand[]);
void show_hand(const char* face[], const char* suit[], Card hand[]);
void num_used(Card hand[], int num_used[13]);
void suit_count(Card hand[], int suit[4]);
void clear(void);
void reinit(Card hand[], Card house_hand[], int deck[4][13]);
void dealer_draw(Card hand[], Card house_hand[], int n);
void draw_card(Card hand[], Card house_hand[], int n);
void generate(int* face, int* suit);

// scoring functions 
int pair(Card hand[], int num_used[13]);
int two_pair(Card hand[], int num_used[13]);
int three_kind(Card hand[], int num_used[13]);
int four_kind(Card hand[], int num_used[13]);
int flush(Card hand[], int suit[4]);
int straight(Card hand[], int num_used[13]);
int full_house(Card hand[], int num_used[]);

// check functions 
char char_input(void);
int check_hand(Card hand[]);
int house_deal(Card hand[], int score, int house_score);
int drawn(int face, int suit, Card hand[], Card house_hand[]);
char char_input(void);

// end guard code
#endif