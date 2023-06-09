#include "pa4.h" // includes header


// start of functions 

/*************************************************************
 * Function:  print_game_rules(void)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function prints the rule of craps.
 * Input parameters: NA
 * Returns: NA
 * Preconditions: Option 1 selected
 * Postconditions: Returns to menu
 *************************************************************/
void print_game_rules(void)
{
	
	printf("Rules of Craps\n");
	printf("A player rolls two dice. Each die has six faces.\nThese faces contain 1, 2, 3, 4, 5, and 6 spots.\nAfter the dice have come to rest, the sum of the spots on the two upwardfaces is calculated.\nIf the sum is 7 or 11 on the first throw, the player wins.\nIf the sum is 2, 3, or 12 on the first throw (called craps), the player loses(i.e.the housewins).\nIf the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes theplayer's point.\nTo win, you must continue rolling the dice until you make your point.\nThe player loses by rolling a 7 before making the point.\n");
	system("pause");
	system("cls");
}


/*************************************************************
 * Function:  get_bank_balance(void)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: Prompts for a bank balance and stores it.
 * Input parameters: NA
 * Returns: bank_balance
 * Preconditions: bank_balance = 0.0
 * Postconditions: bank_balance set to user input
 *************************************************************/
double get_bank_balance(void)
{
	double bank_balance = 0.0;
	printf("Enter how much money you wish to play with:\n");
	scanf("%lf", &bank_balance);
	return bank_balance;
}


/*************************************************************
 * Function:  get_wager_amount(void)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function prompts for a wager and stores the value.
 * Input parameters: NA
 * Returns: wager_amount
 * Preconditions: No wager placed 
 * Postconditions: Stored wager
 *************************************************************/
double get_wager_amount(void)
{
	double wager_amount = 0.0;
	printf("Enter how much you want to wager for this round:\n");
	scanf("%lf", &wager_amount);
	return wager_amount;
}


/*************************************************************
 * Function: check_wager_amount(double wager_amount, double bank_balance)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function checks to see if the wager exceeds the bank balance 
 * Input parameters: double wager_amount, double bank_balance
 * Returns: valid
 * Preconditions: Must have bank balance and wager amount
 * Postconditions: Validates wager
 *************************************************************/
int check_wager_amount(double wager_amount, double bank_balance)
{
	int valid = 0;
	if (bank_balance >= wager_amount)
	{
		valid = 1;
	}
	return valid;
}


/*************************************************************
 * Function: roll_die(void)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function produces a random number between 1-6
 * Input parameters: NA
 * Returns: rand() % 6 + 1
 * Preconditions: NA
 * Postconditions: Random number b/w 1-6
 *************************************************************/
int roll_die(void)
{
	return rand() % 6 + 1;
}


/*************************************************************
 * Function: sum_of_dice(int die1, int die2)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function computes the sum of 2 rolled dice
 * Input parameters: int die1, int die2
 * Returns: sum
 * Preconditions: Values for die1 and die2
 * Postconditions: Sum of 2 dice 
 *************************************************************/
int sum_of_dice(int die1, int die2)
{
	int sum = die1 + die2;
	printf("Your Roll\n%d + %d = %d\n", die1, die2, sum);
	return sum;
}


/*************************************************************
 * Function:  is_win_loss_or_point(int sum_roll)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function determines whether the first roll resulted in win, loss, or need for another roll
 * Input parameters: int sum_roll
 * Returns: point
 * Preconditions: Must have sum of the rolls
 * Postconditions: Point value to dictate what happens next
 *************************************************************/
int is_win_loss_or_point(int sum_roll)
{
	int point = -1;
	if ((sum_roll == 7) || (sum_roll == 11))
	{
		printf("You Win!\n");
		point = 1;
	}
	if ((sum_roll == 2) || (sum_roll == 3) || (sum_roll == 12))
	{
		printf("You Lose!\n");
		point = 0;
	}
	if ((sum_roll != 7) && (sum_roll != 11) && (sum_roll != 2) && (sum_roll != 3) && (sum_roll != 12))
	{
		printf("Your Point to Win!\n");
		point = -1;
	}
	return point;
}


/*************************************************************
 * Function: is_point_loss_or_neither(int sum_dice, int point_value)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function determines the result off all successive rolls
 * Input parameters: int sum_dice, int point_value
 * Returns: point
 * Preconditions: Must have previous point value, and new sum of rolled dice
 * Postconditions: Determines result of round
 *************************************************************/
int is_point_loss_or_neither(int sum_dice, int point_value)
{
	int point = -1;
	if (point_value == sum_dice)
	{
		printf("You Won!\n");
		point = 1;
	}
	if (sum_dice == 7)
	{
		printf("You Lost!\n");
		point = 0;
	}
	return point;
}


/*************************************************************
 * Function: adjust_bank_balance(double bank_balance, double wager_amount, int add_or_sub)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function determines if the wager is added or subtracted from bank balance
 * Input parameters: double bank_balance, double wager_amount, int add_or_sub
 * Returns: balance 
 * Preconditions: Must have previous bank balance and wager, as well as point outcome of roll
 * Postconditions: Updated bank balance 
 *************************************************************/
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_sub)
{
	double balance = bank_balance;
	if (add_or_sub == 1)
	{
		balance = bank_balance + wager_amount;
	}
	else if (add_or_sub == 0)
	{
		balance = bank_balance - wager_amount;
	}
	return balance;
}


/*************************************************************
 * Function: chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance,
	double current_bank_balance)
 * Date Created: Feb. 20, 2023
 * Date Last Modified: Feb. 28, 2023
 * Description: This function prints a specific message based on set conditions
 * Input parameters: int number_rolls, int win_loss_neither, double initial_bank_balance,
	int message
 * Returns: NA
 * Preconditions: Roll count, whether it was a win or loss, intital and int message
 * Postconditions: Message printed to screen
 *************************************************************/
void chatter_messages(int number_rolls, int point, double initial_bank_balance, int message)
{
	if(message == 1)
	{
		if (number_rolls == 3)
		{
			printf("This is getting interesting\n");
			system("pause");
			system("cls");
		}
	}
	if (message == 2)
	{
		if (number_rolls == 5)
		{
			printf("I can't believe this is still going on!\n");
			system("pause");
			system("cls");
		}
	}
	if (message == 3)
	{
		if (initial_bank_balance <= 50)
		{
			printf("You can risk more than that\n");
		}
	}
	if (message == 4)
	{
		if (initial_bank_balance >= 100)
		{
			printf("We got a real gambler\n");
		}
	}
	if (message == 5)
	{
		if (point == 1)
		{
			printf("Didn't expect you to win\n");
		}
	}
	if (message == 6)
	{
		if (point == 0)
		{
			printf("Better luck next time!\n");
		}
	}
} // end of functions 