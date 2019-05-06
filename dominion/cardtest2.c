
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "gardens"

int main()
{
	printf("-------------------- CARD TEST 2 -------------------\n\n");

	//used variables from steward test example
    int seed = 1000;
    int numPlayers = 2;
    int functError = -2;
	struct gameState G;
	int thisplayer = 0;

	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	//make sure there are cards in deck
	G.deckCount[thisplayer] = 2;
	G.handCount[thisplayer] = 5;
	printf("----------------- Testing CARD: %s ----------------\n", TESTCARD);

	//test on it's ownhandCount[player]++;
	printf("--------- Testing Return Value ----------\n");
	printf("-------- Expected outcome: return value = 0 ---------\n");
	functError = gardensFunction(thisplayer, &G);
	if(functError == 0)
	{
		printf("PASS - RETURN VALUE IS 0\n\n");
	}
	else
	{
		printf("FAIL - RETURN VALUE IS NOT 0\n\n");
	}


	printf("--------- Testing Hand Count value ----------\n");
	printf("-------- Expected outcome: hand count stayed 5 ---------\n");

	if(G.handCount[thisplayer] == 5)
	{
		printf("PASS - HAND COUNT WAS NOT AFFECTED\n\n");
	}
	else
	{
		printf("FAIL - HAND COUNT WAS AFFECTED\n\n");
	}




	return 0;
}