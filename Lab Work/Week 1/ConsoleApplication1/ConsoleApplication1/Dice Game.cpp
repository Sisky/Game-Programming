#include <stdio.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

void winCondition(int airoll1, int airoll2, int playerroll1, int playerroll2);


//Taken from slides. gets a random dice roll
int roll()
{
	int diceRoll = 0;
	diceRoll = (rand() % 6) + 1;
	return diceRoll;
}
int secondRoll()
{
	int diceRoll = 0;
	diceRoll = (rand() % 6) + 1;
	return diceRoll;
}

int* aiRoll()
{
	int roll1 = 0;
	int roll2 = 0;

	roll1 = roll();
	roll2 = secondRoll();


	
	int output[] = { roll1, roll2 };
	return output;
}

int* aiRollCheat()
{
	int roll1 = 0;
	int roll2 = 0;

	roll1 = roll();
	if (roll1 <= 3)
	{
		int diceRoll = 0;
		diceRoll = (rand() % 2 + 1);
		if (diceRoll == 0)
		{
			roll2 = roll1;
		}

	}
	else
	{
		roll2 = secondRoll();
	}
}

int* playerRoll()
{
	int roll1 = 0;
	int roll2 = 0;

	roll1 = roll();
	roll2 = secondRoll();

	int output[] = { roll1, roll2 };
	return output;


}

void run()
{
	while (true)
	{
		int *aiRolls = new int[2];
		int *playerRolls = new int[2];
		int aiRoll1 = 0;
		int aiRoll2 = 0;
		int playerRoll1 = 0;
		int playerRoll2 = 0;


		cout << "Type 'start' to start game or 'sim' to run a simulation" << endl;
		string inputKey = "";
		cin >> inputKey;
		if (inputKey.compare("sim"))
		{
			statReporter();
		}
		if ((inputKey.compare("start")) == 0)
		{
			aiRolls = aiRoll();
			int aiRoll1 = aiRolls[0];
			int aiRoll2 = aiRolls[1];
			cout << "The AI rolled a " << aiRolls[0] << " and a " << aiRolls[1] << endl;
			bool playerTurn = true;
			while (playerTurn)
			{
				cout << "Type 'roll' to roll your dice" << endl;
				string inputKey = "";
				cin >> inputKey;
				if ((inputKey.compare("roll")) == 0)
				{
					playerRolls = playerRoll();
					int playerRoll1 = playerRolls[0];
					int playerRoll2 = playerRolls[1];
					cout << "You rolled a " << playerRolls[0] << " and a " << playerRolls[1] << endl;
					winCondition(aiRoll1, aiRoll2, playerRoll1, playerRoll2);
					playerTurn = false;
				}
			}
		}
	}
}
void winCondition(int aiRoll1, int aiRoll2, int playerRoll1, int playerRoll2)
{
	int aiTotal = 0;
	int playerTotal = 0;

	aiTotal = aiRoll1 + aiRoll2;
	playerTotal = playerRoll1 + playerRoll2;
	

	//checks if AI has a pair
	if (aiRoll1 == aiRoll2)
	{
		//checks if player has a pair
		if (playerRoll1 == playerRoll2)
		{
			//if both have a pair that is the same game is a draw.
			if (aiTotal == playerTotal)
			{
				cout << "Game is a draw" << endl;
				
			}
			//if ai has higher pair
			else if (aiTotal > playerTotal)
			{
				cout << "AI player wins" << endl;
				
			}
			//player has higher pair.
			else
			{
				cout << "Player wins" << endl;
				
			}

		}
		else
		{
			cout << "AI player wins" << endl;
			
		}
	}
	//check if player has a pair
	else if (playerRoll1 == playerRoll2)
	{
		cout << "Player wins" << endl;
		
	}
	else
	{
		if (aiTotal == playerTotal)
		{
			cout << "Game is a draw" << endl;
			
		}
		else if (aiTotal > playerTotal)
		{
			cout << "AI player wins" << endl;
			
		}
		else
		{
			cout << "Player wins" << endl;
			
		}
	}

}
void statReporter()
{
	cout << "Type number of times you want simuation to run" << endl;
	int input = 0;
	cin >> input;
	int aiWins = 0;
	int playerWins = 0; 

	while (input > 0)
	{

	}
}

int main(int argc, char* argv[])
{
	srand(time(0));
	run();
	return(0);
}
