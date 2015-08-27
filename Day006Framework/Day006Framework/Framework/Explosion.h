#ifndef __Explosion_H__
#define __Explosion_H__


#include "AnimatedSprite.h"

class Explosion {
public:
	Explosion();
	~Explosion();


	bool Initialise(AnimatedSprite* sprite);

	void Process(float deltaTime);
	void Draw(BackBuffer& backBuffer);

	void SetDead(bool dead);
	bool IsDead() const;



	void SetPositionX(float x);
	void SetPositionY(float y);

	AnimatedSprite* GetSprite();



protected:

private:

protected:
	AnimatedSprite* m_pSprite;

	float m_x;
	float m_y;


	bool m_dead;
};

#endif //__Explosion_H__
