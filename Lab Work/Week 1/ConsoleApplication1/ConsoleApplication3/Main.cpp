#include <stdio.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

//Roll a fair dice
int roll()
{
	int roll = 0;
	roll = (rand() % 6) + 1;
	return roll;
}

//Decides whether the AI is going to win. 70% chance
bool aiWin()
{
	int roll = 0;
	roll = (rand() % 10) + 1;
	if (roll <= 7)
		return true;
	else
		return false;
}

//Ai's turn. Pre determined win or loss
void aiTurnFirst(bool aiWin)
{
	int aiRoll1 = roll();
	int aiRoll2 = roll();
	int playerRoll1 = roll();
	int playerRoll2 = roll();
	//Ai is going to win
	if (aiWin)
	{
		//if rolls are a pair
		if (aiRoll1 == aiRoll2)
		{
			//if player rolls are a pair
			if (playerRoll1 == playerRoll2)
			{
				if ((aiRoll1 + aiRoll2) > (playerRoll1 + playerRoll2))
				{
					cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
					cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl; 
					cout << "AI player wins!" << endl;
				}
				//change players roll to no pair
				else
				{
					if (playerRoll1 == 1)
					{
						playerRoll1++;
						cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
						cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl;
						cout << "AI player wins!" << endl;
					}
					//player roll 1 is between 2 and 6. -- to create non pair.
					else 
					{
						playerRoll1--;
						cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
						cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl;
						cout << "AI player wins!" << endl;
					}
				}
			}
			//ai rolls aren't a pair.
			else
			{
				//if players rolls are a pair change them
				if (playerRoll1 == playerRoll2)
				{
					if (playerRoll1 == 1)
					{
						aiRoll1 = aiRoll2;
						playerRoll1++;
						cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
						cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl;
						cout << "AI player wins!" << endl;
					}
					//player roll 1 is between 2 and 6. -- to create non pair.
					else
					{
						aiRoll1 = aiRoll2;
						playerRoll1--;
						cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
						cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl;
						cout << "AI player wins!" << endl;
					}
				}
			}
		}
	}
	//Player wins
	else
	{
		//if rolls are a pair
		if (playerRoll1 == playerRoll2)
		{
			//if ai rolls are a pair
			if (aiRoll1 == aiRoll2)
			{
				if ((playerRoll1 + playerRoll2) > (aiRoll1 + aiRoll2))
				{
					cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
					cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl; 
					cout << "Player wins!" << endl;
				}
				//change ai roll to no pair
				else
				{
					if (aiRoll1 == 1)
					{
						aiRoll1++;
						cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
						cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl;
						cout << "Player wins!" << endl;
					}
					//player roll 1 is between 2 and 6. -- to create non pair.
					else 
					{
						aiRoll1--;
						cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
						cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl;
						cout << "Player wins!" << endl;
					}
				}
			}
			//player rolls aren't a pair.
			else
			{
				//if ai rolls are a pair change them
				if (aiRoll1 == aiRoll2)
				{
					if (aiRoll1 == 1)
					{
						playerRoll1 = playerRoll2;
						playerRoll1++;
						cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
						cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl;
						cout << "Player wins!" << endl;
					}
					//ai roll 1 is between 2 and 6. -- to create non pair.
					else
					{
						playerRoll1 = playerRoll2;
						aiRoll1--;
						cout << "AI player rolled a " << aiRoll1 << " and a " << aiRoll2 << "." << endl;
						cout << "Player rolled a " << playerRoll1 << "and a " << playerRoll2 << "." << endl;
						cout << "Player wins!" << endl;
					}
				}
			}
		}
	}
	}

}

//Player's turn. Pre determined win or loss
void playerTurnFirst(bool aiWin)
{
	int playerRoll1 = roll();
	int playerRoll2 = roll();
}

void run() 
{
	bool gameRunning = true;
	bool playersTurn = true;

	//While player still wants to play the game
	while (gameRunning)
	{
		//pre determine who is going to win
		
		cout << "Type 'play' to start game 'sim' to run a simulation, quit to end game" << endl;
		string inputKey = "";
		cin >> inputKey;
		if (inputKey.compare("play"))
		{
			bool aiWins = aiWin();
			aiTurnFirst(aiWins);
		}
		else if(inputKey.compare("sim"))
		{
			cout << "bep bop" << endl;
		}
		else if(inputKey.compare("quit"))
		{
			gameRunning = false;
		}
	}
}


int main(int argc, char* argv[])
{
	srand(time(0));
	run();
	return(0);
}