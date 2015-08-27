#include "Explosion.h"
#include "AnimatedSprite.h"
#include <cassert>




Explosion::Explosion()
	: m_pSprite(0)
	, m_x(0.0f)
	, m_y(0.0f)
	, m_dead(false) {
}

Explosion::~Explosion() {
}


void
Explosion::SetPositionX(float x) {
	m_x = x;
}

void
Explosion::SetPositionY(float y) {
	m_y = y;
}


bool
Explosion::IsDead() const {
	return m_dead;
}



void
Explosion::SetDead(bool dead)
{
	m_dead = dead;
}


bool
Explosion::Initialise(AnimatedSprite* sprite)
{
	assert(sprite);
	m_pSprite = sprite;

	return (true);
}

void
Explosion::Process(float deltaTime)
{
	m_pSprite->SetX(static_cast<int>(m_x));
	m_pSprite->SetY(static_cast<int>(m_y));

	if (m_pSprite->IsPaused())
		SetDead(true);

}

void
Explosion::Draw(BackBuffer& backBuffer)
{
	assert(m_pSprite);
	m_pSprite->Draw(backBuffer);
}

AnimatedSprite*
Explosion::GetSprite()
{
	return m_pSprite;

}