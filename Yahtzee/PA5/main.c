#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Yahtzee_functions.h"


int main(void)
{
	int dice[5];
	int rounds = 0, player_count = 0, game_status = 0, rolls = 0, player_turn = 0;
	Player players[4]; //Max 4 players
	
	do {
		game_status = ask_game_status();
		if (game_status == RULES) display_rules();
		else
		{
			player_count = ask_for_number_of_players();
			initialize_players(players, player_count);
			do {
				rounds++;
				player_turn = 0;
				do {
					rolls = 0;
					display_game_screen(players, player_turn, rounds, player_count);
					if (ask_to_roll_dice() == 1) { game_status = EXIT; break; }
					roll_dice(dice, 5);
					display_dice(dice);
					reroll_dice(dice, &rolls);
					fill_card_with_selection(players[player_turn].card, dice, &players[player_turn].score,
						&players[player_turn].bonus, &players[player_turn].top_section_score,
						&players[player_turn].bottom_section_score, &players[player_turn].top_section_bonus);
					player_turn++;
				} while (player_turn < player_count);
				if (game_status == EXIT) break;
			} while (rounds < 14);
		}
		if (rounds >= 13) game_status = EXIT;
	} while (game_status != EXIT);

	display_end_of_game_results(players, player_count);

	return 1;
}