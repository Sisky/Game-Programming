// 717310 C++ SDL Framework

// This include:
#include "entity.h"

// Local includes:
#include "sprite.h"
#include "backbuffer.h"

// Library includes:
#include <cassert>
#include <cmath>

Entity::Entity()
: m_pSprite(0)
, m_x(0.0f)
, m_y(0.0f)
, m_velocityX(0.0f)
, m_velocityY(0.0f)
, m_dead(false)
{

}

Entity::~Entity()
{

}

bool
Entity::Initialise(Sprite* sprite)
{
	assert(sprite);
	m_pSprite = sprite;

	return (true);
}

void 
Entity::Process(float deltaTime)
{
	m_pSprite->SetX(static_cast<int>(m_x));
	m_pSprite->SetY(static_cast<int>(m_y));

	// : Generic position update, based upon velocity (and time).
	m_x += m_velocityX;
	m_y += m_velocityY;

	// : Boundary checking and position capping. 
	if(m_x > 800)
	{
		// If the entity is going to go out of bounds bonce the entity
		// back along the direction that it hit the boundary
		m_x = 800;
		m_velocityX *= -1.0f;
	}
	else if(m_x < 0)
	{
		m_x = 0;
		m_velocityX *= -1.0f;
	}

	if(m_y > 600)
	{
		m_y = 600;
		m_velocityY *= -1.0f;
	}
	else if(m_y < 0)
	{
		m_y = 0;
		m_velocityY *= -1.0f;
	}
}

void 
Entity::Draw(BackBuffer& backBuffer)
{
	if(!m_dead)
	{
		assert(m_pSprite);
		m_pSprite->Draw(backBuffer);
	}
}

bool
Entity::IsCollidingWith(Entity& e)
{
	// Generic Entity Collision routine.
	float circleRadius = 10.0f;

	float fDistance = sqrt(pow((e.GetPositionX() - m_x), 2.0f) +  pow((e.GetPositionY() - m_y), 2.0f)) - circleRadius*2.0f;;

	// Check for intersection.
	if(fDistance <= 0.0f)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

void 
Entity::SetDead(bool dead)
{
	m_dead = dead;
}

bool 
Entity::IsDead() const
{
	return (m_dead);
}

float 
Entity::GetPositionX()
{
	return (m_x);
}

float 
Entity::GetPositionY()
{
	return (m_y);
}

void 
Entity::SetPositionX(float _fX)
{
	m_x = _fX;
}

void 
Entity::SetPositionY(float _fY)
{
	m_y = _fY;
}

float 
Entity::GetHorizontalVelocity()
{
	return (m_velocityX);
}

float 
Entity::GetVerticalVelocity()
{
	return (m_velocityY);
}

void 
Entity::SetHorizontalVelocity(float x)
{
	m_velocityX = x;
}

void 
Entity::SetVerticalVelocity(float y)
{
	m_velocityY = y;
}
