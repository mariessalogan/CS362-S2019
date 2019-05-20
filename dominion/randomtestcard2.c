
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
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
				sea_hag, tribute, smithy, council_room};
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &G);
		//make sure there are cards in deck

		printf("----------------- Testing CARD: %s ----------------\n", TESTCARD);


		printf("--------- Testing Invalid thisplayer ----------\n");
		printf("-------- Expected outcome: fail if player is bad number ---------\n");
		if(thisplayer > numPlayers && functError == 0)
		{
			printf("FAIL - FUNCTION WORKED WITH INVALID PLAYER\n");
			thisplayer = rand() % numPlayers;
		}
		else if(thisplayer > numPlayers && functError != 0)
		{
			printf("PASS - FUNCTION DID NOT WORK WITH INVALID PLAYER\n");
			thisplayer = rand() % numPlayers;
		}
		else
		{
			printf("TEST NOT NEEDED, PLAYER WAS VALID");
		}
		G.deckCount[thisplayer] = rand() % 21;
		G.handCount[thisplayer] = rand() % 5;
		int checkHandCount = G.handCount[thisplayer] + 3;
		//test on it's ownhandCount[player]++;
		printf("--------- Testing cards in hand ----------\n");
		printf("-------- Expected outcome: cards in hand = 8 ---------\n");
		smithyFunction(thisplayer, &G, handPos);
		if(G.handCount[thisplayer] == checkHandCount)
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
