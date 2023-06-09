/*
Name: Logan Cribbs
Class: CPT_S 121, Spring 2023
Assignment: Interview Questions 
Description: This program runs through a set of functions provided in the assignment instructions.
They are mock interview questions.
*/

// guard code
#ifndef INTERVIEW_H
#define INTERVIEW_H

// clear scan warnings 
#define _CRT_SECURE_NO_WARNINGS

// included libraires
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// struct used for occurances function
typedef struct occurrences {
	int num_occurences;
	double frequency;
} Occurrences;

// clears the screen
void clear(void);
// function for question 1
char* my_str_n_cat(char* dest, const char* source, int n);
// function for question 2
int binary_search(int list[], int size, int target);
// function for question 3
void bubble_sort(char* arr[], int n);
// function for question 4
int is_palindrome(char str[], int length, int removed);
// functions for question 5
int sum_primes(unsigned int n);
int prime(unsigned int n);
// function for question 6
void maximum_occurrences(char* str, Occurrences arr[], int* n, char* str2);

// end guard code
#endif
