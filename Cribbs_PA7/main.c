// includes header file 
#include "poker.h"

// start of program 
int main(void) 
{
	// suit array
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	// face array
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	// deck array
	int deck[4][13] = { 0 };
	// hand arrays for both players 
	Card hand[6] = { 0 };
	Card house_hand[6] = { 0 };
	// int variables 
	int total = 0, p1_score = 0, p2_score = 0, draw = 0, house_draw = 0, choice = 0, row = 3, col = 12, option = 0, game = 0, score = 0, house_score = 0;
	// char variable for user input 
	char y_n = '\0';
	
	// call to use rand function
	srand((unsigned)time(NULL)); 

	do {

		// opening message 
		printf("Finally! It's over, I do not wanna build another game\n");
		// clears the screen
		clear();
		// welcome message 
		printf("Hope your ready to play Poker\n");
		// clears the screen
		clear();

		while (game == 0)
		{
			// game menu
			printf("1. Play Game\n2. Rules of the game\n3. Exit\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
			
				// will go up to 10 turns before game will return to the menu
				while (total <= 10) 
				{
					// clears the screen
					clear();
					// shuffle of the deck
					shuffle(deck);
					// deals both players hands 
					deal(deck, face, suit, hand, house_hand);
					printf("Your hand:\n");
					// shows player one hand 
					show_hand(face, suit, hand);
					// checks hands to determine if any combinations are in play
					p1_score = check_hand(hand);
					p2_score = check_hand(house_hand);
					// displays your points based on combinations
					printf("Points: %d\n", p1_score);
					// if you want to swap cards 
					printf("Redraw? Y/N: ");
					// reads user input
					y_n = char_input();
					// if yes, will ask how many and which cards you wish to redraw
					if (y_n == 'Y') 
					{
						do {
							printf("\nHow many cards would you like to redraw? (max of 3): ");
							scanf("%d", &draw);
						} while (draw > 3);
						// draws new cards
						draw_card(hand, house_hand, draw);
						// prints your new hand
						show_hand(face, suit, hand);
						// updates player score of hand
						p1_score = check_hand(hand);
						// displays total points of hand 
						printf("Points: %d\n", p1_score);
					}
					// determines number of cards to draw based on points of dealer hand
					house_draw = house_deal(house_hand, p1_score, p2_score);
					// clears screen
					clear();
					// shows how many cards the dealer swapped
					printf("The dealer drew %d cards.\n", house_draw);
					// randomly draws new cards for dealer
					dealer_draw(house_hand, hand, house_draw);
					// updates score of dealers hand
					p2_score = check_hand(house_hand);
					// clears screen
					clear();
					// if player wins
					if (p1_score > p2_score)
					{
						// congrats message
						printf("You won!\n");
						// shows your hand and points
						printf("Your hand:\n");
						show_hand(face, suit, hand);
						printf("Points: %d\n", p1_score);
						// shows dealer and and points
						printf("\nDealer hand:\n");
						show_hand(face, suit, house_hand);
						printf("Points: %d\n", p2_score);
						// adds to total score
						score++;
						// shows total score of both players
						printf("\nPlayer Score: %d\tHouse Score: %d\n", score, house_score);
						// prompts to keep playing 
						printf("Do you want to keep playing? Y/N\n");
						// checks user input 
						y_n = char_input();
						// if yes starts another hand 
						if (y_n == 'Y')
						{
							game = 0;
						}
						// if no, exits the game 
						else
						{
							return 0;
						}

					}
					// if dealer wins or is a tie(dealer still wins in a tie)
					else if (p2_score > p1_score || p2_score == p1_score) 
					{
						// displays losing message 
						printf("The house won, thats too bad.\n");
						// shows your hand and points
						printf("Your hand:\n");
						show_hand(face, suit, hand);
						printf("Points: %d\n", p1_score);
						// shows dealer hand and points 
						printf("\nDealer hand:\n");
						show_hand(face, suit, house_hand);
						printf("Points: %d\n", p2_score);
						// updates dealer total score 
						house_score++;
						// prints totals 
						printf("\nPlayer Score: %d\tHouse Score: %d\n", score, house_score);
						// prompts user to continue playing 
						printf("Do you want to keep playing? Y/N\n");
						// checks user input 
						y_n = char_input();
						// if yes starts new hand 
						if (y_n == 'y' || y_n == 'Y')
						{
							game = 0;
						}
						// if no, exits the game 
						else
						{
							return 0;
						}
					}
					// clears the screen 
					clear();
					// reinitalizes both players hands and the deck
					reinit(hand, house_hand, deck);
					// adds to total hands played 
					
					
				}
				// clears the screen
				clear();
			}
			// option for game rules 
			if (choice == 2) 
			{
				clear();
				// prints the game rules and combinations 
				printf("Five Card Draw Poker is a card game.\nYou are player one, and the computer (dealer) is the house.\nYou are each dealt 5 cards in a hand, you can't see the dealer's hand\n");
				printf("Using poker game combinations, you can redraw up to 3 cards to create combinations.\n");
				printf("Both hands are revealed and the player with the better hand wins the round.\n");
				printf("COMBINATIONS:\n");
				printf("One Pair\n");
				printf("Two Pair\n");
				printf("Three of a Kind: Three cards of the same face\n");
				printf("Straight: Five cards of consecutive face values\n");
				printf("Flush: Five cards of the same suit\n");
				printf("Four of a Kind: Four cards of the same face\n");
				// clears the screen 
				clear();
			}
			// exits the game 
			if (choice == 3)
			{
				return 0;
			}
		}
		// only executed while menu option is valid in do-while loop
	} while (option > 1 && option < 3);

	// end of the program 
	return 0;
}