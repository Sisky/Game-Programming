#include <stdio.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>

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
	//init values
	int aiTot = 0;
	int playerTot = 0;
	int aiRoll1 = 0;
	int aiRoll2 = 0;
	int playerRoll1 = 0;
	int playerRoll2 = 0;
	//make sure never a draw
	do {
		aiRoll1 = roll();
		aiRoll2 = roll();
		playerRoll1 = roll();
		playerRoll2 = roll();
		aiTot = aiRoll1 + aiRoll2;
		playerTot = playerRoll1 + playerRoll2;
		if (aiTot != playerTot)
			break;
	} while (true);
	//ai is going to win
	if (aiWin)
	{
		//ai rolls a pair
		if (aiRoll1 == aiRoll2)
		{
			//player rolls a pair
			if (playerRoll1 == playerRoll2)
			{
				//both have pairs AIs is better
				if (aiTot > playerTot)
				{
					cout << "Player has rolled a " << playerRoll1 << " and a " << aiRoll2 << endl;
					cout << "AI has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
					cout << "AI wins!" << endl;
				}
				//both have pairs players is better
				else
				{
					cout << "Player has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
					cout << "AI has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
					cout << "AI wins!" << endl;
				}
			}
			//player didn't roll a pair
			else
			{
				cout << "Player has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
				cout << "AI has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
				cout << "AI wins!" << endl;
			}
		}
		//ai dosen't roll a pair
		else
		{
			//player rolled a pair
			if (playerRoll1 == playerRoll2)
			{
				cout << "Player has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
				cout << "AI has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
				cout << "AI wins!" << endl;
			}
			//ai rolled better non pair
			else if (aiTot > playerTot)
			{
				cout << "Player has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
				cout << "AI has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
				cout << "AI wins!" << endl;
			}
			//player rolled better
			else
			{
				cout << "Player has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
				cout << "AI has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
				cout << "AI wins!" << endl;
			}
		}

	}
	//player is going to win
	else
	{
		//ai rolls a pair
		if (aiRoll1 == aiRoll2)
		{
			//player rolls a pair
			if (playerRoll1 == playerRoll2)
			{
				//both have pairs AIs is better
				if (aiTot > playerTot)
				{
					cout << "Player has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
					cout << "AI has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
					cout << "Player wins!" << endl;
				}
				//both have pairs players is better
				else
				{
					cout << "Player has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
					cout << "AI has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
					cout << "Player wins!" << endl;
				}
			}
			//player didn't roll a pair
			else
			{
				cout << "Player has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
				cout << "AI has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
				cout << "Player wins!" << endl;
			}
		}
		//ai dosen't roll a pair
		else
		{
			//player rolled a pair
			if (playerRoll1 == playerRoll2)
			{
				cout << "Player has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
				cout << "AI has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
				cout << "Player wins!" << endl;
			}
			//ai rolled better non pair
			else if (aiTot > playerTot)
			{
				cout << "Player has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
				cout << "AI has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
				cout << "Player wins!" << endl;
			}
			//player rolled better
			else
			{
				cout << "Player has rolled a " << playerRoll1 << " and a " << playerRoll2 << endl;
				cout << "AI has rolled a " << aiRoll1 << " and a " << aiRoll2 << endl;
				cout << "Player wins!" << endl;
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
		if (inputKey.compare("play") == 0)
		{
			bool aiWins = aiWin();
			aiTurnFirst(aiWins);
		}
		else if (inputKey.compare("sim") == 0)
		{
			int num = 0;
			string input = "";
			int aiPercent = 0;
			cout << "please enter the number of times you want the simulation to run:";
			while (true)
			{
				getline(cin, input);
				stringstream myStream(input);
				if (myStream >> num)
					break;
			}
			for (int i = 0; i < num; i++)
			{
				bool aiWins = aiWin();
				aiTurnFirst(aiWins);
				if (aiWins)
					aiPercent++;
			}
			float percent = (float)aiPercent / (float)num * 100;
			cout << "The AI won " << aiPercent << " times out of " << num << " that is " << percent << " percent! " << endl;
		}
		else if (inputKey.compare("quit") == 0)
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