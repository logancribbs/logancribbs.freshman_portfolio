#include "header.h"

// start of functions 

/*************************************************************
 * Function: clear(void)
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function pauses and clears the screen
 * Input parameters: NA
 * Returns: NA
 * Preconditions: NA
 * Postconditions: Screen is cleared 
 *************************************************************/
void clear(void)
{
	system("pause");
	system("cls");
}

/*************************************************************
 * Function:  print_rules(void)
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function prints the rules of the game
 * Input parameters: NA
 * Returns: NA
 * Preconditions: NA
 * Postconditions: The players understands the rules of the game 
 *************************************************************/
void print_rules(void)
{
	printf("Game Rules\n");
	printf("The scorecard used for Yahtzee is composed of two sections.\nA upper section and a lower section.\nA total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\nThe upper section consists of boxes that are scored by summing\nthe value of the dice matching the faces of the box.\nIf a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\nOnce a player has chosen to score a box, it may not be changed \nand the combination is no longer in play for future rounds.\nIf the sum of the scores in the upper section is greater than or equal to 63, \nthen 35 more points are added to the players overall score as a bonus.\n");
	system("pause");
	system("cls");
}

/*************************************************************
 * Function: ex_scorecard(void)
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function prints an example of how the game is scored 
 * Input parameters: NA
 * Returns: NA
 * Preconditions: NA
 * Postconditions: Player understands scoring 
 *************************************************************/
void ex_scorecard(void)
{
	printf("Sum-of-#'s: Add up total of same face die value. Can use once for all face values.(ex. 3 dice that roll 2 = 6).\nThree-of-a-kind: Three dice with the same face Sum of all face values on the 5 dice.\nFour-of-a-kind: Four dice with the same face Sum of all face values on the 5 dice.\nFull house: One pair and a three-of-a-kind = 25.\nSmall straight: A sequence of four dice = 30.\nLarge straight: A sequence of five dice = 40.\nYahtzee(think five-of-a-kind):Five dice with the same face = 50.\nChance: May be used for any sequence of dice, this is the catch all combination = Sum of all face values on the 5 dice.\n");
	system("pause");
	system("cls");
}

/*************************************************************
 * Function: roll_dice(int dice[])
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function rolls the dice and sorts them
 * Input parameters: int dice[]
 * Returns: NA
 * Preconditions: NA
 * Postconditions: Dice rolled and sorted 
 *************************************************************/
int roll_dice(int dice[])
{
	for (int i = 0; i < 6; i++) 
	{
		dice[i] = rand() % 6 + 1;
	}
	sort(dice, 6);
}

/*************************************************************
 * Function: rget_num_die(int dice[], int die_val[])
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function stores the values of the dice into an array
 * Input parameters: int dice[], int die_val[]
 * Returns: Dice value into array
 * Preconditions: Dice have to be rolled 
 * Postconditions: Value of dice are saved 
 *************************************************************/
void get_num_die(int dice[], int die_val[]) 
{
    for (int i = 1; i < 6; i++) 
    {
        int j = dice[i];
        die_val[j] += 1;
    }
}

/*************************************************************
 * Function: sort(int arr[], int size)
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function sorts an array
 * Input parameters: int arr[], int size
 * Returns: NA
 * Preconditions: int arr[], int size
 * Postconditions: Array assorted by value
 * Cannot find the original URL but got from a website, I believe it was StackOverflow
 *************************************************************/
