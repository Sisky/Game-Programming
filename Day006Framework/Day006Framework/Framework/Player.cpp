
#include "Player.h"

Player::Player()
	: Entity()
{    // Call the constructor of the super class
	// Construct the player ship
	
}

Player::~Player()
{

}

void 
Player::Process(float deltaTime)
{
	// Process the Player object
	Entity::Process(deltaTime);
}
