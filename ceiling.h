#pragma once

/////////////////////////////////////////////
// Include
#include "gameObject.h"

/////////////////////////////////////////////
// Class Ceiling

class Ceiling
	: public GameObject
{
public:
	Ceiling();

	virtual void render(sf::RenderWindow* rw);
};
