/////////////////////////////////////////////
// Include
#include "Abyss.h"

/////////////////////////////////////////////
// Class Abyss
Abyss::Abyss()
{
	m_type = GameObjectType_Abyss;
}

void Abyss::render( sf::RenderWindow* rw)
{
	GameObject::render(rw);
}
