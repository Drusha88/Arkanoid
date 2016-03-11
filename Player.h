#pragma once

/////////////////////////////////////////////
// Include
#include "gameObject.h"
#include "level.h"

/////////////////////////////////////////////
// Class Player
class Player
	: public GameObject
{
public:
	Player();

	virtual void update(float dt);
	virtual void render(sf::RenderWindow* rw);
	void move(Direction direction);
	void setKeys(int keyLeft, int keyRight);

protected:
	int m_keyLeft;
	int m_keyRight;
	float m_speed;
};
