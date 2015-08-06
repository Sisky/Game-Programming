#include "Player.h"
#include <iostream>

Player::Player()
	:m_experienceLevel(0), m_health(100), m_rageLevel(0)
{
	std::cout << "Player Object Created!" << std::endl;
}

Player::~Player()
{
	std::cout << "Player Object Destroyed!" << std::endl;
}

int
Player::getExperience() const
{
	return (m_experienceLevel);
}

int
Player::getHealth() const
{
	return (m_health);
}

int
Player::getRageLevel() const
{
	return (m_rageLevel);
}

void
Player::setExperience(int h)
{
	m_experienceLevel = h;
}

void
Player::setHealth(int h)
{
	m_health = h;
}

void
Player::setRageLevel(int h)
{
	m_rageLevel = h;
}

void
Player::printStats()
{
	std::cout << "Experience level is: " << m_experienceLevel << std::endl;
	std::cout << "Health is: " << m_health << std::endl;
	std::cout << "Rage level is: " << m_rageLevel << std::endl;
}