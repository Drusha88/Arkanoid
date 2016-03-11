/////////////////////////////////////////////
// Include
#include "Block.h"
#include "utils.h"

/////////////////////////////////////////////
// Class Block
Block::Block()
{
	m_type = GameObjectType_Block;
	m_width = kBlockWidth;
	int randomColor = GetRandomInt(1, 5);
	switch (randomColor)
	{
		case 1: setSpriteColor(sf::Color(204, 0, 156));  break;
		case 2: setSpriteColor(sf::Color(255, 255, 0));  break;
		case 3: setSpriteColor(sf::Color(255, 0, 0));  break;
		case 4: setSpriteColor(sf::Color(0, 0, 255));  break;
		case 5: setSpriteColor(sf::Color(0, 255, 0));  break;
	}
}


void Block::render(sf::RenderWindow* rw)
{
	GameObject::render(rw);
}

