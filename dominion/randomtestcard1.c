
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "gardens"

int main()
{
	printf("-------------------- CARD TEST RANDOM -------------------\n\n");

	//used variables from steward test example
    int seed = 10;
    int count = 1;
    srand(time(NULL));
    do{
    	count++;
	    int numPlayers = rand() % 5;
	    int functError = -2;
		struct gameState G;
		int thisplayer = rand() % 5;

		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		//make sure there are cards in deck
		G.deckCount[thisplayer] = rand() % 21;
		G.handCount[thisplayer] = rand() % 6;
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
	}while(count != seed);



	return 0;
}