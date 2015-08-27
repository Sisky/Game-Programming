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
	void SetJumping(bool jump);
	void SetLeft(bool left);
	bool IsJumping();
	bool IsLeft();
	bool jumping;
	bool m_left;
	bool m_right;
	void SetJumpTimer(float time);
	

};

#endif // __Player_H__


