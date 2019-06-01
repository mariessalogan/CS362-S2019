
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main()
{
	printf("-------------------- CARD TEST 1 -------------------\n\n");

	//used variables from steward test example
    int seed = 1000;
    int numPlayers = 2;
    int functError = -2;
	struct gameState G;
	int thisplayer = 0;
	int temphand[MAX_HAND];
	int cardDrawn =0;
	int z =0;
	int drawntreasure = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	int choice1, choice2, choice3 = 2;
	int *bonus = 0;

	printf("----------------- Testing CARD: %s ----------------\n", TESTCARD);

	//test on it's own
	printf("--------- Testing Function on it's own ----------\n");
	printf("--------- z needs to be incremented, but decremented back to 0 ----------\n");
	printf("-------- Expected outcome: z = 0 ---------\n");
	functError = cardEffect(adventurer, choice1, choice2, choice3, &G, cardDrawn, bonus);
	if(functError == 0)
	{
		printf("PASS - Z IS CORRECT VALUE\n\n");
	}
	else
	{
		printf("FAIL - Z IS INCORRECT VALUE\n\n");
	}

	//test on it's own and make sure drawn treasure is at 2
	printf("--------- Testing Function on it's own ----------\n");
	printf("-------- Expected outcome: drawntreasure = 2 ---------\n");
	
	if(drawntreasure == 2)
	{
		printf("PASS - DRAWNTREASURE IS CORRECT VALUE\n\n");
	}
	else
	{
		printf("FAIL - DRAWNTREASURE IS INCORRECT VALUE\n\n");
	}



	return 0;
}