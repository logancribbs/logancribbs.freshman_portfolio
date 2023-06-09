#include "pa4.h" // inlcuding header


int main(void) // begiining of program
{


	// calling srand to be able to use rand
	srand((unsigned int)time(NULL));

	// int variables
	int game = 0, option = 0, die1 = 0, die2 = 0,
		sum_roll = 0, point = 0, total = 0, roll = 1, valid = 0, message = 0;

	// double variables
	double wager = 0.0, bank_balance = 0.0, new_balance = 0.0, total_balance = 0.0;


	// welcome screen 
	printf("Welcome to Craps!\n");

	// pauses the screen then clears when any key is pressed
	system("pause");
	system("cls");
	// used to run rand 
	srand((unsigned int)time(NULL));

	do
	{ // broke the segments of the game down into pieces that loop back to each other based on output.
		while (game == 0)
		{
			// game = 0, displays the starting menu and accepts an option selection
			printf("1. Show Rules\n2. Set Balance\n3. Play Game\n4. Check Balance\n5. Exit Game\n");
			scanf("%d", &option);
			// pauses the screen then clears when any key is pressed
			system("pause");
			system("cls");
			// option input
			if (option == 1)
			{
				// prints game rules 
				print_game_rules();
				// brings user back to starting menu
				game = 0;
			}
			// option input
			if (option == 2)
			{
				// prompts for bank balance, stores user input
				bank_balance = get_bank_balance();
				// displays message if balance is set less or equal to 50
				chatter_messages(roll, point, bank_balance, 3);
				// displays message if balance is set greater than or equal to 100
				chatter_messages(roll, point, bank_balance, 4);
				// pauses then clears the screen
				system("pause");
				system("cls");
			}
			// option input 
			if (option == 3)
			{
				// starts the game 
				game = 2;
			}
			// option input 
			if (option == 4)
			{
				// prints the current balance
				printf("Balance: %.2lf\n", bank_balance);
				// pauses the screen then clears when any key is pressed
				system("pause");
				system("cls");
				// returns to the starting menu
				game = 0;
			}
			// option input
			if (option == 5)
			{
				// exits the game 
				return 0;
			}
		}
		// runs the game 
		while (game == 2)
		{
			
				// prompts for wager amount, stores the value 
				wager = get_wager_amount();
				// checks to make sure wager does not exceed bank balance
				valid = check_wager_amount(wager, bank_balance);
				// wager not valid 
				if (valid == 0)
				{
					// prompt for new wager
					printf("Insufficent Funds\nPlace a New Wager\nReturning to Menu\n");
					// returns to starting menu
					game = 0;
				}
				// pauses then clears the screen
				system("pause");
				system("cls");
				// wager is valid
				if (valid == 1)
				{	// randomly produces 2 numbers between 1-6
					die1 = roll_die();
					die2 = roll_die();
					// adds the total of 2 rolls
					sum_roll = sum_of_dice(die1, die2);
					// sets total to sum_roll for later use
					total = sum_roll;
					// determines if win, loss, or playing for a point
					point = is_win_loss_or_point(sum_roll);
					// pauses then clears the screen 
					system("pause");
					system("cls");
					// win
					if (point == 1)
					{
						// adds wager to bank balance 
						bank_balance = adjust_bank_balance(bank_balance, wager, point);
						// displays message if point = 1
						chatter_messages(roll, point, bank_balance, 5);
						// returns to starting menu
						game = 0;
					}
					// loss
					if (point == 0)
					{
						// subracts wager from bank balance
						bank_balance = adjust_bank_balance(bank_balance, wager, point);
						// displays message if point = 0
						chatter_messages(roll, point, bank_balance, 3);
						// bank balance 0 
						if (bank_balance <= 0)
						{
							// print statement
							printf("You are out of money, please update your balance\n");
							// set balance to 0
							bank_balance = 0;
						}
						// returns to starting menu
						game = 0;
					}
					// playing for point
					if (point == -1)
					{
						// playing for point
						while (point == -1)
						{
							// prompts another roll
							printf("Roll Again\n");
							// pauses the screen then clears when any key is pressed
							system("pause");
							system("cls");
							// adds 1 to the roll count 
							roll++;
							// displays message if rolls = 3
							chatter_messages(roll, point, bank_balance, 1);
							// displays message if rolls = 5
							chatter_messages(roll, point, bank_balance, 2);
							// rolls 2 dice for random number between 1-6
							die1 = roll_die();
							die2 = roll_die();
							// adds sum of the 2 rolled numbers
							sum_roll = sum_of_dice(die1, die2);
							// compares sum or roll 1 to next rolls to determine outcome
							point = is_point_loss_or_neither(sum_roll, total);
							// win
							if (point == 1)
							{
								// adds wager to bank balance
								bank_balance = adjust_bank_balance(bank_balance, wager, point);
								// displays message if point = 1
								chatter_messages(roll, 1, bank_balance, 5);
								// set roll back to 0
								roll = 0;
								// return to starting menu
								game = 0;
							}
							// loss
							if (point == 0)
							{
								//subtracts wager from bank balance
								bank_balance = adjust_bank_balance(bank_balance, wager, point);
								// dispalys message if point = 0
								chatter_messages(roll, 0, bank_balance, 6);
								// if balance is 0
								if (bank_balance <= 0)
								{
									// displays message 
									printf("You are out of money, please update your balance\n");
									//sets balance = 0
									bank_balance = 0;
									// sets roll back to 0
									roll = 0;
								}
								// returns to starting menu
								game = 0;
							}
						}



						// pauses the screen then clears when any key is pressed
						system("pause");
						system("cls");
					}
				}
		}

	}while (option > 1 || option < 5); // only works if option input is b/w 1-5
	return 0; // end of program
}