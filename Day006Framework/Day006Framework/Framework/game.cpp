// 717310 C++ SDL Framework

// This includes:
#include "game.h"

// Local includes:
#include "backbuffer.h"
#include "inputhandler.h"
#include "logmanager.h"
#include "sprite.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Background.h"
#include "Platform.h"
#include "Enemy.h"
#include "Explosion.h"
#include "fmod.hpp"
#include "fmod_errors.h"
#include "fmod_common.h"


// Library includes:
#include <string>
#include <cassert>
#include <SDL.h>
#include <iostream>
#include <fstream>


// Static Members:
Game* Game::sm_pInstance = 0;
const float tileSize = 36;
Sprite* left;
Sprite* right;
Sprite* jump;

FMOD::System *systemFMOD = NULL;
FMOD::Sound      *sound1, *sound2, *fire1, *fire2, *playerExplode, *playerdie, *maintheme, *victory, *super;
FMOD::Channel    *channelSFX = 0, *channelMusic, *channelMusic2;
FMOD_RESULT result;



Game&
Game::GetInstance()
{
	if (sm_pInstance == 0)
	{ 
		sm_pInstance = new Game();
	}

	assert(sm_pInstance);

	return (*sm_pInstance);
}

void 
Game::DestroyInstance()
{
	delete sm_pInstance; 
	sm_pInstance = 0;
}

Game::Game()
: m_pBackBuffer(0)
, m_pInputHandler(0)
, m_looping(true)
, m_executionTime(0)
, m_elapsedSeconds(0)
, m_frameCount(0)
, m_FPS(0)
, m_numUpdates(0)
, m_lastTime(0)
, m_lag(0)
, m_pPlayer(0)
, m_EnemyVector(0)
, m_PlatVector(0)
{
	
}

Game::~Game()
{
	delete m_pBackBuffer;
	m_pBackBuffer = 0;

	delete m_pPlayer;
	m_pPlayer = 0;

	
}

bool 
Game::Initialise()
{



	

	const int width = tileSize * 21;
	const int height = tileSize * 16;

	m_pBackBuffer = new BackBuffer();
	if (!m_pBackBuffer->Initialise(width, height))
	{
		LogManager::GetInstance().Log("BackBuffer Init Fail!");
		return (false);
	}

	m_pInputHandler = new InputHandler();
	if (!m_pInputHandler->Initialise())
	{
		LogManager::GetInstance().Log("InputHandler Init Fail!");
		return (false);
	}

	
	//Create background
	Sprite* backG = m_pBackBuffer->CreateSprite("assets\\background.png");

	bg = new Background();
	bg->Initialise(backG);
	bg->SetPositionX(0.0f);
	bg->SetPositionY(0.0f);


	
	// Load the player sprite
	right = m_pBackBuffer->CreateSprite("assets\\Player.png");
	left = m_pBackBuffer->CreateSprite("assets\\PlayerRight.png");

	//Create the player sprite and set the position
	m_pPlayer = new Player();
	m_pPlayer->Initialise(right);
	m_pPlayer->SetPositionX(tileSize);
	m_pPlayer->SetPositionY(tileSize * 14);
	m_pPlayer->SetVerticalVelocity(2.0f);

	//create map from file
	ReadMap();
	
	

	


	m_lastTime = SDL_GetTicks();
	m_lag = 0.0f;

	return (true);
}





//read map from textfile
void 
Game::ReadMap()
{
	std::string line;
	std::ifstream file("assets\\map.txt");
	float y = 1;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			for (std::string::size_type i = 1; i < line.size()+1; ++i) 
			{
				if (line[i] == 'X')
				{
					//spawn platform
					SpawnPlatform(tileSize *i-tileSize, tileSize *y);
				}
				else if (line[i] == 'E')
				{
					//spawn enemy
					SpawnEnemy(tileSize * i- tileSize, tileSize * y);
				}
			}
			y++;
		}
	}

}


