/////////////////////////////////////////////
// Include
#include "ceiling.h"


/////////////////////////////////////////////
// Class Ceiling
Ceiling::Ceiling()
{
	m_type = GameObjectType_Ceiling;
}

void Ceiling::render(sf::RenderWindow* rw)
{
	GameObject::render(rw);
}

