/***********************************************************************
Name: Mariessa Logan
Date 5/5/19
Description: this tests the game initializer to make sure the dominion
game initializes correctly
***********************************************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTFUNCTION "initializeGame"

int main()
{
	printf("-------------------- UNIT TEST 1 -------------------\n\n");
	//used variables from steward test example
	    
    int seed = 1000;
    int numPlayers = -1;
    
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	int initError = 0;

	printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
	printf("--------- Testing negative number of players ----------\n");
	printf("-------- Expected outcome: Return Error of -1 ---------\n");
	initError = initializeGame(numPlayers, k, seed, &G);
	if(initError != -1)
	{
		printf("FAIL - GAME INITIALIZED WITH NEGATIVE NUMBER OF PLAYERS\n\n");
	}
	else
	{
		printf("PASS - GAME DID NOT INITIALIZE WITH NEGATIVE NUMBER OF PLAYERS\n\n");
	}

	//max players is set to 4 in dominion.h, make sure it won't initialize with more
	numPlayers = 5;
	printf("--------- Testing over max number of players ----------\n");
	printf("-------- Expected outcome: Return Error of -1 ---------\n");
	initError = initializeGame(numPlayers, k, seed, &G);
	if(initError != -1)
	{
		printf("FAIL - GAME INITIALIZED WITH OVER MAX NUMBER OF PLAYERS\n\n");
	}
	else
	{
		printf("PASS - GAME DID NOT INITIALIZE WITH OVER NUMBER OF PLAYERS\n\n");
	}

	//Now we are going to test that the selected kingdom cards that were initialized
	k[2] = smithy;
	printf("-------- Testing invalid array of kingdom cards --------\n");
	printf("----- Expected outcome: game should not initialize -----\n");
	if(initError != -1)
	{
		printf("PASS - GAME DID NOT INITIALIZE WITH INVALID ARRAY OF KINGDOM CARDS\n\n");
	}
	else
	{
		printf("FAIL - GAME INITIALIZED WITH INVALID ARRAY OF KINGDOM CARDS\n\n");
	}
	return 0;
	k[2] = embargo;


	//make sure game initializes within set player range
	numPlayers = 2;
	printf("--------- Testing correct number of players ----------\n");
	printf("------ Expected outcome: game should initialize ------\n");
	initError = initializeGame(numPlayers, k, seed, &G);	
	if(initError != -1)
	{
		printf("FAIL - GAME DID NOT INITIALIZE WITH IN RANGE NUMBER OF PLAYERS\n\n");
	}
	else
	{
		printf("PASS - GAME INITIALIZED WITH IN RANGE NUMBER OF PLAYERS\n\n");
	}
	return 0;


}