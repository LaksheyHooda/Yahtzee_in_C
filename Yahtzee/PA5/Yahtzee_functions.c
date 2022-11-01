
#include "Yahtzee_functions.h"

int ask_game_status()
{
	system("cls");
	printf("\n");
	printf("\n");
	display_yahtzee_logo();
	printf("\n");
	printf("\n");
	char response = '\0';
	do {
		printf("Do you want to (r) print rules, (s) start game, or (e) exit game: ");
		scanf(" %c", &response);
		response = tolower(response);
		//printf("%c", response);
	} while (response != 'r' && response != 's' && response != 'e');
	if (response == 'r') return RULES;
	else if (response == 's') return PLAY;
	else return EXIT;
}

int ask_for_number_of_players()
{
	int playerCount = 0;
	system("cls");
	printf("\n");
	printf("\n");
	display_yahtzee_logo();
	printf("\n");
	printf("\n");
	do {
		printf("How many players are playing (1-4)?");
		scanf("%d", &playerCount);
	} while (playerCount < 1 && playerCount > 4);
	return playerCount;
}

void display_rules()
{
	system("cls");
	//yahtzee askii logo
	printf("\n");
	printf("\n");
	display_yahtzee_logo();
	printf("\n");
	printf("\n");
	printf("Welcome to YAHTZEE! (ascii edition) \n");
	printf("The goal of Yahtzee is to fill your card with the most points possible. \n");
	printf("There are 13 rounds and each round each player rolls 5 dice. \n");
	printf("Once you roll your dice you have the option to reroll any of the dice. \n");
	printf("You can reroll up to 3 times. \n");
	printf("Once satasfied you get to choose where you want your points filled. \n");
	printf("There are 6 top section score places and \n");
	printf("6 bottom section score places. \n");
	printf("The top secction is the sum of 1s, 2s, 3s, 4s, 5s, and 6s. \n");
	printf("For example your roll 1 3 3 3 5, you would get a score of 9 for sum of 3. \n");
	printf("If you score above a 62 in the top section you get a 35 point bonus. \n");
	printf("The bottom section contains 6 more options, \n");
	printf("3 of a kind, 4 of a kind, full house, small straight, large straight \n");
	printf("3 and 4 of a kind is just sum of all dice for your points, \n");
	printf("a full house is 2 of one dice face and 3 of the other (25 points) \n");
	printf("a small straight is 4 in a row (30 points) \n");
	printf("and a large straight is 5 in a row (40 points) \n");
	printf("You can also get a Yatzhee (all 5 dice are the same) worth 50 points \n");
	printf("Each additional yatzhee after the first is worth 100 points \n");
	printf("There is also a chance which you can place your points in at any time \n");
	printf("the points for chance are just the sum of the dice \n");
	printf("If you cannot make a combination you must skip your turn \n");
	printf("The goal is to have the most points by the end. \n");
	printf("GOOD LUCK AND HAVE FUN! \n");
	printf("press any key to continue");
	_getch();
}

void display_yahtzee_logo()
{	
	printf("\t  ____                 ");
	printf("\t _     _  ___  _   _ _____ ___________ _____ ");
	printf("\t     ____                 \n");
	printf("\t /\\' .\\    _____       ");
	printf("\t| |   | |/ _ \\| | | (_   _|___  /  ___)  ___)");
	printf("\t    /\\' .\\    _____       \n");
	printf("\t/: \\___\\  / .  /\\      ");
	printf("\t| \\___/ | |_| | |_| | | |    / /| |_  | |_   ");
	printf("\t   /: \\___\\  / .  /\\      \n");
	printf("\t\\' / . / /____/..\\     ");
	printf("\t \\_   _/|  _  |  _  | | |   / / |  _) |  _)  ");
	printf("\t   \\' / . / /____/..\\     \n");
	printf("\t \\/___/  \\'  '\\  /     ");
	printf("\t   | |  | | | | | | | | |  / /__| |___| |___ ");
	printf("\t    \\/___/  \\'  '\\  /     \n");
	printf("\t          \\'__'\\/      ");
	printf("\t   |_|  |_| |_|_| |_| |_| /_____)_____)_____)");
	printf("\t             \\'__'\\/      \n");
}

void initialize_array_zeros(int* arr, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		arr[i] = 0;
	}
}

void initialize_players(Player* players, int player_count)
{
	for (int i = 0; i < player_count; i++)
	{
		char name[50];
		players[i].score = 0;
		players[i].bonus = 0;
		players[i].top_section_bonus = 0;
		players[i].top_section_score = 0;
		players[i].bottom_section_score = 0;
		initialize_array_zeros(players[i].card, 13);
		printf("What is player %d name? (max 7 characters) ", i + 1);
		scanf("%s", &name);
		strncpy(players[i].playerName, name, 7);
		players[i].playerName[7] = '\0';
	}
}

