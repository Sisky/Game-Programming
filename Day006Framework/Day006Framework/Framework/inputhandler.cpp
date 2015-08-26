// 717310 C++ SDL Framework

// This include:
#include "inputhandler.h"
#include "logmanager.h"

// Local includes:
#include "game.h"

// Library includes:
#include <cassert>

InputHandler::InputHandler()
: m_pGameController(0)
{

}

InputHandler::~InputHandler()
{
	if (m_pGameController)
	{
		SDL_JoystickClose(m_pGameController);
		m_pGameController = 0;
	}
}

bool 
InputHandler::Initialise()
{
	int numControllesr = SDL_NumJoysticks();

	m_pGameController = SDL_JoystickOpen(0);
	assert(m_pGameController);

	return (true);
}

void 
InputHandler::ProcessInput(Game& game)
{
	// Receive Input Events below...
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			game.Quit();
		}
		else if (e.type == SDL_JOYBUTTONDOWN)
		{
			switch(e.jbutton.button)
			{
			case A:
				{
					game.FireSpaceShipBullet();
				}
				break;
			case DPADLEFT:
				{
					game.MoveSpaceShipLeft();
				}
				break;
			case DPADRIGHT:
				{
					game.MoveSpaceShipRight();
				}
				break;
			}		
		}
		else if (e.type == SDL_JOYBUTTONUP)
		{
			switch(e.jbutton.button)
			{
			case DPADLEFT:
			case DPADRIGHT:
				{
					game.StopSpaceShipMovement();
				}
				break;
			}
		}
		else if (e.type == SDL_KEYDOWN)
		{
			switch(e.key.keysym.scancode)
			{
			case SDL_SCANCODE_A:
				{
					// Move left
					game.MoveSpaceShipLeft();
				}
				break;
			case SDL_SCANCODE_D:
				{
					// Move Right
					game.MoveSpaceShipRight();
				}
				break;
			case SDL_SCANCODE_SPACE:				
				{
					game.FireSpaceShipBullet();
				}
				break;
			}
		}
		else if(e.type == SDL_KEYUP)
		{
			switch(e.key.keysym.scancode)
			{
			case SDL_SCANCODE_A:
			case SDL_SCANCODE_D:
				{
					// Move Right
					game.StopSpaceShipMovement();
				}
				break;
			}
		}


	}
}
