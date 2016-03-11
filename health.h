#pragma once

/////////////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"

/////////////////////////////////////////////
// Class Health

class Health
	: public GameObject
{
public:
	Health();

	virtual void render(sf::RenderWindow* rw);
private:
};
