#include "Header.h" // including header


//start of functions 

/*************************************************************
 * Function: clear(void)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function pauses and clears the screen.
 * Input parameters: 
 * Returns: 
 * Preconditions: 
 * Postconditions: Screen cleared.
 *************************************************************/
void clear(void)
{
	system("pause");
	system("cls");
}


/*************************************************************
 * Function: welcome_screen(void)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function prints the welcome screen to the game.
 * Input parameters: 
 * Returns: 
 * Preconditions:
 * Postconditions: Welcome screen displayed.
 *************************************************************/
void welcome_screen(void)
{
	printf("Welcome to Battleship!\n");
	clear();
	printf("You are needed on the control bridge right away!\n");
	clear();
}


/*************************************************************
 * Function: print_rules(void)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function prints the rules of the game.
 * Input parameters: 
 * Returns: 
 * Preconditions: Rule option selected.
 * Postconditions: Returns to main menu.
 *************************************************************/
void print_rules(void)
{
	printf("1. This is a 2 player game\n2. Player 1 is you, Player 2 is the computer\n3. You will start by either manueling placing your ships or randomly generating their positions\n4. The first to go will be randomly selected\n5. Once the order is decided, you will take turns choosing points to shoot\n6. If they have a ship there you got a hit, if not you missed\n7. The game will continue unitl one player loses their fleet\n8. Hits and misses will be updated in the log as well as on the game board\n");
	clear();
}


/*************************************************************
 * Function: void init_board(char board[10][10], int rows, int cols)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function initializes the game board with a '~'.
 * Input parameters: char board[10][10], int rows, int cols
 * Returns: Game board.
 * Preconditions: 
 * Postconditions: Game board ready to be printed.
 *************************************************************/
void init_board(char board[10][10], int rows, int cols)
{
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = '~';
		}
	}
}


/*************************************************************
 * Function: print_board(char board[10][10], int rows, int cols)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function prints the game board to the screen.
 * Input parameters: char board[10][10], int rows, int cols
 * Returns: 
 * Preconditions: Must have board initialized.
 * Postconditions: Game board printed to the screen.
 *************************************************************/
