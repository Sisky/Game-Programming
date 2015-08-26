
#ifndef __ENEMY_H__
#define __ENEMY_H__

// Includes for this class
#include "entity.h"

class Enemy : public Entity
{
public:
	Enemy();
	~Enemy();

	void Process(float deltaTime);

protected:

private:
	Enemy(const Enemy& enemy);
	Enemy& operator=(const Enemy& enemy);

};

#endif //__ENEMY_H__