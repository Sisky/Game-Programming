

// These includes
#include "Enemy.h"
#include "sprite.h"
#include "backbuffer.h"

float patrolTimer = 300.0f;
bool left = true;

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
	if (patrolTimer > 0)
	{
		patrolTimer--;
	}
	else
	{
		left = !left;
		patrolTimer = 300.0f;
	}
	if (left)
	{
		m_velocityX = -1.0f;
	}
	else
	{
		m_velocityX = 1.0f;
	}
	Entity::Process(deltaTime);
}