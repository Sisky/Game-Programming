#include "Background.h"

Background::Background()
	: Entity()
{    // Call the constructor of the super class
	 // Construct the Background ship

}

Background::~Background()
{

}

void
Background::Process(float deltaTime)
{
	// Process the Background object
	Entity::Process(deltaTime);
}
