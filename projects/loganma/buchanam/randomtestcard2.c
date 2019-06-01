
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#define TESTCARD "smithy"

int main()
{
	

	//used variables from steward test example
    int seed = 10;
    int count = 1;
    do{
	    int numPlayers = rand() % 5;
		struct gameState G;
		int thisplayer = rand() % 5;
		int handPos = rand() % 6;
		int choice1, choice2, choice3 = 2;
		int *bonus = 0;
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		//make sure there are cards in deck
		G.deckCount[thisplayer] = rand() % 5;
		G.handCount[thisplayer] = rand() % 5;
		printf("----------------- Testing CARD: %s ----------------\n", TESTCARD);

		//test on it's ownhandCount[player]++;
		printf("--------- Testing cards in hand ----------\n");
		printf("-------- Expected outcome: cards in hand = 8 ---------\n");
		cardEffect(smithy, choice2, choice3, choice1, &G, thisplayer, bonus);
		if(G.handCount[thisplayer] == 8)
		{
			printf("PASS - CORRECT AMOUNT OF CARDS IN HAND\n\n");
		}
		else
		{
			printf("FAIL - INCORRECT AMOUNT OF CARDS IN HAND\n\n");
		}
		count++;

	}while(count != seed);


	return 0;
}