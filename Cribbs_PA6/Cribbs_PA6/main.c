#include "battle.h"

int main(void)
{
	int rows = 0, cols = 0, option = 0, game = 0, die1 = 0, die2 = 0, roll1 = 0, roll2 = 0;
	char choice = 0;

	char p1_board[MAX_ROWS][MAX_C] = { {'-','-'} };
	char p2_board[MAX_ROWS][MAX_C] = { {'-','-'} };

	srand((unsigned int)time(NULL));



	welcome_screen();

	do{
		while (game == 0)
		{
			printf("1. Start Game\n2. Rules of the Game\n3. Exit\n");
			scanf("%d", &option);
			clear();

			if (option == 1)
			{
				init_board(p1_board, MAX_ROWS, MAX_C);
				print_board(p1_board, MAX_ROWS, MAX_C);
				choice = man_or_ran();
				manuel_place_ships(p1_board);
				roll_die(die1, die2, &roll1, &roll2);
				



				clear();
				game = 0;
			}
			if (option == 2)
			{
				print_rules();
				game = 0;	
			}
			if (option == 3)
			{
				return 0;
			}
		}
	} while (option > 1 && option < 3);





	return 0;
}