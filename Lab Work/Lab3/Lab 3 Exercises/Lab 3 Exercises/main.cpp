#include "Player.h"

#include <iostream>

int main()
{
	Player player;
	player.printStats();

	player.setExperience(50);
	player.setHealth(200);
	player.setRageLevel(100);

	std::cout << "Experience: " << player.getExperience() << std::endl;
	std::cout << "Health: " << player.getHealth() << std::endl;
	std::cout << "Rage Level: " << player.getRageLevel() << std::endl;

	player.printStats();


	return(0);
}