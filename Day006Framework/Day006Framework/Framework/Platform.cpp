#include "Platform.h"



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