void roll_dice(int* dice_arr, int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		dice_arr[i] = rand() % 6 + 1;
	}
}

int ask_to_roll_dice()
{
	printf("click any key to roll dice! Or press e to exit game \n");
	char newChar = tolower(_getch());
	if (newChar == 'e') return 1;
	else return 0;
}

void display_dice(int* dice_arr)
{
	system("cls");
	for (int i = 0; i < 6; i++)
	{
		switch (dice_arr[i])
		{
		case(1):
			printf("+-------+\n");
			printf("|     	|\n");
			printf("|   o	|\n");
			printf("|     	|\n");
			printf("+-------+\n");
			break;
		case(2):
			printf("+-------+\n");
			printf("|      o|\n");
			printf("|   	|\n");
			printf("|o      |\n");
			printf("+-------+\n");
			break;
		case(3):
			printf("+-------+\n");
			printf("|      o|\n");
			printf("|   o	|\n");
			printf("|o      |\n");
			printf("+-------+\n");
			break;
		case(4):
			printf("+-------+\n");
			printf("|o     o|\n");
			printf("|    	|\n");
			printf("|o     o|\n");
			printf("+-------+\n");
			break;
		case(5):
			printf("+-------+\n");
			printf("|o     o|\n");
			printf("|   o	|\n");
			printf("|o     o|\n");
			printf("+-------+\n");
			break;
		case(6):
			printf("+-------+\n");
			printf("|o     o|\n");
			printf("|o     o|\n");
			printf("|o     o|\n");
			printf("+-------+\n");
			break;
		}
	}
}



int reroll_dice(int* dice_arr, int* rolls)
{
	char answer = '\0';
	do {
		printf("Do you want to reroll any of your dice? (y/n): ");
		scanf(" %c", &answer);
		answer = tolower(answer);
	} while (answer != 'y' && answer != 'n');
	if (answer == 'n') return -1;
	if (answer == 'y') {
		char response[20];
		int reroll[5] = {0};
		int sucess = 0;
		do {
			do {
				printf("Which dice do you want to reroll? (Seprate by commas i.e. 2,4): ");
				scanf("%s", response);
			} while (response == ' ');
			sucess = 1;
			char* token = strtok(response, ",");
			while (token != NULL) {
				if (atoi(token) > 5)
				{
					sucess = 0;
					printf("Incorrect input\n");
					break;
				}
				reroll[atoi(token) - 1] = 1;
				token = strtok(NULL, ",");
			}
		} while (sucess == 0);
		roll_specific_dice(dice_arr, reroll[0], reroll[1], reroll[2], reroll[3], reroll[4]);
		(* rolls)++;
		display_dice(dice_arr);
		if (*rolls < 3) reroll_dice(dice_arr, rolls);
		else return -1;
	}
	
}


int roll_specific_dice(int* dice_arr, int dice1, int dice2, int dice3, int dice4, int dice5)
{
	if (dice1 == 1) dice_arr[0] = rand() % 6 + 1;
	if (dice2 == 1) dice_arr[1] = rand() % 6 + 1;
	if (dice3 == 1) dice_arr[2] = rand() % 6 + 1;
	if (dice4 == 1) dice_arr[3] = rand() % 6 + 1;
	if (dice5 == 1) dice_arr[4] = rand() % 6 + 1;
}

