
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main()
{
	printf("-------------------- CARD TEST 4 -------------------\n\n");

	//used variables from steward test example
    int seed = 1000;
    int numPlayers = 2;
	struct gameState G;
	int thisplayer = 0;
	int handPos = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	//make sure there are cards in deck
	G.deckCount[thisplayer] = 2;
	G.handCount[thisplayer] = 5;
	G.numActions = 0;
	printf("----------------- Testing CARD: %s ----------------\n", TESTCARD);

	//test on it's ownhandCount[player]++;
	printf("--------- Testing cards in hand ----------\n");
	printf("-------- Expected outcome: cards in hand = 6 ---------\n");
	villageFunction(thisplayer, &G, handPos);
	if(G.handCount[thisplayer] == 6)
	{
		printf("PASS - CORRECT AMOUNT OF CARDS IN HAND\n\n");
	}
	else
	{
		printf("FAIL - INCORRECT AMOUNT OF CARDS IN HAND\n\n");
	}

//test on it's ownhandCount[player]++;
	printf("--------- Testing number of actions----------\n");
	printf("-------- Expected outcome: actions = 2 ---------\n");

	if(G.numActions == 2)
	{
		printf("PASS - CORRECT AMOUNT OF ACTIONS\n\n");
	}
	else
	{
		printf("FAIL - INCORRECT AMOUNT OF ACTIONS\n\n");
	}



	return 0;
}