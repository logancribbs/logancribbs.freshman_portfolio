#include "Header.h" // including header


// start of program
int main(void) 
{
	// for use of random generated numbers 
	srand((unsigned int)time(NULL));

	// char variables and arrays  
	char p1_board[NUM_ROWS][NUM_COLS] = { {'\0'} }, p2_board[NUM_ROWS][NUM_COLS] = { { '\0'} }, p2_show[NUM_ROWS][NUM_COLS] = { { '\0' } }, ships[5] = { 'C', 'B', 'S', 'R', 'D' };
	char hit_ship = '\0';

	// int variables and arrays 
	int tried[NUM_ROWS][NUM_COLS] = { { 0 } };
	int lengths[5] = { CARRIER, BATTLESHIP, SUB, CRUISER, DESTROYER };
	int dir = HORI, r_start = 0, c_start = 0, choice = 0, x = 0, y = 0, hit = 0, sunk = 0, gen = 1, option = 0, game = 0;

	// got idea to use bool library from Portfolio Courses on Youtube
	bool place = false, won = false, lost = false;
	
	// arrays using structs for each players stats
	Stats p1 = { 0, 0, 0, 0.0 };
	Stats p2 = { 0, 0, 0, 0.0 };
	
	// opening file for writing 
	FILE* outfile = NULL;
	outfile = fopen("battleship.log", "w");

	// initalizing the players boards
	init_board(p1_board, NUM_ROWS, NUM_COLS);
	init_board(p2_board, NUM_ROWS, NUM_COLS);
	init_board(p2_show, NUM_ROWS, NUM_COLS);

	// display welcome screen 
	welcome_screen();

	do {

		while (game == 0)
		{
			// printing starting menu
			printf("1. Start Game\n2. Rules of the Game\n3. Exit\n");
			scanf("%d", &option);
			clear();

			if(option == 1)
			{
				// start of the game 
				clear();
				printf("Would you like to manually place your ships, or randomly generate a board?\n");
				printf("1. Randomly generate board.\n");
				printf("2. Manually place ships.\n");
				do 
				{
					scanf("%d", &choice);
				} while (!(choice == 1 || choice == 2));
				if (choice == 1)
				{
					// randomly generating the ships onto the board 
					for (int i = 0; i < 5; i++)
					{
						place = true;
						dir = gen_dir();
						do
						{
							gen_sp(dir, lengths[i], &r_start, &c_start);
							if (detect_col(p1_board, dir, lengths[i], r_start, c_start) == 1)
							{
								place_ship(p1_board, NUM_ROWS, NUM_COLS, lengths[i], ships[i], dir, r_start, c_start);
								place = false;
							}
						} while (place);
					}
				}
				else
				{
					// manually place ships on board
					man_place(p1_board);
				}
				// print player 1 board
				printf("YOUR BOARD:\n");
				print_board(p1_board, NUM_ROWS, NUM_COLS);
				system("pause");

				// randomly generate computers ships to the board
				for (int i = 0; i < 5; i++)
				{
					place = true;
					dir = gen_dir();
					do {
						gen_sp(dir, lengths[i], &r_start, &c_start);
						if (detect_col(p2_board, dir, lengths[i], r_start, c_start) == true)
						{
							place_ship(p2_board, NUM_ROWS, NUM_COLS, lengths[i], ships[i], dir, r_start, c_start);
							place = false;
						}
					} while (place);
				}

				// determines who goes first 
				int current = go_first();
				// player 1 goes first 
				if (current == 0)
				{
					printf("Player 1 will go first.\n");
				}
				else if (current == 1)
				{
					printf("Player 2 will go first.\n");
				}
				// clear the screen
				clear();
				// initialize computer parallel array
				for (int i = 0; i < NUM_ROWS; i++)
				{
					for (int j = 0; j < NUM_COLS; j++)
					{
						tried[i][j] = 0;
					}
				}

				while (!won || !lost)
				{
					switch (current)
					{
					case 0:
						// runs through player 1 turn and determines win or loss.
						printf("Your Board:\n");
						// print board 
						print_board(p1_board, NUM_ROWS, NUM_COLS);
						printf("\nComputer's Board:\n");
						// print board
						print_board(p2_show, NUM_ROWS, NUM_COLS);
						// shot selection
						printf("Enter a target: ");
						scanf("%d %d", &x, &y);
						// shot total updated 
						p1.total++;
						// check for hit and sink
						hit = check_shot(p2_board, x, y, &hit_ship);
						sunk = check_sunk(p2_board, hit_ship);
						// update player 2 board 
						board_update(p2_board, x, y, hit);
						board_update(p2_show, x, y, hit);
						if (hit)
						{
							// adds to hit total
							p1.hits++;
							printf("Hit!\n");
							if (sunk)
							{
								// says which ship has been sunk
								printf("Computer ship %c has been sunk!\n", hit_ship);
							}
						}
						else
						{
							// adds to miss total
							p1.miss++;
							printf("Miss!\n");
						}
						// clears the screen
						clear();
						// updates move to log file 
						output_move(outfile, current, x, y, hit, sunk);
						if (win(p2_board))
						{
							// win
							printf("You won!\n");
							system("pause");
							won = 1;
							// go to breakout 
							goto breakout;
						}
						current = 1;
						break;
					case 1: // runs through the player 2 turn and determines win or loss 
						gen = 1;
						while (gen)
						{
							// determines if move has already been played 
							x = rand() % 10;
							y = rand() % 10;
							if (tried[x][y] != 1)
							{
								tried[x][y] = 1;
								gen = 0;
							}
						}
						p2.total++;
						// check shot and sink
						hit = check_shot(p1_board, x, y, &hit_ship);
						sunk = check_sunk(p1_board, hit_ship);
						if (hit)
						{
							// adds total hits 
							p2.hits++;
							printf("Computer turn: %d, %d, hit!\n", x, y);
							if (sunk)
							{
								// declares your ship has been sunk
								printf("Computer turn: %d, %d. Your ship was sunk!\n", x, y);
							}
						}
						else
						{
							// adds total miss 
							p2.miss++;
							printf("Computer turn: %d, %d, miss.\n", x, y);
						}
						// clears the screen
						clear();
						// updates player 1 board 
						board_update(p1_board, x, y, hit);
						if (win(p1_board))
						{
							// win
							printf("You lost!\n");
							system("pause");
							lost = 1;
							// go to breakout 
							goto breakout;
						}
						// update move to log file 
						output_move(outfile, current, x, y, hit, sunk);
						current = 0;
						break;
					}
				}
			breakout: // placeholder , use of breakout was from Portfolio Courses on Youtube 
				// end of game totals up stats for the log file
				printf("Check battlelog for stats\n");
				// determines hit/miss ratio
				p1.hit_miss = ((double)p1.hits / p1.total) * 100;
				p2.hit_miss = ((double)p2.hits / p2.total) * 100;
				// sends stats to log file 
				output_stats(outfile, p1, p2);
				// log file closed 
				fclose(outfile);
				// clears the screen 
				clear();
				// return to starting menu
				game = 0;
			}
			// prints the rules of the game
			if (option == 2)
			{
				print_rules();
			}
			// exits the game
			if (option == 3)
			{
				return 0;
			}

		}
	}while (option > 1 && option < 4);

	// end of program
	return 0; 
}