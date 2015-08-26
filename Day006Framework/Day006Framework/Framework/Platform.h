#ifndef __PLATFORM_H__
#define __PLATFORM_H__
#include "entity.h"


class Platform : public Entity
{
public:
	Platform();
	~Platform();

	void Process(float deltatick);

protected:

private:
	Platform(const Platform& Platform);
	Platform& operator=(const Platform& Platform);
};

#endif //__PLATFORM_H__