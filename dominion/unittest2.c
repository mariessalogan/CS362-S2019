
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "buyCard"

int main()
{
	printf("-------------------- UNIT TEST 2 -------------------\n\n");
	//used variables from steward test example

  
    int seed = 1000;
    int numPlayers = -1;

	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	int functError = 0;
	int supplyPos = 0;
	//make sure that it needs game to initialize to run
	printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
	printf("--------- Testing uninitialized game ----------\n");
	printf("-------- Expected outcome: Return Error of -1 ---------\n");
	functError = buyCard(supplyPos, &G);
	if(functError == 0)
	{
		printf("FAIL - GAME WAS NOT INITIALIZED AND BUY CARD STILL RAN\n\n");
	}
	else
	{
		printf("PASS - GAME WAS NOT INITIALIZED SO BUYCARD DID NOT RUN\n\n");
	}
	initializeGame(numPlayers, k, seed, &G);

	//Test that supplyPos has to be a valid position
	
	printf("------------ Testing invalid supplyPos -------------\n");
	printf("-------- Expected outcome: Return Error of -1 ---------\n");
	functError = buyCard(supplyPos, &G);
	if(functError == 0)
	{
		printf("FAIL - SUPPLYPOS WAS INVALID, SHOULD NOT HAVE ALLOWED THAT BUY\n\n");
	}
	else
	{
		printf("PASS - SUPPLYPOS WAS INVALID AND IT DIDN'T ALLOW A BUY\n\n");
	}

	//Test that supplyPos has to be a valid position
	supplyPos = 1;
	printf("------------ Testing valid supplyPos -------------\n");
	printf("-------- Expected outcome: correctly run ---------\n");
	functError = buyCard(supplyPos, &G);
	if(functError != 0)
	{
		printf("FAIL - SUPPLYPOS WAS VALID, SHOULD HAVE ALLOWED THAT BUY\n\n");
	}
	else
	{
		printf("PASS - SUPPLYPOS WAS VALID AND IT ALLOWED A BUY\n\n");
	}

	return 0;
}