/////////////////////////////////////////////
// Include
#include "Player.h"
#include "utils.h"

/////////////////////////////////////////////
// Class GameObject
Player::Player()
{
	m_type = GameObjectType_Player;
	m_width = kPlayerWidth;
	m_speed = kPlayerSpeed;
	m_health = kHealt;
}

void Player::update(float dt)
{
	GameObject::update(dt);

		if (IsKeyDown(m_keyLeft))
			move(Direction_Left);
		else
			if (IsKeyDown(m_keyRight))
				move(Direction_Right);
			else
					{
						setXSpeed(0);
						setYSpeed(0);
					}
}

void Player::render(sf::RenderWindow* rw)
{
	GameObject::render(rw);
}


void Player::move(Direction direction)
{
	setDirection(direction);

	setXSpeed(0);
	setYSpeed(0);

	switch (m_direction)
	{
	case Direction_Left: setXSpeed(-m_speed); break;
	case Direction_Right: setXSpeed(m_speed); break;
	}
}


void Player::setKeys(int keyLeft, int keyRight)
{
	m_keyLeft = keyLeft;
	m_keyRight = keyRight;

}