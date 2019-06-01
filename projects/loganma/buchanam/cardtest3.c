
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main()
{
	printf("-------------------- CARD TEST 3 -------------------\n\n");

	//used variables from steward test example
    int seed = 1000;
    int numPlayers = 2;
	struct gameState G;
	int thisplayer = 0;
	int handPos = 0;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	int choice1, choice2, choice3 = 2;
	int *bonus = 0;
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
	//make sure there are cards in deck
	G.deckCount[thisplayer] = 2;
	G.handCount[thisplayer] = 5;
	printf("----------------- Testing CARD: %s ----------------\n", TESTCARD);

	//test on it's ownhandCount[player]++;
	printf("--------- Testing cards in hand ----------\n");
	printf("-------- Expected outcome: cards in hand = 8 ---------\n");
	cardEffect(smithy, choice3, choice2, choice1, &G, handPos, bonus);
	if(G.handCount[thisplayer] == 8)
	{
		printf("PASS - CORRECT AMOUNT OF CARDS IN HAND\n\n");
	}
	else
	{
		printf("FAIL - INCORRECT AMOUNT OF CARDS IN HAND\n\n");
	}




	return 0;
}