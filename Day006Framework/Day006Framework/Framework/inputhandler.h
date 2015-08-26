// 717310 C++ SDL Framework
#ifndef __INPUTHANDER_H__
#define __INPUTHANDER_H__

// Library includes:
#include <SDL.h>

// Forward Declarations:
class Game;

class InputHandler
{
	//Member Methods:
public:
	InputHandler();
	~InputHandler();

	bool Initialise();
	void ProcessInput(Game& game);

	enum eXBOXButtons{
		DPADUP,
		DPADDOWN,
		DPADLEFT,
		DPADRIGHT,
		START,
		SELECT,
		L3,
		R3,
		LB,
		RB,
		A,
		B,
		X,
		Y,
		HOME
	};

protected:

private:
	InputHandler(const InputHandler& inputHandler);
	InputHandler& operator=(const InputHandler& inputHandler);

	//Member Data:
public:

protected:
	SDL_Joystick* m_pGameController;

private:

};

#endif // __INPUTHANDER_H__