void fill_card_with_selection(int* card, int* dice, int* score, int* bonus, int* top_score, int* bottom_score, int* top_bonus)
{
	int answer = 0;
	int filled = 0;
	system("cls");
	printf("Your dice rolls: %d, %d, %d, %d, %d \n", dice[0], dice[1], dice[2], dice[3], dice[4]);
	printf("Please select where you want to place your roll! (i.e. 3) \n");
	printf("1. Sum of 1's \t 7. Three of a Kind \n");
	printf("2. Sum of 2's \t 8. Four of a Kind \n");
	printf("3. Sum of 3's \t 9. Full House \n");
	printf("4. Sum of 4's \t 10. Small Straight \n");
	printf("5. Sum of 5's \t 11. Large Straight \n");
	printf("6. Sum of 6's \t 12. Yahtzee \n");
	printf("13. Chance    \t 14. Skip Turn \n");
	do {
		do {
			printf("Your selection: ");
			scanf("%d", &answer);
		} while (answer <= 0 && answer >= 15);
		if (answer == 14) break;
		if (answer == 12 && card[11] > 0)
		{
			if (check_yahtzee(dice) > 0) *bonus += 100;
			else printf("you dont have the right combination \n");
		}
		else
		{
			if (card[answer - 1] > 0)
			{
				printf("Already selected. \n");
			}
			else
			{
				int canbe = 0;
				switch (answer)
				{
					case(ACES): if (check_aces(dice) > 0) canbe = check_aces(dice); break;
					case(TWOS): if (check_twos(dice) > 0) canbe = check_twos(dice); break;
					case(THREES): if (check_threes(dice) > 0) canbe = check_threes(dice); break;
					case(FOURS): if (check_fours(dice) > 0) canbe = check_fours(dice); break;
					case(FIVES): if (check_fives(dice) > 0) canbe = check_fives(dice); break;
					case(SIXES): if (check_sixes(dice) > 0) canbe = check_sixes(dice); break;
					case(THREE_OF_A_KIND): if (check_3_of_a_kind(dice) > 0) canbe = check_3_of_a_kind(dice); break;
					case(FOUR_OF_A_KIND): if (check_4_of_a_kind(dice) > 0) canbe = check_4_of_a_kind(dice); break;
					case(SMALL_STRAIGHT): if (check_small_straight(dice) > 0) canbe = check_small_straight(dice); break;
					case(LARGE_STRAIGHT): if (check_large_straight(dice) > 0) canbe = check_large_straight(dice); break;
					case(FULL_HOUSE): if (check_full_house(dice) > 0) canbe = check_full_house(dice); break;
					case(YAHTZEE): if (check_yahtzee(dice) > 0) canbe = check_yahtzee(dice); break;
					case(CHANCE): if (check_chance(dice) > 0) canbe = check_chance(dice); break;
				}
				if (canbe > 0)
				{
					filled = 1;
					(*score) += canbe;
					if (answer <= 6)
					{
						if (top_section(canbe, top_score, top_bonus) == 1)
						{
							(*score) += 35;
						}
					}
					else
					{
						bottom_section(canbe, bottom_score);
					}
					card[answer - 1] = canbe;
				}
				else printf("you dont have the right combination \n");
			}
		}
	} while (filled == 0);
}

int top_section(int points, int* top_section_score, int* top_section_bonus)
{
	(*top_section_score) += points;
	if (*top_section_score >= 63 && *top_section_bonus == 0)
	{
		*top_section_bonus = 35;
		return 1;
	}
	else return 0;
}

void bottom_section(int points, int* bottom_section_score)
{
	(*bottom_section_score) += points;
}

int check_aces(int* dice)
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		if (dice[i] == 1) total++;
	}
	return total;
}

int check_twos(int* dice)
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		if (dice[i] == 2) total+=2;
	}
	return total;
}

int check_threes(int* dice)
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		if (dice[i] == 3) total += 3;
	}
	return total;
}

int check_fours(int* dice)
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		if (dice[i] == 4) total += 4;
	}
	return total;
}

int check_fives(int* dice)
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		if (dice[i] == 5) total += 5;
	}
	return total;
}

int check_sixes(int* dice)
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		if (dice[i] == 6) total += 6;
	}
	return total;
}

int check_3_of_a_kind(int* dice)
{
	int valid = 0;
	for (int i = 0; i < 5; i++)
	{
		int tally = 1;
		for (int j = 0; j < 5; j++)
		{
			if (j != i && dice[i] == dice[j]) tally++;
		}
		if (tally >= 3) valid = 1;
	}
	if (valid == 1)
	{
		int total = 0;
		for (int i = 0; i < 5; i++)
		{
			total += dice[i];
		}
		return total;
	}
	else return 0;
}

int check_4_of_a_kind(int* dice)
{
	int valid = 0;
	for (int i = 0; i < 5; i++)
	{
		int tally = 1;
		for (int j = 0; j < 5; j++)
		{
			if (j != i && dice[i] == dice[j]) tally++;
		}
		if (tally >= 4) { valid = 1; break; }
	}
	if (valid == 1)
	{
		int total = 0;
		for (int i = 0; i < 5; i++)
		{
			total += dice[i];
		}
		return total;
	}
	else return 0;
}

int check_full_house(int* dice)
{
	int valid = 0;
	for (int i = 0; i < 5; i++)
	{
		int threeTally = 1;
		int twoTallyVal = 0;
		int twoTally = 0;
		for (int j = 0; j < 5; j++)
		{
			if (i != j && dice[i] == dice[j]) threeTally++;
			if (dice[i] != dice[j]) twoTallyVal = dice[j];
			if (twoTallyVal == dice[j]) twoTally++;
		}
		if (threeTally == 3 && twoTally == 2) { valid = 1;  break; }
	}
	if (valid == 1)
	{
		return 25;
	}
	else return 0;
}

