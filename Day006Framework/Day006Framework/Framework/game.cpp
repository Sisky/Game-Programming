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

// Library includes:
#include <cassert>
#include <SDL.h>

// Static Members:
Game* Game::sm_pInstance = 0;

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
	const int tileSize = 36;
	const int width = tileSize * 22;
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
	Sprite* pPlayerSprite = m_pBackBuffer->CreateSprite("assets\\Player.png");

	//Create the player sprite and set the position
	m_pPlayer = new Player();
	m_pPlayer->Initialise(pPlayerSprite);
	m_pPlayer->SetPositionX(400.0f);
	m_pPlayer->SetPositionY(500.0f);


	// Load the alien ship sprite

	SpawnEnemy(700.0f, 500.0f);

	
	

	


	m_lastTime = SDL_GetTicks();
	m_lag = 0.0f;

	return (true);
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

	// Process each alien enemy in the container.
	std::vector<Entity*>::iterator enemyIterator;
	for(enemyIterator = m_EnemyVector.begin();
		enemyIterator != m_EnemyVector.end();
		++enemyIterator)
	{
		(*enemyIterator)->Process(deltaTime);
	}

	// Process each bullet in the container.
	std::vector<Bullet*>::iterator bulletIterator;
	for(bulletIterator = m_BulletVector.begin();
		bulletIterator != m_BulletVector.end();
		++bulletIterator)
	{
		(*bulletIterator)->Process(deltaTime);
	}

	// Update the player object
	m_pPlayer->Process(deltaTime);

	// Check for bullet vs alien enemy collisions...
	// For each bullet
	for(bulletIterator = m_BulletVector.begin();
		bulletIterator != m_BulletVector.end();
		++bulletIterator)
	{
		// For each alien enemy
		for(enemyIterator = m_EnemyVector.begin();
			enemyIterator != m_EnemyVector.end();
			++enemyIterator)
		{
			// Check collision between two entities.	
			if((*bulletIterator)->IsCollidingWith(*(*enemyIterator)) == true)
			{
				// If collided, destory both and spawn explosion.
				(*bulletIterator)->SetDead(true);
				(*enemyIterator)->SetDead(true);
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

	
}

void 
Game::Draw(BackBuffer& backBuffer)
{
	++m_frameCount;

	backBuffer.SetClearColour(0,0,0);
	backBuffer.Clear();
	bg->Draw(*m_pBackBuffer);
	// Draw all enemy aliens in container...
	std::vector<Entity*>::iterator enemyIterator;
	for(enemyIterator = m_EnemyVector.begin();
		enemyIterator != m_EnemyVector.end();
		++enemyIterator)
	{
		(*enemyIterator)->Draw(backBuffer);
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
	m_pPlayer->SetHorizontalVelocity(-5.0f);        
}

//Add the method to tell the player ship to move right...
void 
Game::MoveSpaceShipRight()
{
	// Tell the player ship to move left.
	m_pPlayer->SetHorizontalVelocity(5.0f);        
}

// Space a Bullet in game.
void 
Game::FireSpaceShipBullet()
{
	// Load the player bullet sprite.   
	Sprite* pBulletSprite = m_pBackBuffer->CreateSprite("assets\\playerbullet.png");

	// Create a new bullet object.
	Bullet* pBullet = new Bullet();
	pBullet->Initialise(pBulletSprite);

	// Set the bullets vertical velocity.
	pBullet->SetVerticalVelocity(-5.0f);
	pBullet->SetPositionX(m_pPlayer->GetPositionX()+10.0f);
	pBullet->SetPositionY(m_pPlayer->GetPositionY());

	// Add the new bullet to the bullet container.
	m_BulletVector.push_back(pBullet);
}

void
Game::StopSpaceShipMovement()
{
	m_pPlayer->SetHorizontalVelocity(0.0f);
}


void 
Game::SpawnEnemy(float x, float y)
{
	Enemy* e = new Enemy();
	Sprite* pAlienSprite = m_pBackBuffer->CreateSprite("assets\\rabbit.png");
	e->Initialise(pAlienSprite);
	e->SetPositionX(x);
	e->SetPositionY(y);
	m_EnemyVector.push_back(e);
}
