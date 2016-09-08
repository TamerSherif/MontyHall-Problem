include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

int gameMode(int researchMode)
{

	int loops = 1;
	int strategy;
	int wins = 0;
	int losses = 0;
	int count = 0;
	static int totalGame=0, winGame=0;
	if(researchMode == 1)
	{
		printf("Pick a strategy:\n");
		printf("1. Switch strategy\n");
		printf("2. Never switch strategy\n");

		scanf("%d",&strategy);

		printf("How many times would you like the game simulated?\nEnter a positive integer ( > 0 ): ");
		scanf("%d",&loops);
	}
	srand(time(NULL));

	int realDoor;
	int userDoor;
	int switchDoor;
	int openedDoor;
	char shouldSwitch;
	int score;
	//printf("%d\n",door);

	while(count < loops)
	{
	realDoor = rand() % 3 + 1;

	if(!researchMode)
	{
    totalGame++;
	printf("Pick a door! (1-3): ");
	scanf("%d",&userDoor);
	getchar();
	}

	else
	{
		userDoor = rand() % 3 + 1;
	}

	if(realDoor != userDoor)
	{
		if(realDoor == 1)
		{
			if(userDoor == 2)
				openedDoor = 3;
			else
				openedDoor = 2;
		}

		else if(realDoor == 2)
		{
			if(userDoor == 1)
				openedDoor = 3;
			else
				openedDoor = 1;

		}

		else
		{
			if(userDoor == 1)
				openedDoor = 2;
			else
				openedDoor = 1;

		}

		switchDoor = realDoor;
	}

	else
	{
		if(realDoor == 1)
		{
			openedDoor = 2;
			switchDoor = 3;

		}

		else if(realDoor == 2)
		{
			openedDoor = 3;
			switchDoor = 1;
		}

		else
		{
			openedDoor = 2;
			switchDoor = 1;
		}


	}

	if(!researchMode)
	{
	printf("You picked door #%d, but I opened you door #%d which is... empty!\nWould you like to make a switch with door #%d? (Y/N): ",userDoor,openedDoor,switchDoor);
	scanf("%c",&shouldSwitch);

	if(tolower(shouldSwitch) == 'y')
		userDoor = switchDoor;
	}

	else
	{
		if(strategy == 1)
			userDoor = switchDoor;

	}

	if(userDoor == realDoor)
		{
			if(!researchMode)
			{
			printf("You picked the right door! YAY!\n\n");
			score = 1;
			}

			else
			{
			    wins++;
                winGame++;
			}
			//printf("The score is %d\n", score);

		}
	else
		{
			if(!researchMode)
			{

			printf("You picked the wrong door! BOO!\n\n");
			score = 0;

			}
			else
			losses++;
		}

		count++;
	}

	if(researchMode)
	{
		printf("\n\nAfter %d number of simulations:\n",loops);
		printf("Win ratio: %f\n",1.0*wins/loops);
		printf("Loss ratio: %f\n\n",1.0*losses/loops);


	}
	//else
        //printf("You have won %d games out of %d\n", winGame, totalGame);


	return score;


}

int main(void)
{


	int games =0, wins = 0;
	int mode;
	while(1)
	{
	printf("Enter one of the following options");
	printf("\n1. Game Mode");
	printf("\n2. Research Mode");
	printf("\n3. Exit\n");
	printf("Please pick an option from above (1-3): ");

	scanf("%d",&mode);

	switch(mode)
		{
			case 1: wins = wins + gameMode(0);
					games = games + 1;
					printf("You have won %d games out of %d\n", wins, games);
					printf("Win ratio: %f\n",100.0*wins/games);
					break;
			case 2: gameMode(1);
					break;
			case 3: break;
			default: printf("Error. Please pick option 1, 2 or 3\n");
					 break;
		}

		if(mode == 3)
			break;
	}




	printf("Thanks for playing!\n");
	printf("Games played: %d\n",games);
	printf("Games won: %d\n",wins);







	return 0;
}
