#include "Platform.h"
#include <cmath>


// Local includes:
#include "sprite.h"
#include "backbuffer.h"


Platform::Platform()
{
	Entity::Entity();

}


Platform::~Platform()
{
	Entity::~Entity();
}

void
Platform::Process(float deltaTime)
{
	m_pSprite->SetX(static_cast<int>(m_x));
	m_pSprite->SetY(static_cast<int>(m_y));

	// : Generic position update, based upon velocity (and time).
	m_x += m_velocityX;
	m_y += m_velocityY;

	// : Boundary checking and position capping. 



}
bool
Platform::IsCollidingWith(Entity& e)
{

	float rectWidth = 36.0f;
	//no colliding default
	float fDistance =1.0f;
	//rectangle collision
	if (m_x < e.GetPositionX()+ rectWidth 
		&& m_x + rectWidth > e.GetPositionX() 
		&& m_y < e.GetPositionY() + rectWidth 
		&& rectWidth + m_y > e.GetPositionY())
	{
		fDistance = 0.0f;
	}

	// Check for intersection.
	if (fDistance <= 0.0f)
	{
		return (true);
		
	}
	else
	{
		return (false);
	}
}