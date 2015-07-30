#include <iostream>
#include <string>

using namespace std;

void draw(char* board);

bool checkBoardFull(char* board)
{
	if (board[0] != 'A' && board[1] != 'B' && board[2] != 'C' && board[3] != 'D' && board[4] != 'E' && board[5] != 'F' && board[6] != 'G' && board[7] != 'H' && board[8] != 'I')
	{
		cout << "Game is a draw. No more possible moves" << endl;
		draw(board);
		return true;
	}
	else
		return false;
}

bool checkForWin(char* board)
{
	//horizontals
	if (board[0] == board[1] && board[1] == board[2])
	{
		cout << "Player " << board[0] << " wins!";
		cout << "                 " << endl;
		cout << "     |     |     " << endl;
		cout << "==" << board[0] << "==|==" << board[1] << "==|==" << board[2] << "==" << endl;
		cout << "     |     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
		cout << "     |     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
		cout << "     |     |     " << endl;
		return true;
	}
	else if (board[3] == board[4] && board[4] == board[5])
	{
		cout << "Player " << board[3] << " wins!";
		cout << "                 " << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
		cout << "     |     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |     " << endl;
		cout << "==" << board[3] << "==|==" << board[4] << "==|==" << board[5] << "==" << endl;
		cout << "     |     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
		cout << "     |     |     " << endl;
		return true;
	}
	else if ((board[6] == board[7] && board[7] == board[8]))
	{
		cout << "Player " << board[6] << " wins!";
		cout << "                 " << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
		cout << "     |     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |     " << endl;
		cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
		cout << "     |     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |     " << endl;
		cout << "==" << board[6] << "==|==" << board[7] << "==|==" << board[8] << "==" << endl;
		cout << "     |     |     " << endl;
		return true;
	}
	//check verticles
	else if ((board[0] == board[3] && board[3] == board[6]))
	{

		cout << "Player " << board[0] << " wins!";
		cout << "                 " << endl;
		cout << "  =  |     |     " << endl;
		cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
		cout << "  =  |     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "  =  |     |     " << endl;
		cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
		cout << "  =  |     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "  =  |     |     " << endl;
		cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
		cout << "  =  |     |     " << endl;
		return true;
	}
	else if ((board[1] == board[4] && board[4] == board[7]))
	{

		cout << "Player " << board[1] << " wins!";
		cout << "        =        " << endl;
		cout << "     |  =  |     " << endl;
		cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
		cout << "     |  =  |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |  =  |     " << endl;
		cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
		cout << "     |  =  |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |  =  |     " << endl;
		cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
		cout << "     |  =  |     " << endl;
		return true;
	}
	else if ((board[2] == board[5] && board[5] == board[8]))
	{

		cout << "Player " << board[2] << " wins!";
		cout << "              =  " << endl;
		cout << "     |     |  =  " << endl;
		cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
		cout << "     |     |  =  " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |  =  " << endl;
		cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
		cout << "     |     |  =  " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |  =  " << endl;
		cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
		cout << "     |     |  =  " << endl;
		return true;
	}
	//diagonals
	else if ((board[0] == board[4] && board[4] == board[8]))
	{

		cout << "Player " << board[0] << " wins!";
		cout << "                 " << endl;
		cout << " =   |     |     " << endl;
		cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
		cout << "    =|     |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     | =   |     " << endl;
		cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
		cout << "     |    =|     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |     |=    " << endl;
		cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
		cout << "     |     |   = " << endl;
		return true;
	}
	else if ((board[2] == board[4] && board[4] == board[6]))
	{

		cout << "Player " << board[2] << " wins!";
		cout << "                 " << endl;
		cout << "     |     |   = " << endl;
		cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
		cout << "     |     | =   " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "     |    =|     " << endl;
		cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
		cout << "     |=    |     " << endl;
		cout << "-----+-----+-----" << endl;
		cout << "    =|     |     " << endl;
		cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
		cout << "=    |     |     " << endl;
		return true;
	}
	else
		return false;
}


void draw(char* board)
{
	cout << "                 " << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
	cout << "     |     |     " << endl;
	cout << "-----+-----+-----" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
	cout << "     |     |     " << endl;
	cout << "-----+-----+-----" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
	cout << "     |     |     " << endl;
}

int main(int argc, char* argv[])
{
	bool playerXTurn = true;
	bool playerOTurn = false;
	char board[9];
	board[0] = 'A';
	board[1] = 'B';
	board[2] = 'C';
	board[3] = 'D';
	board[4] = 'E';
	board[5] = 'F';
	board[6] = 'G';
	board[7] = 'H';
	board[8] = 'I';

	while (true)
	{
		while (playerXTurn)
		{
			//draw the board
			draw(board);

			cout << "Choose the upper case letter position you wish to place your 'X'" << endl;
			string input = "";
			cin >> input;
			if (input.compare("A") == 0)
			{
				if (board[0] == 'A')
				{
					board[0] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("B") == 0)
			{
				if (board[1] == 'B')
				{
					board[1] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("C") == 0)
			{
				if (board[2] == 'C')
				{
					board[2] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("D") == 0)
			{
				if (board[3] == 'D')
				{
					board[3] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("E") == 0)
			{
				if (board[4] == 'E')
				{
					board[4] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("F") == 0)
			{
				if (board[5] == 'F')
				{
					board[5] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("G") == 0)
			{
				if (board[6] == 'G')
				{
					board[6] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("H") == 0)
			{
				if (board[7] == 'H')
				{
					board[7] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			else if (input.compare("I") == 0)
			{
				if (board[8] == 'I')
				{
					board[8] = 'X';
					playerXTurn = false;
					playerOTurn = true;
				}
			}
			if (checkForWin(board))
			{
				playerXTurn = false;
				playerOTurn = false;
			}
			else if (checkBoardFull(board))
			{
				playerXTurn = false;
				playerOTurn = false;
			}

		}




		while (playerOTurn)
		{

			//draw the board
			draw(board);

			cout << "Choose the upper case letter position you wish to place your 'O'" << endl;
			string input = "";
			cin >> input;
			if (input.compare("A") == 0)
			{
				if (board[0] == 'A')
				{
					board[0] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("B") == 0)
			{
				if (board[1] == 'B')
				{
					board[1] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("C") == 0)
			{
				if (board[2] == 'C')
				{
					board[2] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("D") == 0)
			{
				if (board[3] == 'D')
				{
					board[3] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("E") == 0)
			{
				if (board[4] == 'E')
				{
					board[4] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("F") == 0)
			{
				if (board[5] == 'F')
				{
					board[5] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("G") == 0)
			{
				if (board[6] == 'G')
				{
					board[6] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("H") == 0)
			{
				if (board[7] == 'H')
				{
					board[7] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			else if (input.compare("I") == 0)
			{
				if (board[8] == 'I')
				{
					board[8] = 'O';
					playerXTurn = true;
					playerOTurn = false;
				}
			}
			if (checkForWin(board))
			{
				playerXTurn = false;
				playerOTurn = false;
			}
			else if (checkBoardFull(board))
			{
				playerXTurn = false;
				playerOTurn = false;
			}
		}
	}



	


	return(0);
}