void print_board(char board[10][10], int rows, int cols)
{
	for (int i = 0; i < rows; i++) 
	{
		if (i == 0) 
		{
			printf("    0  1  2  3  4  5  6  7  8  9\n");
		}
		for (int j = 0; j < cols; j++) 
		{
			if (j == 0) 
			{
				printf(" %d ", i);
			}
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}


/*************************************************************
 * Function: gen_dir(void) 
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function generates a random number to determine horizontal or vertical.
 * Input parameters: 
 * Returns: 
 * Preconditions: 
 * Postconditions: Direction determined.
 *************************************************************/
int gen_dir(void) 
{
	return rand() % 2;
}


/*************************************************************
 * Function: gen_sp(int dir, int length, int* row, int* col)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function generates the starting point for the ships based on direction.
 * Input parameters: int dir, int length, int* row, int* col
 * Returns: Coordinates for starting point.
 * Preconditions: Direction determined.
 * Postconditions: Starting point determined.
 *************************************************************/
void gen_sp(int dir, int length, int* row, int* col)
{
	if (dir == HORI)
	{
		*row = rand() % NUM_ROWS;
		*col = rand() % (NUM_COLS - length + 1);
	}
	else if (dir == VERT)
	{
		*col = rand() % NUM_COLS;
		*row = rand() % (NUM_ROWS - length + 1);
	}
}


/*************************************************************
 * Function: place_ship(char board[][NUM_COLS], int rows, int cols, int length, char ship, int dir, int r_start, int c_start)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function places the ships onto the board based on randomized direction and starting point.
 * Input parameters: char board[][NUM_COLS], int rows, int cols, int length, char ship, int dir, int r_start, int c_start
 * Returns: Ship placement.
 * Preconditions: Starting point determined.
 * Postconditions: Ships randomly placed in board.
 *************************************************************/
void place_ship(char board[][NUM_COLS], int rows, int cols, int length, char ship, int dir, int r_start, int c_start)
{
	if (dir == HORI)
	{
		for (int i = 0; i < length; i++)
		{
			board[r_start][c_start + i] = ship;
		}
	}
	else if (dir == VERT) 
	{
		for (int i = 0; i < length; i++) 
		{
			board[r_start + i][c_start] = ship;
		}
	}
}


/*************************************************************
 * Function: detect_col(char board[][NUM_COLS], int dir, int length, int row, int col)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function determines if there is a collision or not.
 * Input parameters: char board[][NUM_COLS], int dir, int length, int row, int col
 * Returns: Valid
 * Preconditions: 
 * Postconditions: Valid placement.
 *************************************************************/
int detect_col(char board[][NUM_COLS], int dir, int length, int row, int col)
{
	int valid = 0;
	if (dir == HORI)
	{
		for (int i = 0; i < length; i++) 
		{
			if (board[row][col + i] != '~') 
			{
				valid = 0;
			}
			else if (board[row][col + 1] == '~') 
			{
				valid = 1;
			}
		}
	}
	else if (dir == VERT) 
	{
		for (int i = 0; i < length; i++) 
		{
			if (board[row + i][col] != '~') 
			{
				valid = 0;
			}
			else if (board[row + i][col] == '~')
			{
				valid = 1;
			}
		}
	}
	return valid;
}


/*************************************************************
 * Function: go_first(void)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function determines who goes first.
 * Input parameters: 
 * Returns: 
 * Preconditions: 
 * Postconditions: Turn order decided
 *************************************************************/
int go_first(void)
{
	return rand() % 2;
}


/*************************************************************
 * Function:  man_place(char board[][NUM_COLS])
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function allows the player to manually place their ships on the board.
 * Input parameters: char board[][NUM_COLS]
 * Returns: 
 * Preconditions: User input.
 * Postconditions: Ships placed on the board.
 *************************************************************/
void man_place(char board[][NUM_COLS])
{
	int row = 0, col = 0, count = 0;
	int carrier_cor[CARRIER * 2] = { 0 }, battleship_cor[BATTLESHIP * 2] = { 0 }, sub_cor[SUB * 2] = { 0 }, cruiser_cor[CRUISER * 2] = { 0 }, destroyer_cor[DESTROYER * 2] = { 0 };
	
	// got the idea to use these placeholder from Portfolio Courses on Youtube 
	car:
	printf("Enter where you would like to place the carrier:\n");
	for (int i = 0; i < (CARRIER * 2); i += 2) 
	{
		printf("Row #%d: ", ++count);
		scanf("%d", &row);
		printf("Col #%d: ", count);
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9))
		{
			carrier_cor[i] = row;
			carrier_cor[i + 1] = col;
		}
		else 
		{
			printf("Invalid row or column value\n");
			goto car;
		}
	}
	if (check_place(board, carrier_cor, CARRIER) == 0) 
	{
		printf("Placement not valid, enter new location.\n");
		goto car;
	}
	for (int i = 0; i < (CARRIER * 2); i += 2) 
	{
		board[carrier_cor[i]][carrier_cor[i + 1]] = 'C';
	}
	print_board(board, NUM_ROWS, NUM_COLS);

	// placeholder
	bat:
	count = 0;
	printf("Enter where you would like to place the battleship:\n");
	for (int i = 0; i < (BATTLESHIP * 2); i += 2) 
	{
		printf("Row #%d: ", ++count);
		scanf("%d", &row);
		printf("Col #%d: ", count);
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9)) 
		{
			battleship_cor[i] = row;
			battleship_cor[i + 1] = col;
		}
		else 
		{
			printf("Invalid row or column value\n");
			goto bat;
		}
	}
	if (check_place(board, battleship_cor, BATTLESHIP) == 0) 
	{
		printf("Placement not valid, enter new location.\n");
		goto bat;
	}
	for (int i = 0; i < (BATTLESHIP * 2); i += 2) 
	{
		board[battleship_cor[i]][battleship_cor[i + 1]] = 'B';
	}
	print_board(board, NUM_ROWS, NUM_COLS);

	// placeholder
	sub:
	count = 0;
	printf("Enter where you would like to place the submarine:\n");
	for (int i = 0; i < SUB * 2; i += 2) 
	{
		printf("Row #%d: ", ++count);
		scanf("%d", &row);
		printf("Col #%d: ", count);
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9)) 
		{
			sub_cor[i] = row;
			sub_cor[i + 1] = col;
		}
		else 
		{
			printf("Invalid row or column value\n");
			goto sub;
		}
	}
	if (check_place(board, sub_cor, SUB) == 0) 
	{
		printf("Placement not valid, enter new location.\n");
		goto sub;
	}
	for (int i = 0; i < (SUB * 2); i += 2) 
	{
		board[sub_cor[i]][sub_cor[i + 1]] = 'S';
	}
	print_board(board, NUM_ROWS, NUM_COLS);

	// placeholder
	cru:
	count = 0;
	printf("Enter where you would like to place the cruiser:\n");
	for (int i = 0; i < CRUISER * 2; i += 2) 
	{
		printf("Row #%d: ", ++count);
		scanf("%d", &row);
		printf("Col #%d: ", count);
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9))
		{
			cruiser_cor[i] = row;
			cruiser_cor[i + 1] = col;
		}
		else 
		{
			printf("Invalid row or column value\n");
			goto cru;
		}
	}
	if (check_place(board, cruiser_cor, CRUISER) == 0) 
	{
		printf("Placement not valid, enter new location.\n");
		goto cru;
	}
	for (int i = 0; i < (CRUISER * 2); i += 2) 
	{
		board[cruiser_cor[i]][cruiser_cor[i + 1]] = 'R';
	}
	print_board(board, NUM_ROWS, NUM_COLS);

	// placeholder
	des:
	count = 0;
	printf("Enter where you would like to place the destroyer:\n");
	for (int i = 0; i < DESTROYER * 2; i += 2) 
	{
		printf("Row #%d: ", ++count);
		scanf("%d", &row);
		printf("Col #%d: ", count);
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9)) 
		{
			destroyer_cor[i] = row;
			destroyer_cor[i + 1] = col;
		}
		else 
		{
			printf("Invalid row or column value\n");
			goto des;
		}
	}
	if (check_place(board, destroyer_cor, DESTROYER) == 0) 
	{
		printf("Placement not valid, enter new location.\n");
		goto des;
	}
	for (int i = 0; i < (DESTROYER * 2); i += 2) 
	{
		board[destroyer_cor[i]][destroyer_cor[i + 1]] = 'D';
	}
	system("cls");
}


