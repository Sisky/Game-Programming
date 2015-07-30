#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	bool playerXTurn = true;
	bool playerOTurn = false;
	char board[3][3];
	board[0][0] = 'A';
	board[0][1] = 'B';
	board[0][2] = 'C';
	board[1][0] = 'D';
	board[1][1] = 'E';
	board[1][2] = 'F';
	board[2][0] = 'G';
	board[2][1] = 'H';
	board[2][2] = 'I';

	while (true)
	{


		while (playerXTurn)
		{
			cout << "                 " << endl;
			cout << "     |     |     " << endl;
			cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
			cout << "     |     |     " << endl;
			cout << "-----+-----+-----" << endl;
			cout << "     |     |     " << endl;
			cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
			cout << "     |     |     " << endl;
			cout << "-----+-----+-----" << endl;
			cout << "     |     |     " << endl;
			cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
			cout << "     |     |     " << endl;

			cout << "Choose the upper case letter position you wish to place your 'X'" << endl;
			string input = "";
			cin >> input;
			if (input.compare("A") == 0)
			{
				if (board[0][0] == 'A')
				{
					board[0][0] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("B") == 0)
			{
				if (board[0][1] == 'B')
				{
					board[0][1] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("C") == 0)
			{
				if (board[0][2] == 'C')
				{
					board[0][2] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("D") == 0)
			{
				if (board[1][0] == 'D')
				{
					board[1][0] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("E") == 0)
			{
				if (board[1][1] == 'E')
				{
					board[1][1] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("F") == 0)
			{
				if (board[1][2] == 'F')
				{
					board[1][2] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("G") == 0)
			{
				if (board[2][0] == 'G')
				{
					board[2][0] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("H") == 0)
			{
				if (board[2][1] == 'H')
				{
					board[2][1] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("I") == 0)
			{
				if (board[2][2] == 'I')
				{
					board[2][2] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}

		}




		while (playerOTurn)
		{
			cout << "                 " << endl;
			cout << "     |     |     " << endl;
			cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
			cout << "     |     |     " << endl;
			cout << "-----+-----+-----" << endl;
			cout << "     |     |     " << endl;
			cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
			cout << "     |     |     " << endl;
			cout << "-----+-----+-----" << endl;
			cout << "     |     |     " << endl;
			cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
			cout << "     |     |     " << endl;

			cout << "Choose the upper case letter position you wish to place your 'O'" << endl;
			string input = "";
			cin >> input;
			if (input.compare("A") == 0)
			{
				if (board[0][0] == 'A')
				{
					board[0][0] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("B") == 0)
			{
				if (board[0][1] == 'B')
				{
					board[0][1] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("C") == 0)
			{
				if (board[0][2] == 'C')
				{
					board[0][2] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("D") == 0)
			{
				if (board[1][0] == 'D')
				{
					board[1][0] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("E") == 0)
			{
				if (board[1][1] == 'E')
				{
					board[1][1] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("F") == 0)
			{
				if (board[1][2] == 'F')
				{
					board[1][2] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("G") == 0)
			{
				if (board[2][0] == 'G')
				{
					board[2][0] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("H") == 0)
			{
				if (board[2][1] == 'H')
				{
					board[2][1] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("I") == 0)
			{
				if (board[2][2] == 'I')
				{
					board[2][2] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}

		}
	}



	


	return(0);
}
