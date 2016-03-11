#pragma once

/////////////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"

/////////////////////////////////////////////
// Class Ball

class Ball
	: public GameObject
{
public:
	Ball();
	virtual void update(float dt);
	virtual void render(sf::RenderWindow* rw);
	void intersect(GameObject* object);
	void move(Direction direction);

protected:
	float m_speed;
};


