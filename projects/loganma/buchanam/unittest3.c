
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "isGameOver"

int main()
{
	printf("-------------------- UNIT TEST 3 -------------------\n\n");
	//used variables from steward test example

    int functError = 0;

    int seed = 1000;
    int numPlayers = 2;

	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
	printf("--------- Testing just initialized game for end of game ----------\n");
	printf("-------- Expected outcome: Return Error of -1 ---------\n");
	functError = isGameOver(&G);
	if(functError == 1)
	{
		printf("FAIL - GAME JUST STARTED, SHOULD NOT BE OVER\n\n");
	}
	else
	{
		printf("PASS - GAME JUST STARTED, SHOULD NOT BE OVER\n\n");
	}

	//Set provinces to 0
	G.supplyCount[province] = 0;
	printf("--------- Testing that games end when there are no more provinces ----------\n");
	printf("-------- Expected outcome: Return 1 to signal game is over ---------\n");
	functError = isGameOver(&G);
	if(functError == 1)
	{
		printf("PASS - GAME SHOULD END IF NO MORE PROVINCES LEFT\n\n");
	}
	else
	{
		printf("FAIL - GAME SHOULD END IF NO MORE PROVINCES LEFT\n\n");
	}

	//Set provinces back to a passing number
	G.supplyCount[province] = 2;

	//test that game ends when 3 supply piles are at 0.
	G.supplyCount[0] = 0;
	G.supplyCount[1] = 0;
	G.supplyCount[2] = 0;
	printf("--------- Testing that games end when 3 supply piles are at 0 ----------\n");
	printf("-------- Expected outcome: Return 1 to signal game is over ---------\n");
	functError = isGameOver(&G);
	if(functError == 1)
	{
		printf("PASS - GAME SHOULD END IF NO MORE PROVINCES LEFT\n\n");
	}
	else
	{
		printf("FAIL - GAME SHOULD END IF NO MORE PROVINCES LEFT\n\n");
	}	

	return 0;

}