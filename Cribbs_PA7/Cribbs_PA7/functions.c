// include header 
#include "poker.h"

// start of functions

/*************************************************************
 * Function: void clear(void)
 * Description: This function pauses and then clears the screen.
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
 * Function: char_input(void)
 * Description: This function checks user input when asked to redraw.
 * Input parameters: NA
 * Returns: NA
 * Preconditions: User input.
 * Postconditions: Cards are either drawn or not.
 *************************************************************/
char char_input(void)
{
	char input = '\0';
	scanf(" %c", &input);
	input = toupper(input);
	return input;
}

/*************************************************************
 * Function: shuffle(int deck[][13])
 * Description: This function randomizes the deck array.
 * Input parameters: 2D array 
 * Returns: NA
 * Preconditions: NA
 * Postconditions: Randomized array
 *************************************************************/
void shuffle(int deck[][13])
{
	int row = 0, column = 0, card = 0;   

	for (card = 1; card <= 52; card++)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (deck[row][column] != 0);

		deck[row][column] = card;
	}
}

/*************************************************************
 * Function: deal(const int deck[][13], const char* face[], const char* suit[], Card hand[], Card house_hand[])
 * Description: This function randomly deals the hands to both players.
 * Input parameters: const int deck[][13], const char* face[], const char* suit[], Card hand[], Card house_hand[]
 * Returns: NA
 * Preconditions: Randomized array
 * Postconditions: Random deal
 *************************************************************/
void deal(const int deck[][13], const char* face[], const char* suit[], Card hand[], Card house_hand[])
{
	int row = 0, column = 0, card = 0, i = 1;

	for (card = 1; card <= 10; card++)
	{
		
		for (row = 0; row <= 3; row++)
		{
		
			for (column = 0; column <= 12; column++)
			{
				
				if (deck[row][column] == card)
				{
					
					if (card % 2 == 0) 
					{
						hand[i].suit = row;
						hand[i].face = column;
						i++;
					}
					else 
					{
						house_hand[i].suit = row;
						house_hand[i].face = column;
					}
				}
			}
		}
	}
}

/*************************************************************
 * Function: show_hand(const char* face[], const char* suit[], Card hand[]) 
 * Description: This function prints the welcome screen to the game.
 * Input parameters: const char* face[], const char* suit[], Card hand[]
 * Returns: NA
 * Preconditions: Hand has been dealt.
 * Postconditions: Displays hand
 *************************************************************/
void show_hand(const char* face[], const char* suit[], Card hand[]) 
{
	for (int i = 1; i <= 5; i++) 
	{
		// forgot the name but used the two choice based on the condition
		printf("%d: %4s of %-6s%c", i, face[hand[i].face], suit[hand[i].suit], i % 2 == 0 ? '\n' : '\t');
	}
}

/*************************************************************
 * Function: num_used(Card hand[], int num_used[13])
 * Description: This function determines which cards have been dealt already.
 * Input parameters: Card hand[], int num_used[13]
 * Returns: NA
 * Preconditions: Cards dealt 
 * Postconditions: Validates cards remaining in deck
 *************************************************************/
void num_used(Card hand[], int num_used[13]) 
{
	for (int i = 0; i < FACE; i++) 
	{
		num_used[i] = 0;
	}

	for (int i = 1; i < HAND; i++) 
	{
		switch (hand[i].face) 
		{
		case 0: 
			num_used[0]++;
			break;
		case 1: 
			num_used[1]++;
			break;
		case 3: 
			num_used[2]++;
			break;
		case 4: 
			num_used[3]++;
			break;
		case 5: 
			num_used[4]++;
			break;
		case 6: 
			num_used[5]++;
			break;
		case 7: 
			num_used[6]++;
			break;
		case 8: 
			num_used[7]++;
			break;
		case 9: 
			num_used[8]++;
			break;
		case 10: 
			num_used[9]++;
			break;
		case 11: 
			num_used[10]++;
			break;
		case 12: 
			num_used[11]++;
			break;
		case 13: 
			num_used[12]++;
			break;
		}
	}
}

/*************************************************************
 * Function: pair(Card hand[], int num_used[13])
 * Description: This function determines if you have a pair in the hand.
 * Input parameters: Card hand[], int num_used[13]
 * Returns: 1 if true, 0 if false 
 * Preconditions: Hands dealt 
 * Postconditions: Determines point value of hand.
 *************************************************************/
int pair(Card hand[], int num_used[13]) 
{
	for (int i = 0; i < FACE; i++) 
	{
		if (num_used[i] == 2) 
		{
			return 1;
		}
	}
	return 0;
}

/*************************************************************
 * Function: two_pair(Card hand[], int num_used[13])
 * Description: This function determines if hand has two pair.
 * Input parameters: Card hand[], int num_used[13]
 * Returns: 1 if true, 0 if false
 * Preconditions: Hands dealt 
 * Postconditions: Determines points of hand 
 *************************************************************/