void sort(int arr[], int size) 
{
	int temp = 0;
	for (int i = 0; i < (size - 1); i++)
    {
		for (int j = 0; j < (size - i - 1); j++) 
		{
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*************************************************************
 * Function: int array[], int size
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function adds together an array
 * Input parameters: int array[], int size
 * Returns: sum
 * Preconditions: int array[], int size
 * Postconditions: Array totaled 
 *************************************************************/
int sum_array(int array[], int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

/*************************************************************
 * Function: int dice[], int count
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function prints the result of the dice roll
 * Input parameters: int dice[], int count
 * Returns: rand() NA
 * Preconditions: int dice[], int count
 * Postconditions: Results of roll are printed to the screen 
 *************************************************************/
void print_die(int dice[], int count) 
{
	printf("Die values of roll %d: ", count);
	for (int i = 1; i < DIE_VALUE; i++) {
		printf("%d ", dice[i]);
	}
	printf("\n");
}

/*************************************************************
 * Function: next_roll(char* next_roll_ptr)
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function checks if you want to roll again or are satified with first roll
 * Input parameters: char* next_roll_ptr
 * Returns: NA
 * Preconditions: First roll has to be made
 * Postconditions: Another roll or going to scoring option
 *************************************************************/
void next_roll(char* next_roll_ptr)
{

	char next_roll = '\0';
	printf("Another roll? [Y/N]: ");
	scanf(" %c", &next_roll);
	if (next_roll == 'y' || next_roll == 'Y')
	{
	*next_roll_ptr = 'Y';
	}
	else
	{
	*next_roll_ptr = '\0';
	}
}

/*************************************************************
 * Function: check_roll(int dice[]) 
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function checks which dice you wish to keep if you want to roll again.
 * Input parameters: int dice[]
 * Returns: Nothing
 * Preconditions: Dice have to have been rolled
 * Postconditions: Which dice are being kept
 *************************************************************/
void check_roll(int dice[]) 
{
    int die1 = 0, die2 = 0, die3 = 0, die4 = 0, die5 = 0, keep = 0, count = 1;
    char roll_again = '\0';

    roll_dice(dice);
    print_die(dice, count);
    next_roll(&roll_again);
    count += 1;

    do {
        if (roll_again == '\0') 
        {
            break;
        }
        do 
        {
            printf("Dice to keep? ");
            scanf("%d", &keep);
        } while (keep < 0 || keep > 5);

        switch (keep) 
        {
        case 0: roll_dice(dice);
            break;

        case 1: printf("Dice to keep? (1-5, left to right): ");    
            scanf("%d", &die1);
            for (int i = 1; i < 6; i++) 
            {
                if (i == die1) 
                {
                    continue;
                }
                else {
                    dice[i] = rand() % 6 + 1;
                }
            }
            break;

        case 2: printf("Dice to keep? (1-5): ");
            scanf("%d%d", &die1, &die2);
            for (int i = 1; i < 6; i++) 
            {
                if (i == die1 || i == die2) 
                {
                    continue;
                }
                else {
                    dice[i] = rand() % 6 + 1;
                }
            }
            break;

        case 3: printf("Dice to keep? (1-5): ");
            scanf("%d%d%d", &die1, &die2, &die3);
            for (int i = 1; i < 6; i++) 
            {
                if (i == die1 || i == die2 || i == die3)
                {
                    continue;
                }
                else {
                    dice[i] = rand() % 6 + 1;
                }
            }
            break;

        case 4: printf("Dice to keep? (1-5): ");
            scanf("%d%d%d%d", &die1, &die2, &die3, &die4);
            for (int i = 1; i < 6; i++) 
            {
                if (i == die1 || i == die2 || i == die3 || i == die4)
                {
                    continue;
                }
                else
                {
                    dice[i] = rand() % 6 + 1;
                }
            }
            break;

        case 5: break;

        }
        print_die(dice, count);
        if (count < 3) {
            next_roll(&roll_again);
        }
        count += 1;
    } while (roll_again == 'Y' && count <= 3);

}


/*************************************************************
 * Function: score_type(int* combo_choice, int check_combo[])
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function prompts for a combo choice and the saves user option
 * Input parameters: int* combo_choice, int check_combo[]
 * Returns: combo_choice_ptr
 * Preconditions: int* combo_choice, int check_combo[]
 * Postconditions: Scoring option has been chosen
 *************************************************************/
    void score_type(int* combo_choice, int check_combo[])
    {
       
        int combo = 0;
        printf("Enter combo choice:\n");
        printf("1: Sum of ones   2: Sum of twos\n");
        printf("3: Sum of threes 4: Sum of fours\n");
        printf("5: Sum of fives  6: Sum of sixes\n");
        printf("7: 3 of a kind   8: 4 of a kind\n");
        printf("9: Full house   10: Small straight\n");
        printf("11: Big straight 12: Yahtzee\n");
        printf("13: Chance\n");
     while ((combo < 1 || combo > 13) || check_combo[combo] == 1)
     {
            printf("Enter your combo choice:\n ");
            scanf("%d", &combo);
     }
        check_combo[combo] = 1;
        *combo_choice = combo;

    }

 /*************************************************************
 * Function: three_kind(int dice[], int die_val[], int low[])
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function scores a 3 of a kind if valid
 * Input parameters: int dice[], int die_val[], int low[]
 * Returns: Array value
 * Preconditions: int dice[], int die_val[], int low[]
 * Postconditions: Total score updated 
 *************************************************************/
    void three_kind(int dice[], int die_val[], int low[]) 
    {
        int is_three = 0;
        for (int i = NUM_DIE - 1; i > 0; i--) 
        {
            if (die_val[i] == 3)
            {
                is_three += 1;
                break;
            }
        }
        if (is_three >= 1) 
        {
            low[1] = sum_array(dice, DIE_VALUE);
        }
        else 
        {
            low[1] = 0;
        }
    }

   
 /*************************************************************
 * Function: four_kind(int dice[], int die_val[], int low[])
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function scores a 4 of a kind if valid.
 * Input parameters: int dice[], int die_val[], int low[]
 * Returns: Array value
 * Preconditions: int dice[], int die_val[], int low[]
 * Postconditions: Total score updated
 *************************************************************/
    void four_kind(int dice[], int die_val[], int low[]) 
    {
        int is_four = 0;
        for (int i = NUM_DIE - 1; i > 0; i--) 
        {
            if (die_val[i] == 4) 
            {
                is_four += 1;
                break;
            }
        }
        if (is_four >= 1) 
        {
            low[2] = sum_array(dice, DIE_VALUE);
        }
        else 
        {
            low[2] = 0;
        }
    }

    
 /*************************************************************
 * Function: full_house(int die_val[], int low[]) 
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function scores a full house if valid.
 * Input parameters: int die_val[], int low[]
 * Returns: Array value
 * Preconditions: int die_val[], int low[]
 * Postconditions: Total score updated 
 *************************************************************/
    void full_house(int die_val[], int low[]) 
    {
        int three = 0, pair = 0;
        for (int i = 1; i < NUM_DIE; i++) 
        {
            if (die_val[i] == 3)
            {
                three += 1;
            }
            else if (die_val[i] == 2) 
            {
                pair += 1;
            }
        }
        if (three == 1 && pair == 1) 
        {
            low[3] = 25;
        }
        else 
        {
            low[3] = 0;
        }
    }

   
/*************************************************************
* Function: small_st(int die_val[], int low[])
* Date Created: Mar. 15, 2023
* Date Last Modified: Mar. 22, 2023
* Description: This function scores a small straight if valid.
* Input parameters: int die_val[], int low[]
* Returns: Array value
* Preconditions: int die_val[], int low[]
* Postconditions: Total score updated 
*************************************************************/
    void small_st(int die_val[], int low[]) 
    {
        int count = 0;
        for (int i = 1; i < NUM_DIE; i++) 
        {
            if (count == 4) 
            {
                break;
            }
            if (die_val[i] >= 1) 
            {
                count += 1;
            }
            else if (die_val[i] == 0) 
            {
                count = 0;
            }
        }
        if (count == 4) 
        {
            low[4] = 30;
        }
        else 
        {
            low[4] = 0;
        }
    }

 /*************************************************************
 * Function: roll_die(void)
 * Date Created: Mar. 15, 2023
 * Date Last Modified: Mar. 22, 2023
 * Description: This function produces a random number between 1-6
 * Input parameters: NA
 * Returns: rand() % 6 + 1
 * Preconditions: NA
 * Postconditions: Random number b/w 1-6
 *************************************************************/
    void large_st(int die_val[], int low[]) 
    {
        int count = 0;
        for (int i = 1; i < NUM_DIE; i++) 
        {
            if (count == 5) 
            {
                break;
            }
            if (die_val[i] == 1) 
            {
                count += 1;
            }
            else if (die_val[i] == 0) 
            {
                count = 0;
            }
        }
        if (count == 5) 
        {
            low[5] = 40;
        }
        else 
        {
            low[5] = 0;
        }
    }

/*************************************************************
* Function: yahtzee(int die_val[], int low[])
* Date Created: Mar. 15, 2023
* Date Last Modified: Mar. 22, 2023
* Description: This function scores a yahtzee if valid.
* Input parameters: int die_val[], int low[]
* Returns: rand() Array value
* Preconditions: int die_val[], int low[]
* Postconditions: Updated score
*************************************************************/
    void yahtzee(int die_val[], int low[])
    {
        int yahtzee = 0;
        for (int i = NUM_DIE - 1; i > 0; i--) 
        {
            if (die_val[i] == 5) 
            {
                yahtzee += 1;
                break;
            }
        }
        if (yahtzee >= 1) 
        {
            low[6] = 50;
        }
        else 
        {
            low[6] = 0;
        }
    }


 /*************************************************************
* Function: score_roll(int dice[], int num_val[], int up[], int low[], int check_combo[])
* Date Created: Mar. 15, 2023
* Date Last Modified: Mar. 22, 2023
* Description: This function scores the turn of the player by the scoring choice they chose.
* Input parameters: int dice[], int num_val[], int up[], int low[], int check_combo[]
* Returns: Array value
* Preconditions: int dice[], int num_val[], int up[], int low[], int check_combo[]
* Postconditions: Scores the choice
*************************************************************/
    void score_roll(int dice[], int num_val[], int up[], int low[], int check_combo[])
    {
        int combo = 0;
        score_type(&combo, check_combo);

            switch(combo)
            {
            case 1: up[1] = num_val[1];
                check_combo[1] = 1;
                printf("Score: %d\n", up[1]);
                break;

            case 2: up[2] = num_val[2] * 2;
                check_combo[2] = 1;
                printf("Score: %d\n", up[2]);
                break;

            case 3: up[3] = num_val[3] * 3;
                check_combo[3] = 1;
                printf("Score: %d\n", up[3]);
                break;

            case 4: up[4] = num_val[4] * 4;
                check_combo[4] = 1;
                printf("Score: %d\n", up[4]);
                break;

            case 5: up[5] = num_val[5] * 5;
                check_combo[5] = 1;
                printf("Score: %d\n", up[5]);
                break;

            case 6: up[6] = num_val[6] * 6;
                check_combo[6] = 1;
                printf("Score: %d\n", up[6]);
                break;

            case 7: three_kind(dice, num_val, low);
                check_combo[7] = 1;
                printf("Score: %d\n", low[1]);
                break;

            case 8: four_kind(dice, num_val, low);
                check_combo[8] = 1;
                printf("Score: %d\n", low[2]);
                break;

            case 9: full_house(num_val, low);
                check_combo[9] = 1;
                printf("Score: %d\n", low[3]);
                break;

            case 10: small_st(num_val, low);
                check_combo[10] = 1;
                printf("Score: %d\n", low[4]);
                break;

            case 11: large_st(num_val, low);
                check_combo[11] = 1;
                printf("Score: %d\n", low[5]);
                break;

            case 12: yahtzee(num_val, low);
                check_combo[12] = 1;
                printf("Score: %d\n", low[6]);
                break;

            case 13: low[7] = sum_array(dice, DIE_VALUE);
                check_combo[13] = 1;
                printf("Score: %d\n", low[7]);
                break;

            }
    }

    // end of functions 