#include "pa8.h"

// start of functions 

/*************************************************************
 * Function: void clear(void)
 * Description: Clears the screen
 * Input parameters: NA
 * Returns: NA
 * Preconditions: NA
 * Postconditions: Screen cleared
 *************************************************************/
void clear(void)
{
	system("pause");
	system("cls");
}

/*************************************************************
 * Function: char* my_str_n_cat(char* dest, const char* source, int n) 
 * Description: This function copies a determined num of char from source to dest
 * Input parameters: char* dest, const char* source, int n
 * Returns: dest
 * Preconditions: 2 strings 
 * Postconditions: Updated string 
 *************************************************************/
char* my_str_n_cat(char* dest, const char* source, int n) 
{
	while (*dest != '\0') 
	{
		dest++;
	}
	for (int i = 0; i < n; i++) 
	{
		if (*source == '\0') 
		{
			break;
		}
		else 
		{
			*dest = *source;
			dest++;
			source++;
		}
	}
	return dest;
}

/*************************************************************
 * Function:int binary_search(int list[], int size, int target)
 * Description: This function searches through an array to find the target value 
 * Input parameters: int list[], int size, int target
 * Returns: Index
 * Preconditions: Array that can be searched through
 * Postconditions: Finds target value 
 *************************************************************/
int binary_search(int list[], int size, int target) 
{
	int left = 1, right = size, index = -1, mid = 0;
	int found = 0;
	while (!found && left <= right) 
	{
		mid = (left + right) / 2;
		if (list[mid] == target) 
		{
			found = 1;
			index = mid;
		}
		else if (target < list[mid]) 
		{
			right = mid - 1;
		}
		else if (target > list[mid]) 
		{
			left = mid + 1;
		}
	}
	return index;
}

/*************************************************************
 * Function: void bubble_sort(char* arr[], int n)
 * Description: This function sorts a char array by the ASCII of each char in ascending order
 * Input parameters: char* arr[], int n
 * Returns: NA
 * Preconditions: Array to be sorted
 * Postconditions: Sorted array
 *************************************************************/
void bubble_sort(char* arr[], int n) 
{
	int mark1 = n, mark2 = 1, i = 0;

	for (i = 0; i < mark1; i++);
	while (i > 1) 
	{
		mark2 = 1;
		while (mark2 < mark1) 
		{
			if (*arr[mark2] < *arr[mark2 - 1]) 
			{
				char* temp = arr[mark2 - 1];
				arr[mark2 - 1] = arr[mark2];
				arr[mark2] = temp;
			}
			mark2++;
		}
		mark1--;
		for (i = 0; i < mark1; i++);
	}
}

/*************************************************************
 * Function:int is_palindrome(char arr[], int length, int removed)
 * Description: This function determines if a char array is a palindrome
 * Input parameters: char arr[], int length, int removed
 * Returns: True or false
 * Preconditions: Array to be checked
 * Postconditions: Determines if array is a palindrome
 *************************************************************/
int is_palindrome(char arr[], int length, int removed) 
{
	char str[100];
	int count = 0, i = 0;

	while (count < length && !removed) 
	{
		if (arr[i] != ' ') 
		{
			str[count] = arr[i];
			count++;
		}
		i++;
		if (count == length) 
		{
			str[count] = '\0';
		}
	}

	if (!removed) 
	{ 
		if (str[0] == '\0') 
		{
			return 1;
		}

		if (str[0] != str[length - 1]) 
		{
			return 0;
		}

		return is_palindrome(str + 1, length -= 2, 1);
	}
	else 
	{ 
		if (arr[0] == '\0') 
		{
			return 1;
		}

		if (arr[0] != arr[length - 1]) 
		{
			return 0;
		}
		return is_palindrome(arr + 1, length -= 2, 1);
	}
}

/*************************************************************
 * Function: int sum_primes(unsigned int n) 
 * Description: This function determines the total of prime numbers in an int range
 * Input parameters: unsigned int n
 * Returns: Sum
 * Preconditions: Int range to be checked
 * Postconditions: Total of all prime numbers within the range
 *************************************************************/
int sum_primes(unsigned int n) 
{
	int sum = 0;

	if (n == 2) 
	{
		return n;
	}
	if (prime(n)) 
	{
		sum = n;
	}

	return sum_primes(n - 1) + sum;
}

/*************************************************************
 * Function: int prime(unsigned int n)
 * Description: This function determines if a number is prime
 * Input parameters: unsigned int n
 * Returns: 1 if true, 0 if false
 * Preconditions: Number to be checked 
 * Postconditions: Number is prime or not 
 *************************************************************/
int prime(unsigned int n) 
{
	if (n % 2 == 0 && n > 2) 
	{
		return 0;
	}
	for (int i = 3; i < n / 2; i += 2) 
	{
		if (n % i == 0) 
		{
			return 0;
		}
	}
	return 1;
}

/*************************************************************
 * Function: void maximum_occurrences(char* str, Occurrences arr[], int* max_occur, char* str2)
 * Description: This function determines how many times a character is used in a string
 * Input parameters: char* str, Occurrences arr[], int* max_occur, char* str2
 * Returns: Max occurences of a char in the string 
 * Preconditions: Sting to be checked
 * Postconditions: Total of char in string
 * got help from Portfolio Courses on YT
 *************************************************************/
void maximum_occurrences(char* str, Occurrences arr[], int* max_occur, char* str2)
{
	int count[26] = { 0 };
	char temp[26] = { '\0' };
	int next = 0, next2 = 0, num = 0, place = 0, total = 0, max = 0, index = 0;

	while (*str != '\0') 
	{
		num = 0;
		
		for (int i = 0; i < 100; i++) 
		{
			if (*str == temp[i]) 
			{
				place = i;
				num++;
			}
		}
		if (num == 0) 
		{
			temp[next++] = *str;
		}
		else {
			count[place] += num;
		}
		total++;
		str++;
	}

	for (int i = 0; i < sizeof(arr) / sizeof(Occurrences); i++) 
	{
		if (count[i] != 0) 
		{
			arr[i].num_occurences = count[i] + 1;
			arr[i].frequency = (double)(count[i] + 1) / total;
		}
		else 
		{
			arr[i].num_occurences = 1;
			arr[i].frequency = 1.0 / total;
		}
	}

	for (int i = 0; i < 26; i++) 
	{
		if (count[i] > max) 
		{
			max = count[i];
			index = i;
		}
	}

	*max_occur = max + 1;
	*str2 = temp[index];
}

// end of functions 