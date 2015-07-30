#include <iostream>
#include <ctime>

using namespace std;

void rollTwoDice(int& die1, int& die2);

int main()
{
	srand(time(0));
	// Declare two local integers, representing the two dice.
	// Set each dice to hold a value of zero.
	int die1 = 0;
	int die2 = 0;
	// Print out the contents of the two dice after the call.
	cout << "First roll: " << die1 << " Second roll: " << die2 << endl;
	// Call rollTwoDice with the local dice variables.
	rollTwoDice(die1, die2);
	// Print out the contents of the two dice after the call.
	cout << "First roll: " << die1 << " Second roll: " << die2 << endl;
	
	return 0;
}
void rollTwoDice(int& die1, int& die2)
{
	die1 = (rand() % 6) + 1;
	die2 = (rand() % 6) + 1;

}