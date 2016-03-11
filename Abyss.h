#pragma once

/////////////////////////////////////////////
// Include
#include "gameObject.h"

/////////////////////////////////////////////
// Class Abyss
class Abyss
	: public GameObject
{
public:

	Abyss();

	virtual void render( sf::RenderWindow* rw);
};
