#pragma once


/////////////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////////////
// Class Block

class Block
	: public GameObject
{
public:
	Block();

	virtual void render(sf::RenderWindow* rw);
};
