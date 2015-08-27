

// These includes
#include "Enemy.h"
#include "sprite.h"
#include "backbuffer.h"


bool left = true;

Enemy::Enemy()
{
	Entity::Entity();

}
void
Enemy::SetLeft(bool left)
{
	m_left = left;
}

bool
Enemy::IsLeft()
{
	return m_left;
}

Enemy::~Enemy()
{
	Entity::~Entity();
}

void
Enemy::Process(float deltaTime)
{
	//gravity
	m_velocityY = 3.0f;
	
	
	Entity::Process(deltaTime);
}