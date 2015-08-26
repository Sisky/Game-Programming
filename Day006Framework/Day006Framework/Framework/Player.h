#ifndef __Player_H__
#define __Player_H__


#include "entity.h"

class Player : public Entity
{
private:


public:
	// Constructors and Destructors
	Player();
	~Player();

	void Process(float deltaTime);

};

#endif // __Player_H__