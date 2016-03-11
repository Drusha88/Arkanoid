/////////////////////////////////////
// Include
#include "Ball.h"
#include <iostream>

/////////////////////////////////////
// Class Ball
Ball::Ball()
{
	m_type = GameObjectType_Ball;
	m_speed = kBallSpeed;
	setYSpeed(m_speed);
	setDirection(Direction_Down);
}

void Ball::update(float dt)
{
	GameObject::update(dt);
}

void Ball::render(sf::RenderWindow*  rw)
{
	GameObject::render(rw);
}

void Ball::intersect(GameObject* object)
{
	GameObjectType tempType = object->getType();

	switch (tempType)
	{
	case GameObjectType_Player: {
									int x0 = m_x;
									int y0 = m_y;
									int x1 = int(object->getX());
									int y1 = int(object->getY());
									if ((y1 - y0) >= 1)
									{
										move(Direction_Up);
										int leftOrRight = (x0 - (x1-(kPixelsPerCell/2))) / kPixelsPerCell;
										switch (leftOrRight)
										{
											case 0:	move(Direction_Left);	break;
											case 1:	move(Direction_Left);	break;
											case 2:	setXSpeed(0);			break;
											case 3:	move(Direction_Right);	break;
											case 4:	move(Direction_Right);	break;
											case 5:	move(Direction_Right);	break;
											default: setXSpeed(0);			break;	
										}
									}
									break;
								}
	case GameObjectType_Wall: {
									int x0 = m_x;
									int y0 = m_y;
									int x1 = int(object->getX());
									int y1 = int(object->getY());

									if ((x0 - x1) >= 1)
										move(Direction_Right);
									
									else if ((x0 - x1) <= -1)
										move(Direction_Left);
									
									break;
								}	

	case GameObjectType_Ceiling: {
									int y0 = m_y;
									int y1 = int(object->getY());

									if ((y1 - y0) <= -10) 
										move(Direction_Down);

									break;
								 }

	case GameObjectType_Abyss: {
								    GameObject* tempHealth = 0;
									tempHealth = m_game->getHealth();
									tempHealth->doDamage(1);
									int healthBall = getHealth();
									if (healthBall)
									{
										int xPlayer;
										int yPlayer;
										GameObject* tempPlayer = 0;
										tempPlayer = m_game->getPlayer();
										m_x = (tempPlayer->getX()) + (kPlayerWidth/2);
										m_y = (tempPlayer->getY()) - kPixelsPerCell;
										setXSpeed(0);
										setYSpeed(-m_speed);
									}
									break;
								}

	case GameObjectType_Block: {
								   int r00 = m_y;
								   int c00 = m_x;
								   int r01 = r00 + m_height - 1;
								   int c01 = c00 + m_width - 1;
								   int r10 = int(object->getY());
								   int c10 = int(object->getX());
								   int r11 = r10 + object->getHeight() - 1;
								   int c11 = c10 + object->getWidth() - 1;

								   if ((r00 <= r10) && (r01 <= r10) && (c01 >= c10) && (c00 <= c11))
										move(Direction_Up);

								   if((r00 >= r11) && (r01 >= r11) && (c01 >= c10) && (c00 <= c11))
										move(Direction_Down);

								   if ((r01 >= r10) && (r00 <= r11) && (c00 >= c11) && (c01 >= c11))
										move(Direction_Right);

								   if ((r01 >= r10) && (r00 <= r11) && (c00 <= c10) && (c01 <= c10))
										move(Direction_Left);

									object->doDamage(1);
									break;
								}							
	}
}

void Ball::move(Direction direction)
{
	setDirection(direction);
	switch (m_direction)
	{
	case Direction_Left: setXSpeed(-m_speed); break;
	case Direction_Right: setXSpeed(m_speed); break;
	case Direction_Up: setYSpeed(-m_speed); break;
	case Direction_Down: setYSpeed(m_speed); break;
	}
}
