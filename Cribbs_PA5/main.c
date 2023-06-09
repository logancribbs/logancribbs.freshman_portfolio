#include "header.h" // including header

// start of program
int main(void)
{
	// variables for whole game 
	int game = 0, option = 0, turn = 1;
	// char variable 
	char roll = '\0';
	// variables for player 1
	int up_p1[7] = { 0 }, low_p1[8] = { 0 }, p1_check[14] = { -1 }, p1_score = 0, dice1[6] = { 0 }, die_val1[7] = { 0 };
	// variable for player 2
	int up_p2[7] = { 0 }, low_p2[8] = { 0 }, p2_check[14] = { -1 }, p2_score = 0, dice2[6] = { 0 }, die_val2[7] = { 0 };

	// print welcome scrren
	printf("Lets Play Yahtzee!!!\n");
	// clear 
	clear();
	// needed for dice roll
	srand((unsigned int)time(NULL));

	do
	{
		while (game == 0)
		{
			// print starting menu
			printf("1. Game Rules\n2. Example Score Card\n3. Play Game\n4. Exit Game\n");
			// get user input 
			scanf("%d", &option);
			// clear 
			clear();
			if (option == 1)
			{
				// prints the rules of the game 
				print_rules();
				// returns to starting menu
				game = 0;
			}
			if (option == 2)
			{
				// prvides examples of how the game is scored 
				ex_scorecard();
				// returns to starting menu
				game = 0;
			}
			if (option == 3)
			{
				// start of game, plays through for 13 rounds 
				while (turn < 14)
				{
					// print what turn your on
					printf("Turn %d\n", turn);
					// which player is going 
					printf("Player 1\n");
					// shows total acore
					printf("Total Score: %d\n", p1_score);
					// which dice to keep
					check_roll(dice1);
					// get the dice
					get_num_die(dice1, die_val1);
					// scores the round
					score_roll(dice1, die_val1, up_p1, low_p1, p1_check);
					// adds to total
					p1_score = sum_array(up_p1, 7) + sum_array(low_p1, 8);
					// clear screen
					clear();
					// print what turn your on
					printf("Turn %d\n", turn);
					// which player is going 
					printf("Player 2\n");
					// adds to total
					printf("Total Score: %d\n", p2_score);
					// which dice to keep
					check_roll(dice2);
					// get the dice
					get_num_die(dice2, die_val2);
					// scores the round
					score_roll(dice2, die_val2, up_p2, low_p2, p2_check);
					// adds to total
					p2_score = sum_array(up_p2, 7) + sum_array(low_p2, 8);
					// clears the screen
					clear();
					// adds 1 to turn
					++turn;
				}

				if (p1_score > p2_score)
				{
					// if player 1 wins 
					printf("Player 1 Score: %d\nPlayer 2 Score: %d", p1_score, p2_score);
					printf("Player 1 wins!\n");
					clear();
					// returns to starting menu
					game = 0;
				}
				if (p1_score < p2_score)
				{
					// if player 2 wins 
					printf("Player 1 Score: %d\nPlayer 2 Score: %d", p1_score, p2_score);
					printf("Player 2 wins!\n");
					clear();
					// returns to starting menu
					game = 0;
				}
				if (p1_score == p2_score)
				{
					// if they tie
					printf("Player 1 Score: %d\nPlayer 2 Score: %d", p1_score, p2_score);
					printf("I have no idea how you pulled this off!\n");
					clear();
					// returns to starting menu
					game = 0;
				}
				else
				{
					// the game lost the scores 
					printf("Something went wrong\n");
					clear();
					// returns to the starting menu
					game = 0;
				}
				
				
			}
			if (option == 4)
			{
				// exiting the game 
				system("cls");
				printf("Thanks for playing!");
				return 0;
			}
		}
		
	} while (option > 1 || option < 4);
	
	// end of the program
	return 0;
}