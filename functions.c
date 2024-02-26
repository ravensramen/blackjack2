#include "header.h"
//add bank function, fix over 21 bust error7

void initialize_rand(void) {
	srand(time(NULL));
}

int card_draw() {
	int card_value = 0;
	card_value = rand() % 11 + 1;
	return card_value;
}

void welcome_statement(void) {
	printf("Welcome to blackjack!\n");
}

int determine_choice(void) {
	int user_choice = 0;
	printf("Enter 1 to display rules, 2 to play blackjack, and 3 to exit the program\n");
	scanf("%d", &user_choice);
	return user_choice;
}
void print_game_rules(void) {
	printf("Here are the rules...\n\n");

	printf("Both you and the dealer will recieve two cards.\n");
	printf("The dealer will be able to see your cards, but you will only be able to see one of theirs.\n");
	printf("Your goal is to get a sum of cards closer to 21 than that of your dealer.\n");
	printf("You will be given the option to draw more cards to get closer to a sum of 21...\n");
	printf("But be warned, if you exceed 21, you bust!\n\n");

	printf("Without further ado, let's play!\n");


	return;
}

void play_blackjack(void) {
	printf("playing game...\n");

	int wager = 0;
	int player_card1 = 0, player_card2 = 0, player_card_draws = 0, dealer_card1 = 0, dealer_card2 = 0;

	int sum = 0, house_sum = 0;
	int keep_drawing = 0;

	wager = enter_wager();

	player_card1 = card_draw();
	player_card2 = card_draw();

	sum = card_sum(player_card1, player_card2);

	dealer_card1 = card_draw();
	dealer_card2 = card_draw();

	printf("You cards are %d and %d. Your sum is %d\n", player_card1, player_card2, sum);
	printf("The dealer's cards are '?' and '?'... who knows what their sum could be...\n");

	

	if (sum > 21) {
		printf("BUST!! WOMP WOMP :P\n");
		return 0;
	}

	if (sum == 21) {
		printf("Lucky you!... Dumb question but...");
	}

	keep_drawing = want_to_draw();


	while(keep_drawing == 1 && sum <21) {
		//if user choice is yes
		int new_sum = draw_more(sum);
		sum = new_sum;

		//if (sum > 21) {
		//	printf("kys :P");
		//	break;
		
		if (sum <= 21) {
			//printf("Your current sum is %d.\n", sum);
			keep_drawing = want_to_draw(); 
		}
	}

	if (keep_drawing == 0) {
		printf("You said no? lets reveal the cards...\n");
		house_sum = card_sum(dealer_card1, dealer_card2);
		printf("The house's cards were %d and %d, and their sum was %d.\n", dealer_card1, dealer_card2, house_sum);
		determine_winner(sum, house_sum);
	}

	return;
}

int enter_wager(void) {
	int wager = 0;
	printf("Enter your wager: ");
	scanf("%d", &wager);
	return wager;
}


int card_sum(int card1, int card2) {
	int card_sum = 0;
	card_sum = card1 + card2;
	return card_sum;
}

int draw_more(int sum) {
	int initial_sum = sum;
	int final_sum = 0;

	final_sum = draw_cards_again(initial_sum);
	return final_sum;
	}

int draw_cards_again(int sum) { 
	int previous_sum = sum;
	int next_card = 0;
	int sum_after = 0;

	printf("Drawing more cards. . . \n");
	next_card = card_draw();
	printf("You drew a %d\n", next_card);
	sum_after = previous_sum + next_card;



	printf("Your new sum is %d.", sum_after);

	if (sum_after == 21) {
		printf("Lucky you!... Dumb question but...");
		return sum_after;
	}

	if (sum_after > 21) {
		printf("BUST!!");
		return 0;
	}
}

void determine_winner(int player_sum, int dealer_sum) {
	if (player_sum > 21) {
		return 0;
	}
	if (player_sum < dealer_sum) {
		printf("The house wins!! Sucks to suck!\n");
	}
	else if (dealer_sum < player_sum) {
		printf("You win, YIPPEE!\n");
	}
	else if (dealer_sum = player_sum) {
		printf("A stand-off?? Better luck next round I guess!\n");
	}
}

int want_to_draw(void) {
	char user_choice = '\0';
	int choice = 0;

	printf("Do you want to draw again? Enter 'Y' for yes and 'N' for no\n");
	scanf(" %c", &user_choice);
	user_choice = toupper(user_choice);

	if (user_choice == 'Y') {
		int choice = 1;
		return choice;
	}
	else {
		return 0;
	}
	return choice;
}