bool 
Game::DoGameLoop()
{
	const float stepSize = 1.0f / 60.0f;

	assert(m_pInputHandler);
	m_pInputHandler->ProcessInput(*this);
	
	if (m_looping)
	{
		int current = SDL_GetTicks();
		float deltaTime = (current - m_lastTime) / 1000.0f;
		m_lastTime = current;

		m_executionTime += deltaTime;

		m_lag += deltaTime;

		while (m_lag >= stepSize)
		{
			Process(stepSize);

			m_lag -= stepSize;

			++m_numUpdates;
		}
		
		Draw(*m_pBackBuffer);
	}

	SDL_Delay(1);

	return (m_looping);
}

void 
Game::Process(float deltaTime)
{
	// Count total simulation time elapsed:
	m_elapsedSeconds += deltaTime;

	// Frame Counter:
	if (m_elapsedSeconds > 1)
	{
		m_elapsedSeconds -= 1;
		m_FPS = m_frameCount;
		m_frameCount = 0;
	}

	// Update the game world simulation:

	// Process each enemy in the container.
	std::vector<Enemy*>::iterator enemyIterator;
	for (enemyIterator = m_EnemyVector.begin();
	enemyIterator != m_EnemyVector.end();
		++enemyIterator)
	{
		
		(*enemyIterator)->Process(deltaTime);
	}

	// Process each bullet in the container.
	std::vector<Bullet*>::iterator bulletIterator;
	for (bulletIterator = m_BulletVector.begin();
	bulletIterator != m_BulletVector.end();
		++bulletIterator)
	{
		(*bulletIterator)->Process(deltaTime);
	}
	//process all platforms
	std::vector<Platform*>::iterator platIterator;
	for (platIterator = m_PlatVector.begin();
	platIterator != m_PlatVector.end();
		++platIterator)
	{
		(*platIterator)->Process(deltaTime);
	}
	//process explosions
	std::vector<Explosion*>::iterator ExplosionIterator;
	for (ExplosionIterator = Explosions.begin();
	ExplosionIterator != Explosions.end();
		++ExplosionIterator)
	{
		(*ExplosionIterator)->Process(deltaTime);
		(*ExplosionIterator)->GetSprite()->Process(deltaTime);
	}

	// Update the player object
	m_pPlayer->Process(deltaTime);



	// Check for bullet vs alien enemy collisions...
	// For each bullet
	for (bulletIterator = m_BulletVector.begin();
	bulletIterator != m_BulletVector.end();
		++bulletIterator)
	{
		// For each alien enemy
		for (enemyIterator = m_EnemyVector.begin();
		enemyIterator != m_EnemyVector.end();
			++enemyIterator)
		{
			// Check collision between two entities.	
			if ((*bulletIterator)->IsCollidingWith(*(*enemyIterator)) == true)
			{
				// If collided, destory both and spawn explosion.
				SpawnExplosion((*enemyIterator)->GetPositionX(), (*enemyIterator)->GetPositionY());
				(*bulletIterator)->SetDead(true);
				(*enemyIterator)->SetDead(true);

			}
		}
	}


	//check for bullet vs platform
	for (bulletIterator = m_BulletVector.begin();
	bulletIterator != m_BulletVector.end();
		++bulletIterator)
	{
		// For each alien enemy
		for (platIterator = m_PlatVector.begin();
		platIterator != m_PlatVector.end();
			++platIterator)
		{
			// Check collision between two entities.	
			if ((*bulletIterator)->IsCollidingWith(*(*platIterator)) == true)
			{
				// If collided, destory both and spawn explosion.
				(*bulletIterator)->SetDead(true);

			}
		}
	}
	//enemy vs plat
	for (platIterator = m_PlatVector.begin(); platIterator != m_PlatVector.end(); ++platIterator)
	{
		// For each plat
		for (enemyIterator = m_EnemyVector.begin(); enemyIterator != m_EnemyVector.end(); ++enemyIterator)
		{
			// Check collision between two entities.	
			if ((*platIterator)->IsCollidingWith(*(*enemyIterator)) == true)
			{
				// If collided, set on top
				(*enemyIterator)->SetPositionY((*platIterator)->GetPositionY() - tileSize);
				if ((*platIterator)->GetPositionX() < 200)
				{
					(*enemyIterator)->SetHorizontalVelocity(3.0f);
				}

			}
		}
	}




	//player vs enemy
	for (enemyIterator = m_EnemyVector.begin(); enemyIterator != m_EnemyVector.end(); ++enemyIterator)
	{
		if ((*enemyIterator)->IsCollidingWith(*m_pPlayer))
		{
			SpawnExplosion(m_pPlayer->GetPositionX(), m_pPlayer->GetPositionY());
			m_pPlayer->SetPositionX(tileSize);
			m_pPlayer->SetPositionY(tileSize);
		}
	}

	//player vs plat
	for (platIterator = m_PlatVector.begin(); platIterator != m_PlatVector.end(); ++platIterator)
	{
		if ((*platIterator)->IsCollidingWith(*m_pPlayer))
		{
			float platPos = (*platIterator)->GetPositionY();
			float platxPos = (*platIterator)->GetPositionX();
			//right collision
			if (m_pPlayer->GetPositionY() > (*platIterator)->GetPositionY())
			{
				m_pPlayer->SetPositionY(platPos + tileSize);
				if (m_pPlayer->GetPositionX() < (*platIterator)->GetPositionX())
				{
					//m_pPlayer->SetPositionX(platxPos + tileSize);

					m_pPlayer->SetVerticalVelocity(2.0f);
				}
				else if (m_pPlayer->GetPositionX() > (*platIterator)->GetPositionX())
				{
					m_pPlayer->SetVerticalVelocity(2.0f);
				}
			}
			else
			{
				m_pPlayer->SetPositionY(platPos - tileSize);
				if (m_pPlayer->GetPositionX() < (*platIterator)->GetPositionX())
				{

					m_pPlayer->SetVerticalVelocity(2.0f);
				}
				else if (m_pPlayer->GetPositionX() > (*platIterator)->GetPositionX())
				{
					m_pPlayer->SetVerticalVelocity(2.0f);
				}
			}
		}
	}






	// Remove any dead bullets from the container...
	bulletIterator = m_BulletVector.begin();
	while(bulletIterator != m_BulletVector.end())
	{
		if((*bulletIterator)->IsDead() == true)
		{

			bulletIterator = m_BulletVector.erase(bulletIterator);

		}
		else
		{
			++bulletIterator;
		}
	}

	// Remove any dead enemy aliens from the container...
	enemyIterator = m_EnemyVector.begin();
	while(enemyIterator != m_EnemyVector.end())
	{
		if((*enemyIterator)->IsDead() == true)
		{

			enemyIterator = m_EnemyVector.erase(enemyIterator);

		}
		else
		{
			++enemyIterator;
		}
	}
	//remove explosions
	std::vector<Explosion*>::iterator explosionIterator;
	for (explosionIterator = Explosions.begin(); explosionIterator != Explosions.end();) 
	{
		Explosion* explode = *explosionIterator;

		if (explode->IsDead()) 
		{
			delete explode;
			explosionIterator = Explosions.erase(explosionIterator);
		}
		else 
		{
			explosionIterator++;
		}

	}
	
}

