#include "Bullet.h"

Bullet::Bullet()
{
	Entity::Entity();
}

Bullet::~Bullet()
{
	Entity::~Entity();
}

void 
Bullet::Process(float deltatick)
{
	if(m_y >= 600.0f || m_y <= 0.0f)
	{
		m_dead = true;
	}

	Entity::Process(deltatick);
}