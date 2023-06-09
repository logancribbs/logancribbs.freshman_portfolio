#include "battle.h"

void welcome_screen(void)
{
	printf("Welcome to Battleship!\n");
	system("pause");
	system("cls");
	printf("You are needed on the control bridge right away!\n");
	system("pause");
	system("cls");
}

void clear(void)
{
	system("pause");
	system("cls");
}

void print_rules(void)
{
	printf("1. This is a 2 player game\n2. Player 1 is you, Player 2 is the computer\n3. You will start by either manueling placing your ships or randomly generating their positions\n4. The first to go will be randomly selected\n5. Once the order is decided, you will take turns choosing points to shoot\n6. If they have a ship there you got a hit, if not you missed\n7. The game will continue unitl one player loses their fleet\n8. Hits and misses will be updated in the log as well as on the game board\n");
	clear();
}

void init_board(char board[][MAX_C], int num_rows, int num_cols)
{
	int row_i = 0, col_i = 0;

	for (; row_i < num_rows; ++row_i) 
	{
		for (col_i = 0; col_i < num_cols; ++col_i) 
		{
			board[row_i][col_i] = '-';
		}
	}
}

void print_board(char board[][MAX_C], int num_rows, int num_cols)
{
	int row_i = 0, col_i = 0;

	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);

	for (; row_i < num_rows; ++row_i)
	{
		printf("%-2d", row_i);
		for (col_i = 0; col_i < num_cols; ++col_i) 
		{
			printf("%-2c", board[row_i][col_i]);
		}

		putchar('\n');
	}
}

int roll_die(int die1, int die2, int *roll1, int *roll2)
{
	printf("Roll die to see who goes first\n");
	do {
		die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;

		*roll1 = die1;
		*roll2 = die2;

		clear();
		if (*roll1 > *roll2)
		{
			printf("Player 1 roll = %d\nPlayer 2 roll = %d\n", *roll1, *roll2);
			printf("Player 1 goes first\n");

		}
		if (*roll1 < *roll2)
		{
			printf("Player 1 roll = %d\nPlayer 2 roll = %d\n", *roll1, *roll2);
			printf("Player 2 goes first\n");
		}
		if (*roll1 == *roll2)
		{
			printf("Player 1 roll = %d\nPlayer 2 roll = %d\n", *roll1, *roll2);
			printf("Roll Again\n");
		}
	} while (die1 == die2);
}

char man_or_ran(void)
{
	char choice = '\n';
	printf("Player 1, do you want to place your ships manually? [Y/N]\n");
	scanf("%c", &choice);
	
	if ((choice == 'y') || (choice == 'Y'))
	{
		printf("Understood, please place your ships\n");
	}
	if ((choice == 'n') || (choice == 'N'))
	{
		printf("Your ships will be randomly placed\n");
	}
	else 
	{
		printf("Enter a valid choice\n");
	}

	
}

int manuel_place_ships(char board[MAX_ROWS][MAX_C])
{
	int row = 0, col = 0, num = 0;

	
		char carrier[CARRIER * 2];
		printf("Place your Carrier\n");
		for (int i = 0; i < (CARRIER * 2); i += 2)
		{
			printf("Row: ");
			scanf("%d", &row);
			printf("Col: ");
			scanf("%d", &col);
			if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9))
			{
				carrier[i] = row;
				carrier[i + 1] = col;
			}
		}
		for (int i = 0; i < (CARRIER * 2); i += 2)
		{
			board[carrier[i]][carrier[i + 1]] = 'C';
		}
		clear();
		print_board(board, MAX_ROWS, MAX_C);
	
	
	// Battleship
	char battle[BATTLE * 2];
	printf("Place your Battleship\n");
	for (int i = 0; i < (BATTLE * 2); i += 2)
	{
		printf("Row: ");
		scanf("%d", &row);
		printf("Col: ");
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9))
		{
			battle[i] = row;
			battle[i + 1] = col;
		}
	}
	for (int i = 0; i < (BATTLE * 2); i += 2)
	{
		board[battle[i]][battle[i + 1]] = 'B';
	}
	clear();
	print_board(board, MAX_ROWS, MAX_C);

	// Crusier 
	char crusier[CRUISER * 2];
	printf("Place your Crusier\n");
	for (int i = 0; i < (CRUISER * 2); i += 2)
	{
		printf("Row: ");
		scanf("%d", &row);
		printf("Col: ");
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9))
		{
			crusier[i] = row;
			crusier[i + 1] = col;
		}
	}
	for (int i = 0; i < (CRUISER * 2); i += 2)
	{
		board[crusier[i]][crusier[i + 1]] = 'R';
	}
	clear();
	print_board(board, MAX_ROWS, MAX_C);

	//Sub
	char sub[SUB * 2];
	printf("Place your Submarine\n");
	for (int i = 0; i < (SUB * 2); i += 2)
	{
		printf("Row: ");
		scanf("%d", &row);
		printf("Col: ");
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9))
		{
			sub[i] = row;
			sub[i + 1] = col;
		}
	}
	for (int i = 0; i < (SUB * 2); i += 2)
	{
		board[sub[i]][sub[i + 1]] = 'S';
	}
	clear();
	print_board(board, MAX_ROWS, MAX_C);


	// Destroyer 
	char des[DESTROYER * 2];
	printf("Place your Destroyer\n");
	for (int i = 0; i < (DESTROYER * 2); i += 2)
	{
		printf("Row: ");
		scanf("%d", &row);
		printf("Col: ");
		scanf("%d", &col);
		if ((row >= 0 && row <= 9) && (col >= 0 && col <= 9))
		{
			des[i] = row;
			des[i + 1] = col;
		}
	}
	for (int i = 0; i < (DESTROYER * 2); i += 2)
	{
		board[des[i]][des[i + 1]] = 'D';
	}
	clear();
	print_board(board, MAX_ROWS, MAX_C);

}