void 
Game::Draw(BackBuffer& backBuffer)
{
	++m_frameCount;

	backBuffer.SetClearColour(0,0,0);
	backBuffer.Clear();
	bg->Draw(*m_pBackBuffer);
	
	// Draw all enemy aliens in container...
	std::vector<Enemy*>::iterator enemyIterator;
	for(enemyIterator = m_EnemyVector.begin();
		enemyIterator != m_EnemyVector.end();
		++enemyIterator)
	{
		(*enemyIterator)->Draw(backBuffer);
	}
	//draw platfomrs 
	std::vector<Platform*>::iterator platIterator;
	for (platIterator = m_PlatVector.begin();
	platIterator != m_PlatVector.end();
		++platIterator)
	{
		(*platIterator)->Draw(backBuffer);
	}

	// Draw all bullets in container...
	std::vector<Bullet*>::iterator bulletIterator;
	for(bulletIterator = m_BulletVector.begin();
		bulletIterator != m_BulletVector.end();
		++bulletIterator)
	{
		(*bulletIterator)->Draw(backBuffer);
	}
	

		
	

		
	// Draw the player ship...
	m_pPlayer->Draw(*m_pBackBuffer);
	
	//Draw explosions
	std::vector<Explosion*>::iterator ExplosionIterator;
	for (ExplosionIterator = Explosions.begin(); ExplosionIterator != Explosions.end(); ++ExplosionIterator)
	{
		(*ExplosionIterator)->Draw(backBuffer);
	}
	

	backBuffer.Present();
}

