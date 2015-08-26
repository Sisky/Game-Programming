#ifndef __BULLET_H__
#define __BULLET_H__

#include "entity.h"

class Bullet : public Entity
{
public:
	Bullet();
	~Bullet();

	void Process(float deltatick);

protected:

private:
	Bullet(const Bullet& bullet);
	Bullet& operator=(const Bullet& bullet);

};

#endif //__BULLET_H__