/*************************************************************
 * Function: check_place(char board[][NUM_COLS], int coords[], int size)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function checks to see if the placement is valid.
 * Input parameters: char board[][NUM_COLS], int coords[], int size
 * Returns: 0 or 1
 * Preconditions: User input.
 * Postconditions: Valid placement.
 *************************************************************/
int check_place(char board[][NUM_COLS], int coords[], int size)
{
	int r_valid = 1, c_valid = 1, count = 0, r_check = coords[0], c_check = coords[1], r_cor[100] = { 0 }, c_cor[100] = { 0 };

	for (int i = 0; i < size * 2; i += 2) 
	{
		r_cor[count] = coords[i];
		if (coords[i] != r_check) 
		{
			r_valid = 0;
		}
		count++;
	}
	count = 0;
	for (int i = 1; i < size * 2; i += 2) 
	{
		c_cor[count] = coords[i];
		if (coords[i] != c_check) 
		{
			c_valid = 0;
		}
		count++;
	}
	if ((r_valid && !c_valid)) 
	{
		sort(c_cor, size);
		for (int i = 1; i < size; i++) 
		{
			if ((c_cor[i] > c_cor[i - 1] + 1) || board[r_cor[i]][c_cor[i]] != '~') 
			{
				return 0;
			}
		}
		return 1;
	}
	else if ((!r_valid && c_valid))
	{
		sort(r_cor, size);
		for (int i = 1; i < size; i++) 
		{
			if ((r_cor[i] > r_cor[i - 1] + 1) || board[r_cor[i]][c_cor[i]] != '~') 
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}


/*************************************************************
 * Function: sort(int arr[], int size) 
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function sorts an array of integers into ascending order.
 * Input parameters: int arr[], int size
 * Returns: 
 * Preconditions: Array of integers. 
 * Postconditions: Sorted array.
 *************************************************************/
void sort(int arr[], int size) 
{
	int temp = 0;
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


/*************************************************************
 * Function: win(char board[][NUM_COLS]) 
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function determines a winner based on the number of ship placements.
 * Input parameters: char board[][NUM_COLS]
 * Returns: 1 if all ships have been sunk.
 * Preconditions: All ships have been hit.
 * Postconditions: Winner is determined. 
 *************************************************************/
int win(char board[][NUM_COLS]) 
{
	int count = 0;
	for (int i = 0; i < NUM_ROWS; i++) 
	{
		for (int j = 0; j < NUM_COLS; j++) 
		{
			if (board[i][j] == '*') 
			{
				count++;
			}
		}
	}
	if (count == 17) 
	{
		return 1;
	}
	return 0;
}


/*************************************************************
 * Function: check_shot(char board[][NUM_COLS], int x, int y, char* toke)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function checks if shot was hit or not.
 * Input parameters: char board[][NUM_COLS], int x, int y, char* toke
 * Returns: 1 if hit, 0 if not.
 * Preconditions: User input.
 * Postconditions: Hit or not.
 *************************************************************/
int check_shot(char board[][NUM_COLS], int x, int y, char* toke)
{
	for (int i = 0; i < NUM_ROWS; i++) 
	{
		for (int j = 0; j < NUM_COLS; j++) 
		{
			if (i == x && j == y) 
			{
				if (board[i][j] != '~') 
				{
					if (board[i][j] != 'M' || board[i][j] != '*') 
					{
						*toke = board[i][j];
					}
					return 1;
				}
			}
		}
	}
	return 0;
}


/*************************************************************
 * Function: board_update(char board[][NUM_COLS], int x, int y, int hit)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function updates the board based on the selections by the players.
 * Input parameters: char board[][NUM_COLS], int x, int y, int hit
 * Returns: 
 * Preconditions: User input.
 * Postconditions: Updated board.
 *************************************************************/
void board_update(char board[][NUM_COLS], int x, int y, int hit)
{
	for (int i = 0; i < NUM_ROWS; i++) 
	{
		for (int j = 0; j < NUM_COLS; j++) 
		{
			if (i == x && j == y) 
			{
				if (hit) 
				{
					board[i][j] = '*';
				}
				else 
				{
					board[i][j] = 'M';
				}
			}

		}
	}
}


/*************************************************************
 * Function: check_sunk(char board[][NUM_COLS], char ship)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function checks to see if a hit sunk the ship.
 * Input parameters: char board[][NUM_COLS], char ship
 * Returns: 1 if sunk, 0 if not.
 * Preconditions: User input.
 * Postconditions: If ship has been sunk or not.
 *************************************************************/
int check_sunk(char board[][NUM_COLS], char ship)
{
	int count = 0;
	for (int i = 0; i < NUM_ROWS; i++) 
	{
		for (int j = 0; j < NUM_COLS; j++) 
		{
			if (board[i][j] == ship) 
			{
				count++;
			}
		}
	}
	
	if (count == 1) 
	{
		return 1;
	}
	return 0;
}


/*************************************************************
 * Function: output_move(FILE* outfile, int player, int x, int y, int hit, int sunk)
 * Date Created: Mar. 30, 2023
 * Date Last Modified:  Apr. 10, 2023
 * Description: This function writes the moves of both players into the log file.
 * Input parameters: FILE* outfile, int player, int x, int y, int hit, int sunk
 * Returns: 
 * Preconditions: User input.
 * Postconditions: Updtes moves list in log file.
 *************************************************************/
void output_move(FILE* outfile, int player, int x, int y, int hit, int sunk)
{
	switch (player)
	{
	case 0: 
		if (hit) 
		{
			if (sunk) 
			{
				fprintf(outfile, "Player 1 shot at %d, %d. It's a hit, the enemy's ship sank!\n", x, y);
			}
			else 
			{
				fprintf(outfile, "Player 1 shot at %d, %d. It's a hit.\n", x, y);
			}
		}
		else 
		{
			fprintf(outfile, "Player 1 shot at %d, %d. You missed.\n", x, y);
		}
		break;
	case 1: 
		if (hit)
		{
			if (sunk) 
			{
				fprintf(outfile, "Computer shot at %d, %d. It's a hit, your ship was sunk!\n", x, y);
			}
			else 
			{
				fprintf(outfile, "Computer shot at %d, %d. It's a hit.\n", x, y);
			}
		}
		else 
		{
			fprintf(outfile, "Computer shot at %d, %d. They missed.\n", x, y);
		}
		break;
	}
}


/*************************************************************
 * Function: void output_stats(FILE* outfile, Stats p_1, Stats p_2)
 * Date Created: Mar. 30, 2023
 * Date Last Modified: Apr. 10, 2023
 * Description: This function writes the stats from the whole game into the log file.
 * Input parameters: (FILE* outfile, Stats p_1, Stats p_2
 * Returns: 
 * Preconditions: User input.
 * Postconditions: Stats of the game written to log file.
 *************************************************************/
void output_stats(FILE* outfile, Stats p_1, Stats p_2)
{
	fprintf(outfile, "\nPlayer One Stats:\n");
	fprintf(outfile, "Number of Hits: %d\n", p_1.hits);
	fprintf(outfile, "Number of Misses: %d\n", p_1.miss);
	fprintf(outfile, "Total Number of Shots: %d\n", p_1.total);
	fprintf(outfile, "Hit/Miss Ratio: %.2lf%%\n\n", p_1.hit_miss);
	fprintf(outfile, "Computer Stats:\n");
	fprintf(outfile, "Number of Hits: %d\n", p_2.hits);
	fprintf(outfile, "Number of Misses: %d\n", p_2.miss);
	fprintf(outfile, "Total Number of Shots: %d\n", p_2.total);
	fprintf(outfile, "Hit/Miss Ratio: %.2lf%%\n", p_2.hit_miss);
}

// end of functions 