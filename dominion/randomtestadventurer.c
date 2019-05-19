#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

#define TESTCARD "adventurer"

int main()
{
	srand(time(NULL));

	int seed = 150;
	int i;
	for(i=0; i <= seed; i++)
	{
		int numPlayers = rand() % 5;
		int cardDrawn = rand();
		int drawntreasure = rand() %4;
		int temphand[MAX_HAND];
		int players[MAX_PLAYERS];
		int handPos = rand() % 5;
		struct gameState G;
		struct gameState *state = newGame();
		int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
		kingdomCards(k[0], k[1], k[2], k[3], k[4], k[5], k[6], k[7], k[8], k[9]);
		initializeGame(numPlayers, k, seed, &G);
		//this will be to pick a random plater to add different types of cards to their hand.
		int i;
		//This is to put random cards in that random person's hands
		int j;
		int m;
		for(m = 0; m<10; m++){
			//there are 27 numbers in the card enumerator
			j = rand() % 28;
			int cost = getCost(j);
			i = rand() % 5;
			G.supplyCount[m] = i;

		}
		cardEffect(j, 1, 2, 3, &G, handPos, k);
		//These are needed to add coverage.
		numHandCards(&G);
		scoreFor(i, &G);
		playCard(handPos, i, j, m, &G);
		fullDeckCount(i, j, &G);
		supplyCount(j, &G);
		handCard(handPos, &G);
		endTurn(&G);
		buyCard(handPos, &G);
		isGameOver(&G);
		//test adventurer function
		adventurerFunction(i, &G, temphand, j, m, drawntreasure);
		//test on it's own and make sure drawn treasure is at 2
		printf("--------- Testing Function on it's own ----------\n");
		printf("-------- Expected outcome: drawntreasure = 2 ---------\n");
		
		if(drawntreasure == (drawntreasure + 2))
		{
			printf("PASS - DRAWNTREASURE IS CORRECT VALUE\n\n");
		}
		else
		{
			printf("FAIL - DRAWNTREASURE IS INCORRECT VALUE\n\n");
		}
		int winner = getWinners(players, &G);
		if(winner == i)
		{
			printf("PASS - WINNER IS CORRECT");
		}
		else
		{
			printf("FAIL - WINNER IS INCORRECT");
		}
	}
	
	return 0;
}