int two_pair(Card hand[], int num_used[13]) 
{
	int count = 0;

	for (int i = 0; i < FACE; i++) 
	{
		if (num_used[i] == 2) 
		{
			count++;
		}
	}
	if (count == 2) 
	{
		return 1;
	}
	return 0;
}

/*************************************************************
 * Function: three_kind(Card hand[], int num_used[13])
 * Description: This function determines if there s a 3 of a kind in hand.
 * Input parameters: Card hand[], int num_used[13]
 * Returns: 1 if true, 0 if false 
 * Preconditions: Hands dealt 
 * Postconditions: Determines points of hand
 *************************************************************/
int three_kind(Card hand[], int num_used[13]) 
{
	for (int i = 0; i < FACE; i++) 
	{
		if (num_used[i] == 3) 
		{
			return 1;
		}
	}
	return 0;
}

/*************************************************************
 * Function: full_house(Card hand[], int num_used[])
 * Description: This function determines if there is a full house in the hand.
 * Input parameters: Card hand[], int num_used[]
 * Returns: 1 if true, 0 if false
 * Preconditions: Hands dealt
 * Postconditions: Determines points of hand
 *************************************************************/
int full_house(Card hand[], int num_used[])
{
	for (int i = 0; i < FACE; i++)
	{
		if (num_used[i] == 3 && num_used[i] == 2)
		{
			return 1;
		}
	}
	return 0;
}

/*************************************************************
 * Function: four_kind(Card hand[], int num_used[13]) 
 * Description: This function determines if hand has 4 of a kind 
 * Input parameters: Card hand[], int num_used[13]
 * Returns: 1 if true, 0 if false 
 * Preconditions: Hands dealt 
 * Postconditions: Points of hand determined
 *************************************************************/
int four_kind(Card hand[], int num_used[13]) 
{
	for (int i = 0; i < FACE; i++) 
	{
		if (num_used[i] == 4) 
		{
			return 1;
		}
	}
	return 0;
}

/*************************************************************
 * Function: suit_count(Card hand[], int suit[4])
 * Description: This function determines the number of each suit within the hand.
 * Input parameters: Card hand[], int suit[4]
 * Returns: NA
 * Preconditions: Hands dealt.
 * Postconditions: Number of same suit cards in hand determined.
 *************************************************************/
void suit_count(Card hand[], int suit[4]) 
{
	
	for (int i = 0; i < SUIT; i++) 
	{
		suit[i] = 0;
	}

	for (int i = 1; i < HAND; i++) 
	{
		switch (hand[i].suit) 
		{
		case 0:
			suit[0]++;
			break;
		case 1:
			suit[1]++;
			break;
		case 2:
			suit[2]++;
			break;
		case 3:
			suit[3]++;
			break;
		}
	}
}

/*************************************************************
 * Function: flush(Card hand[], int suit[4])
 * Description: This function determines if the dealt hand has a flush.
 * Input parameters: Card hand[], int suit[4]
 * Returns: 1 if true, 0 if false 
 * Preconditions: suit_count has been called
 * Postconditions: If the hand has a flush or not
 *************************************************************/
int flush(Card hand[], int suit[4]) 
{
	
	for (int i = 0; i < SUIT; i++) 
	{
		if (suit[i] == 5) 
		{
			return 1;
		}
	}
	return 0;
}

/*************************************************************
 * Function: straight(Card hand[], int num_used[13]) 
 * Description: This function determines if the cards are in consecutive order.
 * Input parameters: Card hand[], int num_used[13]
 * Returns: 1 if true, 0 if false 
 * Preconditions: Hands dealt 
 * Postconditions: If their is a straight or not
 *************************************************************/
int straight(Card hand[], int num_used[13]) 
{
	int count = 0;
	
	for (int i = 0; i < FACE; i++) 
	{
		if (num_used[i] == 1) 
		{
			count++;
		}
		else if (num_used[i] == 0 && count == 5) 
		{
			return 1;
		}
		else {
			count = 0;
		}
	}

	if (count == 5) 
	{
		return 1;
	}

	return 0;
}

/*************************************************************
 * Function:  check_hand(Card hand[])
 * Description: This function evaluates the hand and returns the total points of the hand.
 * Input parameters: Card hand[]
 * Returns: Points 
 * Preconditions: Hands dealt 
 * Postconditions: Points for hand totaled 
 *************************************************************/
int check_hand(Card hand[]) 
{
	int points = 0, num[13], suit[4];
	num_used(hand, num);
	suit_count(hand, suit);
	
	if (pair(hand, num))
		points++;
	if (two_pair(hand, num) && pair(hand, num))
		points++;
	if (three_kind(hand, num))
		points += 3;
	if (straight(hand, num))
		points += 4;
	if (flush(hand, suit))
		points += 5;
	if (four_kind(hand, num))
		points += 6;
	if (full_house(hand, num))
		points += 7;
	return points;
}