int check_small_straight(int* dice)
{
	//small straight combos
	//1,2,3,4
	//2,3,4,5
	//3,4,5,6
	int valid = 1;
	for (int i = 0; i < 3; i++)
	{
		valid = 1;
		int pos[4] = { 1 + i, 2 + i, 3 + i, 4 + i };
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (dice[j] == pos[k])
				{
					pos[k] = 0;
					break;
				}
			}
		}
		for (int j = 0; j < 4; j++)
		{
			if (pos[j] != 0) valid = 0;
		}
		if (valid == 1) break;
	}
	if (valid == 1) return 30;
	else return 0;
}

int check_large_straight(int* dice)
{
	//1,2,3,4,5
	//2,3,4,5,6
	int valid = 1;
	for (int i = 0; i < 2; i++)
	{
		valid = 1;
		int pos[5] = { 1 + i, 2 + i, 3 + i, 4 + i, 5 + i };
		for (int k = 0; k < 5; k++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (dice[j] == pos[k])
				{
					pos[k] = 0;
					break;
				}
			}
		}
		for (int j = 0; j < 5; j++)
		{
			if (pos[j] != 0) valid = 0;
		}
		if (valid == 1) break;
	}
	if (valid == 1) return 40;
	else return 0;
}

int check_yahtzee(int* dice)
{
	int valid = 1;
	for (int i = 1; i < 5; i++)
	{
		if (dice[i] != dice[0]) { valid = 0; break; }
	}
	if (valid == 1) return 50;
	else return 0;
}

int check_chance(int* dice)
{
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		total += dice[i];
	}
	return total;
}

void display_game_screen(Player* players, int players_turn, int round, int player_count)
{
	system("cls");
	printf("It is %s's turn! \t We are on round %d\n\n", players[players_turn].playerName, round);
	for (int i = 0; i < 14; i++)
	{
		if (i == 0)
		{
			printf("\t\t");
			for (int j = 0; j < player_count; j++)
			{
				printf("\t%s", players[j].playerName);
			}
			printf("\n");
			continue;
		}
		if (i == 7)
		{
			printf("\nTOP BONUS\t");
			for (int k = 0; k < player_count; k++)
			{
				printf("\t%d", players[k].top_section_bonus);
			}
			printf("\n\nTOP TOTAL\t");
			for (int k = 0; k < player_count; k++)
			{
				printf("\t%d", players[k].top_section_score);
			}
			printf("\n\n");
		}
		char type[20];
		switch (i) {
			case (ACES): strncpy(type, "ONES\t", 20); break;
			case (TWOS): strncpy(type, "TWOS\t", 20); break;
			case (THREES): strncpy(type, "THREES\t", 20); break;
			case (FOURS): strncpy(type, "FOURS\t", 20); break;
			case (FIVES): strncpy(type, "FIVES\t", 20); break;
			case (SIXES): strncpy(type, "SIXES\t", 20); break;
			case (THREE_OF_A_KIND): strncpy(type, "THREE OF A KIND", 20); break;
			case (FOUR_OF_A_KIND): strncpy(type, "FOUR OF A KIND", 20); break;
			case (FULL_HOUSE): strncpy(type, "FULL HOUSE", 20); break;
			case (SMALL_STRAIGHT): strncpy(type, "SMALL STRAIGHT", 20); break;
			case (LARGE_STRAIGHT): strncpy(type, "LARGE STRAIGHT", 20); break;
			case (YAHTZEE): strncpy(type, "YAHTZEE\t", 20); break;
			case (CHANCE): strncpy(type, "CHANCE\t", 20); break;
		}
		printf("%s\t", type);
		for (int j = 0; j < player_count; j++)
		{
			printf("\t%d", players[j].card[i-1]);
		}
		printf("\n");
	}
	printf("\nBOTTOM TOTAL\t");
	for (int k = 0; k < player_count; k++)
	{
		printf("\t%d", players[k].bottom_section_score);
	}
	printf("\n");
	printf("Yahtzee Bonus\t");
	for (int i = 0; i < player_count; i++)
	{
		printf("\t%d", players[i].bonus);
	}
	printf("\n\n");
	printf("TOTAL\t\t");
	for (int i = 0; i < player_count; i++)
	{
		printf("\t%d", players[i].score);
	}
	printf("\n\n");
}

void display_end_of_game_results(Player* players, int player_count)
{
	system("cls");
	printf("\n");
	printf("\n");
	display_yahtzee_logo();
	printf("\n");
	printf("\n");
	char winnername[10];
	int winner_score = 0;
	for (int i = 0; i < player_count; i++)
	{
		if (players[i].score >= winner_score)
		{
			winner_score = players[i].score;
			strncpy(winnername, players[i].playerName, 10);
		}
	}
	printf("%s won with a score of %d \n", winnername, winner_score);
	printf("\nNice try to the rest of you \n");
	printf("Hope you had fun! \n");
	printf("press any key to close the program");
	_getch();
}