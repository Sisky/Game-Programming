#include "Player.h"
#include <iostream>

int main()
{
	Player* pPlayer = 0;
	pPlayer = new Player();
	
	pPlayer->printStats();

	return(0);
}