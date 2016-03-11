#pragma once


/////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"


/////////////////////////////////////
// Class Wall

class Wall
	: public GameObject
{
public:
	Wall();

	virtual void render(sf::RenderWindow* rw);

};
