/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Patel Bhavy Piyushkumar
	ID     : 121048219
	Email  : bppatel16@myseneca.ca
	Section: NMM
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define Min_lives 1
#define Max_lives 10
#define Multi_of 5
#define Min_Pathlength 10
#define Max_pathlength 70
struct PlayerInfo
{
	int lives;
	char Symbol;
	int nmber_of_treasure;
	int history[Max_pathlength];
};
struct GameInfo
{
	int pathlength;
	int moves;
	int bombs[Max_pathlength];
	int treasure[Max_pathlength];
};
int main(void)
{
	int Min_Moves = 0, Max_Moves = 0, Next_Moves = 1;
	int x,y,k,l,i;
	x = y = k = l =  0;
	int j ;
	double m = 0;
	const char undiscovered = '-', bomb = '!', treasure = '$', bothbat = '&',neitherbat = '.';
	struct PlayerInfo player;
	struct GameInfo game;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n");
	printf("\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.Symbol);
	printf("Set the number of lives: ");
	scanf("%d", &player.lives);
	while (1 > player.lives || 10 < player.lives)
	{
		printf("     Must be between 1 and 10!\n");
		printf("Set the number of lives: ");
		scanf("%d", &player.lives);
	}
	printf("Player configuration set-up is complete\n");
	printf("\n");
	int a, b;

	printf("GAME Configuration\n");
	printf("------------------\n");
	do {
		a = 1;
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf(" %d", &game.pathlength);
		b = game.pathlength % Multi_of;
		if (game.pathlength > Max_pathlength || game.pathlength < Min_Pathlength || b) {
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
			a = 0;
		}
	} while (a == 0);

	printf("Set the limit for number of moves allowed: ");
	scanf("%d", &game.moves);
	while (player.lives > game.moves || (int)(game.pathlength * 0.75) < game.moves)
	{
		printf("    Value must be between %d and %d\n", player.lives, (int)(game.pathlength * 0.75));
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.moves);
	}
	printf("\n");
	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);
	for (i = 0; i < game.pathlength; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		for (j = i; j < i + 5; j++)
		{
			scanf("%d", &game.bombs[j]);
		}
	}
	printf("BOMB placement set\n");
	printf("\n");
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathlength);
	for (i = 0; i < game.pathlength; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
		for (j = i; j < i + 5; j++)
		{
			scanf("%d", &game.treasure[j]);
		}
	}
	printf("TREASURE placement set\n");
	printf("\n");
	printf("GAME configuration set-up is complete...\n");
	printf("\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.Symbol);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n");
	printf("\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", game.pathlength);
	printf("   Bombs      : ");
	for (i = 0; i < game.pathlength; i++)
	{

		printf("%d", game.bombs[i]);

	}
	printf("\n   Treasure   : ");
	for (i = 0; i < game.pathlength; i++)
	{

		printf("%d", game.treasure[i]);

	}
	printf("\n");
	printf("\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");
	i = 0, j = 1;
	m = 0;
	player.nmber_of_treasure = 0;
	while (1)
	{
		
		if (m == 0)
			++m;
		else
		{
			printf("\n");
			printf("  ");
			for (x = 0; x < game.pathlength; x++) {
				if (player.history[x] == 1 && x == (Next_Moves - 1))
				{																				/*Line zero(player'symbol)*/
					printf("%c", player.Symbol);
				}
				else
					printf(" ");
			}
		}
		printf("\n");
		printf("  ");
		for (x = 0; x < game.pathlength; x++)
		{
			if (player.history[x] == 0)
				printf("%c", undiscovered);
			else if (game.bombs[x] == 1 && game.treasure[x] == 1)
			{
				printf("%c", bothbat);
			}																					/*Line one(symbolic representation)*/
			else if (game.bombs[x] == 1)
			{
				printf("%c", bomb);
			}
			else if (game.treasure[x] == 1)
			{
				printf("%c", treasure);
			}
			else
				printf("%c", neitherbat);
		}
		printf("\n");
		printf("  ");
		for (x = 0; x < game.pathlength; x++)
		{
			if ((x + 1) % 10 == 0)
			{

				++i;
				printf("%d", i);															/*Line two(major)*/
			}
			else
				printf("|");
		}
		i = 0;
		printf("\n");
		printf("  ");
		for (x = 0; x < game.pathlength; x++) {
			if ((x + 1) % 10 == 0)
			{
				printf("0");
				j = 1;																		/*Line three(minor)*/
			}
			else
				printf("%d", j++);
		}
		printf("\n");
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",
			player.lives, player.nmber_of_treasure, game.moves);
		printf("+---------------------------------------------------+\n");
		if (player.lives == 0 || game.moves == 0)
			break;
		while (1) {
			printf("Next Move [1-%d]: ", game.pathlength);
			scanf("%d", &Next_Moves);																		/*Loop for moves in gamepath*/
			if (Next_Moves<1 || Next_Moves > game.pathlength)
				printf("  Out of Range!!!\n");
			else
				break;
		}
		if (player.history[Next_Moves - 1] == 1)
		{
			printf("\n===============> Dope! You've been here before!\n");
		}
		else
		{
			player.history[Next_Moves - 1] = 1;
			game.moves -= 1;
			if (game.bombs[Next_Moves - 1] == 1 && game.treasure[Next_Moves - 1] == 1)
			{
				player.lives -= 1;
				player.nmber_of_treasure += 1;
				printf("\n===============> [&] !!! BOOOOOM !!! [&]");
				printf("\n===============> [&] $$$ Life Insurance Payout!!! [&]\n");						/*Condition for bomb and treasure*/
				if (player.lives == 0)
					printf("\nNo more LIVES remaining!\n");

				else if (game.moves == 0)
					printf("\nNo more MOVES remaining!\n");
			}
			else if (game.bombs[Next_Moves - 1] == 1)
			{
				player.lives -= 1;
				printf("\n===============> [%c] !!! BOOOOOM !!! [%c]\n", bomb, bomb);
				if (player.lives == 0)
					printf("\nNo more LIVES remaining!\n");													/*Condition for bomb*/
				else if (game.moves == 0)
					printf("\nNo more MOVES remaining!\n");
			}
			else if (game.treasure[Next_Moves - 1] == 1)
			{
				player.nmber_of_treasure += 1;
				printf("\n===============> [%c] $$$ Found Treasure! $$$ [%c]\n", treasure, treasure);					/*Condition for  treasure*/
			}
			else {
				printf("\n===============> [%c] ...Nothing found here... [%c]\n", neitherbat, neitherbat);					/*Nothing found*/
			}
		}
	}
	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n");
	printf("\nYou should play again and try to beat your score!");
	return 0;
}
