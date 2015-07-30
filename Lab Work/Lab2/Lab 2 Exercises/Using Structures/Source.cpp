#include <iostream>

using namespace std;

struct Player
{
	int xPos;
	int yPos;
	int health;
	bool alive;

};

void SetupPlayer(Player* player)
{
	player->xPos = 0;
	player->yPos = 0;
	player->health = 100;
	player->alive = true;
}

void PrintPlayerDetails(const Player& player)
{
	cout << "Player's Current State" << endl;
	cout << "- Position: (" << player.xPos << ", " << player.yPos << ")" << endl;
	cout << "- Health: " << player.health << endl;
	cout << "- Alive: " << player.alive << endl;



}

int main()
{	
	Player player;
	SetupPlayer(&player);
	PrintPlayerDetails(player);
	return 0;
}