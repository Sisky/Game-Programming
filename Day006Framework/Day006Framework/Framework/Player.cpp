
#include "Player.h"
#include "sprite.h"
#include "backbuffer.h"



Player::Player()
	: Entity()
{    // Call the constructor of the super class
	// Construct the player ship
	jumping = false;
	jumpTimer = -1;
	m_left = false;

}

Player::~Player()
{

}

void 
Player::SetLeft(bool left)
{
	m_left = left;
}

bool
Player::IsLeft()
{
	return m_left;
}


void
Player::SetJumpTimer(float timer)
{
	jumpTimer = timer;
}
void
Player::SetJumping(bool jump)
{
	if (jump)
	{
		m_velocityY = -2.0f;
		jumpTimer = 100.0f;
		jumping = true;
	}
	else
	{
		m_velocityY = 2.0f;
		jumping = true;
	}
}
bool
Player::IsJumping()
{
	return jumping;
}
void 
Player::Process(float deltaTime)
{
	m_pSprite->SetX(static_cast<int>(m_x));
	m_pSprite->SetY(static_cast<int>(m_y));

	// : Generic position update, based upon velocity (and time).
	m_x += m_velocityX;
	m_y += m_velocityY;


	
	// : Boundary checking and position capping. 
	if (m_x > 800)
	{
		// If the entity is going to go out of bounds bonce the entity
		// back along the direction that it hit the boundary
		m_x = 800;
		m_velocityX *= -1.0f;
	}
	else if (m_x < 0)
	{
		m_x = 0;
		m_velocityX *= -1.0f;
	}

	if (m_y > 600)
	{
		m_x = 0;
		m_y = 0;
		
	}
	else if (m_y < 0)
	{
		m_y = 0;
		m_velocityY *= -1.0f;
	}
	//stop jumping if already jumping
	if (jumpTimer > 0)
	{
		jumpTimer--;
	}
	if(jumpTimer < 50 && jumpTimer > 0)
	{
		SetJumping(false);
	}
	if (jumpTimer == 0)
	{
		jumping = false;
	}
	
}
