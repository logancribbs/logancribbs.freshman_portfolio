#include "pa8.h"

// start of program 
int main(void) 
{
	// int variable
	int occurrences = 0;
	// char variable 
	char letter = '\0';

	// all arrrays used in the program
	char bit[100] = "bit";
	char w1[10] = "Seahawks";
	char w2[10] = "Ravens";
	char w3[10] = "Broncos";
	char w4[10] = "Chiefs";
	int* list[4] = { w1, w2, w3, w4 };
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	// struct array for question 6
	Occurrences array[10];
	
	// describes what is happening in the program
	printf("These are example of commonly asked interview questions and the functions\nbeing ran to determine is solution was correct\n");
	// clears the screen
	clear();
	// opening screen
	printf("PA8 Interview Questions\n");
	// clears the screen 
	clear();

	// question 1
	// calling function
	my_str_n_cat(bit, "ear", 1);
	// print result of called function
	printf("Example for using my_str_n_cat function\n\n");
	printf("bit + first letter of ear = %s\n", bit);
	// clears the screen 
	clear();

	// question 2
	// prints the result of calling binary search in 2 examples
	printf("Using binary_search\n");
	// true
	printf("Index of 15 in array: %d\n", binary_search(arr, 10, 15));
	// false
	printf("Index of 200 in array: %d\n", binary_search(arr, 10, 200));
	// clears the screen
	clear();

	//question 3
	printf("Using bubble_sort\n");
	// prints unsorted list 
	printf("Unsorted List:\n");
	for (int i = 0; i < 4; i++) 
	{
		puts(list[i]);
	}
	// new line 
	printf("\n");
	// calls bubble_sort
	bubble_sort(list, 4);
	// prints sorted list 
	printf("Sorted List:\n");
	for (int i = 0; i < 4; i++) 
	{
		puts(list[i]);
	}
	// clears the screen
	clear();

	// question 4
	// prints the reult of call palindrome function
	printf("Using is_palindrome\n");
	// true
	printf("Is racecar a palindrome: %s\n", is_palindrome("racecar", 7, 0) ? "true" : "false");
	// false
	printf("Is tiktok a palindrome: %s\n", is_palindrome("tiktok", 7, 0) ? "true" : "false");
	// clears the screen
	clear();

	// question 5
	// prints the result of sum_primes along an interger range
	printf("Adding the sum of primes in a certain integer range\n");
	// result should be 17
	printf("Sum of primes from 1 to 10: %d\n", sum_primes(10));
	// clears the screen
	clear();

	// question 6
	printf("Using max_occurrences to determine how many times a char is found in the string\n");
	// calls occurence of 'p' string happy 
	maximum_occurrences("happy", array, &occurrences, &letter);
	// prints result
	printf("%c occurs in the string 'happy', %d times.\n", letter, occurrences);
	// calls occurence of 'p' in madden
	maximum_occurrences("madden", array, &occurrences, &letter);
	// prints results 
	printf("%c occurs in the string 'madden', %d times.\n", letter, occurrences);


	return 0;
}