/*************************************************************
 * Function: reinit(Card hand[], Card house_hand[], int deck[4][13])
 * Description: This function sets the hands and the deck back to 0.
 * Input parameters: Card hand[], Card house_hand[], int deck[4][13]
 * Returns: NA
 * Preconditions: End of hand
 * Postconditions: Arrays ready for new hand start
 *************************************************************/
void reinit(Card hand[], Card house_hand[], int deck[4][13]) 
{
	for (int i = 0; i < 6; i++) 
	{
		hand[i].face = 0;
		hand[i].suit = 0;
		house_hand[i].face = 0;
		house_hand[i].suit = 0;
	}

	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 13; j++) 
		{
			deck[i][j] = 0;
		}
	}
}

/*************************************************************
 * Function: house_deal(Card hand[], int score, int house_score)
 * Description: This function determines how many cards the dealer will swap based on score of current hand.
 * Input parameters: Card hand[], int score, int house_score
 * Returns: How many cards dealer will swap based on points of current hand.
 * Preconditions: Hands have been checked for points
 * Postconditions: Welcome screen displayed.
 *************************************************************/
int house_deal(Card hand[], int score, int house_score) 
{
	if (house_score <= score) 
	{
		if (house_score < 3) 
		{
			return 1;
		}
		else if (house_score < 2) 
		{
			return 2;
		}
		else if (house_score < 1) 
		{
			return 3;
		}
	}
	return 0;
}

/*************************************************************
 * Function: dealer_draw(Card hand[], Card house_hand[], int k)
 * Description: This function randomly generates new cards to swap if dealer chooses to do so.
 * Input parameters: Card hand[], Card house_hand[], int k
 * Returns: NA
 * Preconditions: Dealer draws new cards 
 * Postconditions: Dealer is dealt random cards 
 *************************************************************/
void dealer_draw(Card hand[], Card house_hand[], int k) 
{
	int used[6] = { 0 };
	int random = 0, gen = 0, new = 0, face = 0, suit = 0;
	
	for (int i = 0; i < k; i++) 
	{
		gen = 1;
		while (gen) 
		{
			random = rand() % 5 + 1;
			for (int j = 1; j < 6; j++) 
			{
				if (random == j && used[random] == 1)
				{
					gen = 1;
					break;
				}
				gen = 0;
			}
		}

		new = 1;
		while (new) 
		{
			generate(&face, &suit);
			if (drawn(face, suit, hand, house_hand) == 0) 
			{
				new = 0;
			}
		}
		used[random] = 1;
		hand[random].face = face;
		hand[random].suit = suit;
	}
}

/*************************************************************
 * Function: draw_card(Card hand[], Card house_hand[], int n)
 * Description: This function generates a random card to replace card chosen to swap.
 * Input parameters: Card hand[], Card house_hand[], int n
 * Returns: NA
 * Preconditions: Cards to be swapped 
 * Postconditions: New cards generated
 *************************************************************/
void draw_card(Card hand[], Card house_hand[], int n) 
{
	int choice = 0, face = 0, suit = 0, gen = 0;
	for (int i = 0; i < n; i++)
	{
		gen = 1;
		while (gen) 
		{
			generate(&face, &suit);
			if (drawn(face, suit, hand, house_hand) == 0) 
			{
				gen = 0;
			}
		}
		printf("Which card do you want to redraw? 1-5:\n");
		scanf("%d", &choice);
		switch (choice) 
		{
		case 1:
			hand[1].face = face;
			hand[1].suit = suit;
			break;
		case 2:
			hand[2].face = face;
			hand[2].suit = suit;
			break;
		case 3:
			hand[3].face = face;
			hand[3].suit = suit;
			break;
		case 4:
			hand[4].face = face;
			hand[4].suit = suit;
			break;
		case 5:
			hand[5].face = face;
			hand[5].suit = suit;
			break;
		}
	}
}

/*************************************************************
 * Function: drawn(int face, int suit, Card hand[], Card house_hand[])
 * Description: This function determines if a card has already been dealt.
 * Input parameters: int face, int suit, Card hand[], Card house_hand[]
 * Returns: 1 if already dealt, 0 if still in deck
 * Preconditions: Hands dealt 
 * Postconditions: Right cards are being dealt when redrawing 
 *************************************************************/
int drawn(int face, int suit, Card hand[], Card house_hand[]) 
{
	for (int i = 1; i < 6; i++) 
	{
		if ((hand[i].face == face && hand[i].suit == suit) || (house_hand[i].face == face && house_hand[i].suit == suit)) 
		{
			return 1;
		}
	}
	return 0;
}

/*************************************************************
 * Function: generate(int* face, int* suit)
 * Description: This function randmomized the value and suit of each card.
 * Input parameters: int* face, int* suit
 * Returns: NA
 * Preconditions: 2D array to store values 
 * Postconditions: Deck is randomized
 *************************************************************/
void generate(int* face, int* suit)
{
	*face = rand() % 13;
	*suit = rand() % 4;
}

// end of functions 