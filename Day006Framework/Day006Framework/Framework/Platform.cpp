#include "Platform.h"
#include <cmath>


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
	Entity::Process(deltaTime);

	// Process things relating to this enemy like when it decides to fire.
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