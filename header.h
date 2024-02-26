#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <ctype.h> 

void initialize_rand(void);

void welcome_statement(void);

int determine_choice(void);

void print_game_rules(void);

void play_blackjack(void);

int enter_wager(void);

int card_sum(int card1, int card2);

int draw_more(int sum);

int draw_cards_again(int sum);

void determine_winner(int player_sum, int dealer_sum);

int want_to_draw(void);