void 
Game::Quit()
{
	m_looping = false;
}

void 
Game::MoveSpaceShipLeft()
{
	// Tell the player ship to move left.
	m_pPlayer->SetHorizontalVelocity(-2.0f);     
	m_pPlayer->SetLeft(true);
	m_pPlayer->Initialise(left);
}

//Add the method to tell the player ship to move right...
void 
Game::MoveSpaceShipRight()
{
	// Tell the player ship to move left.
	m_pPlayer->SetHorizontalVelocity(2.0f);   
	m_pPlayer->SetLeft(false);
	m_pPlayer->Initialise(right);
}
void
Game::Jump()
{
	if (!m_pPlayer->IsJumping())
	{
		m_pPlayer->SetJumping(true);
	}
	
}
// Space a Bullet in game.
void 
Game::FireSpaceShipBullet()
{
	// Load the player bullet sprite.   
	Sprite* pBulletSprite = m_pBackBuffer->CreateSprite("assets\\playerbullet.png");
	Sprite* pBulletSpriteReverse = m_pBackBuffer->CreateSprite("assets\\playerbulletreverse.png");

	// Create a new bullet object.
	
	//if facing left fire right to left
	if (m_pPlayer->IsLeft())
	{
		Bullet* pBullet = new Bullet();
		pBullet->Initialise(pBulletSpriteReverse);
		pBullet->SetHorizontalVelocity(-5.0f);
		pBullet->SetPositionX(m_pPlayer->GetPositionX() + 6.0f);
		pBullet->SetPositionY(m_pPlayer->GetPositionY() + 7.0f);
		m_BulletVector.push_back(pBullet);
	}
	//fire left to right
	else
	{
		Bullet* pBullet = new Bullet();
		pBullet->Initialise(pBulletSprite);
		pBullet->SetHorizontalVelocity(5.0f);
		pBullet->SetPositionX(m_pPlayer->GetPositionX() + 6.0f);
		pBullet->SetPositionY(m_pPlayer->GetPositionY() + 7.0f);
		m_BulletVector.push_back(pBullet);
	}
	//set horizontal
	
	// Set the bullets vertical velocity.
	
	

	// Add the new bullet to the bullet container.
	
}

void
Game::StopSpaceShipMovement()
{
	m_pPlayer->SetHorizontalVelocity(0.0f);
	
}


void 
Game::SpawnPlatform(float x, float y)
{
	Platform* plat = new Platform();
	Sprite* platSprite = m_pBackBuffer->CreateSprite("assets\\plat.png");
	plat->Initialise(platSprite);
	plat->SetPositionX(x);
	plat->SetPositionY(y);
	plat->SetHorizontalVelocity(-0.5f);
	m_PlatVector.push_back(plat);
	
}

void
Game::SpawnEnemy(float x, float y)
{
	Enemy* e = new Enemy();
	Sprite* rabbitLeft = m_pBackBuffer->CreateSprite("assets\\rabbit.png");
	e->Initialise(rabbitLeft);
	e->SetPositionX(x);
	e->SetPositionY(y);
	e->SetHorizontalVelocity(-0.5f);
	m_EnemyVector.push_back(e);
}

void
Game::SpawnExplosion(int x, int y)
{
	Explosion* explosion = new Explosion();
	explosion->SetPositionX(x - 10);
	explosion->SetPositionY(y - 10);



	AnimatedSprite* exploding = m_pBackBuffer->CreateAnimatedSprite("assets\\explosion.png");
	exploding->SetLooping(false);
	exploding->SetFrameWidth(64);
	exploding->SetFrameSpeed(0.05);
	exploding->AddFrame(0);
	exploding->AddFrame(64);
	exploding->AddFrame(128);
	exploding->AddFrame(192);
	exploding->AddFrame(256);




	explosion->Initialise(exploding);

	Explosions.push_back(explosion);
}