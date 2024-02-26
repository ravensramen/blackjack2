#include "header.h"

int main() {
	initialize_rand();
	welcome_statement();

	int user_choice = 0;

	do {
		user_choice = determine_choice();
		switch (user_choice) {
		case 1: print_game_rules();
			break;
		case 2: play_blackjack();
			break;
		case 3:
			printf("Thanks for playing. bye bye...");
			return 0;
		}
	} while (user_choice != 3);




	return 0;
}
