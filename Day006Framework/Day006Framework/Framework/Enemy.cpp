

// These includes
#include "Enemy.h"


Enemy::Enemy()
{
	Entity::Entity();

}

Enemy::~Enemy()
{
	Entity::~Entity();
}

void
Enemy::Process(float deltaTime)
{
	Entity::Process(deltaTime);

	// Process things relating to this enemy like when it decides to fire.
}