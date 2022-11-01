
#ifndef Yahtzee_functions
#define _CRT_SECURE_NO_WARNINGS
#define RULES 100
#define PLAY 101
#define EXIT 102
//Upper section Constants
#define ACES 1
#define TWOS 2
#define THREES 3
#define FOURS 4 
#define FIVES 5
#define SIXES 6
//lower section constants
#define THREE_OF_A_KIND 7
#define FOUR_OF_A_KIND 8
#define FULL_HOUSE 9
#define SMALL_STRAIGHT 10
#define LARGE_STRAIGHT 11
#define YAHTZEE 12
#define CHANCE 13
#define SKIP 14

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Players {
	int score;
	int bonus;
	int top_section_bonus;
	int top_section_score;
	int bottom_section_score;
	int card[13];
	char playerName[7];
} Player;

int top_section(int points, int* top_section_score, int* top_section_bonus);

void bottom_section(int points, int* bottom_section_score);

int ask_game_status();

int ask_for_number_of_players();

void display_rules();

void initialize_array_zeros(int* arr, int arraySize);

void initialize_players(Player *players, int player_count);

int ask_to_roll_dice();

void roll_dice(int* dice_arr, int arr_size);

void display_yahtzee_logo();

void display_dice(int* dice_arr);

int reroll_dice(int* dice_arr, int* rolls);

int roll_specific_dice(int* dice_arr, int dice1, int dice2, int dice3, int dice4, int dice5);

void display_game_screen(Player* players, int players_turn, int round, int player_count);

void fill_card_with_selection(int* card, int* dice, int* score, int* bonus, int* top_score, int* bottom_score, int* top_bonus);

int check_aces(int* dice);

int check_twos(int* dice);

int check_threes(int* dice);

int check_fours(int* dice);

int check_fives(int* dice);

int check_sixes(int* dice);

int check_3_of_a_kind(int* dice);

int check_4_of_a_kind(int* dice);

int check_full_house(int* dice);

int check_small_straight(int* dice);

int check_large_straight(int* dice);

int check_yahtzee(int* dice);

int check_chance(int* dice);

void display_end_of_game_results(Player* players, int player_count);

#endif // !Yahtzee_functions
