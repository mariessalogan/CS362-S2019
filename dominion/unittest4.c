
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "getCost"

int main()
{
	printf("-------------------- UNIT TEST 4 -------------------\n\n");

	//used variables from steward test example
	int cardNumber;
    int seed = 1000;
    int numPlayers = 2;
    int functError = -2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);

	//test curse
	cardNumber = curse;
	printf("--------- Testing curse ----------\n");
	printf("-------- Expected outcome: Return cost of 0 ---------\n");
	functError = getCost(cardNumber);
	if(functError == 0)
	{
		printf("PASS - CORRECT COST WAS SENT\n\n");
	}
	else
	{
		printf("FAIL - INCORRECT COST WAS SENT\n\n");
	}

	//test ESTATE
	cardNumber = estate;
	printf("--------- Testing estate ----------\n");
	printf("-------- Expected outcome: Return cost of 2 ---------\n");
	functError = getCost(cardNumber);
	if(functError == 2)
	{
		printf("PASS - CORRECT COST WAS SENT\n\n");
	}
	else
	{
		printf("FAIL - INCORRECT COST WAS SENT\n\n");
	}

	//test duchy
	cardNumber = duchy;
	printf("--------- Testing duchy ----------\n");
	printf("-------- Expected outcome: Return cost of 5 ---------\n");
	functError = getCost(cardNumber);
	if(functError == 5)
	{
		printf("PASS - CORRECT COST WAS SENT\n\n");
	}
	else
	{
		printf("FAIL - INCORRECT COST WAS SENT\n\n");
	}

	//test ESTATE
	cardNumber = estate;
	printf("--------- Testing copper ----------\n");
	printf("-------- Expected outcome: Return cost of 0 ---------\n");
	functError = getCost(cardNumber);
	if(functError == 0)
	{
		printf("PASS - CORRECT COST WAS SENT\n\n");
	}
	else
	{
		printf("FAIL - INCORRECT COST WAS SENT\n\n");
	}

	//test adventurer
	cardNumber = adventurer;
	printf("--------- Testing adventurer ----------\n");
	printf("-------- Expected outcome: Return cost of 6 ---------\n");
	functError = getCost(cardNumber);
	if(functError == 6)
	{
		printf("PASS - CORRECT COST WAS SENT\n\n");
	}
	else
	{
		printf("FAIL - INCORRECT COST WAS SENT\n\n");
	}
	
	//test incorrect input
	cardNumber = (int)"mariessa";
	printf("--------- Testing mariessa ----------\n");
	printf("-------- Expected outcome: error - invalid input ---------\n");
	functError = getCost(cardNumber);
	if(functError == -1 )
	{
		printf("PASS - ERROR FROM INVALID INPUT\n\n");
	}
	else
	{
		printf("FAIL - SHOULD BE AN ERROR FROM INVALID INPUT\n\n");
	}
	return 0;
}