#ifndef __Background_H__
#define __Background_H__


#include "entity.h"

class Background : public Entity
{
private:


public:
	// Constructors and Destructors
	Background();
	~Background();

	void Process(float deltaTime);

};

#endif // __Background_H__