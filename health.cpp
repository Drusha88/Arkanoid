/////////////////////////////////////////////
// Include
#include "health.h"

/////////////////////////////////////////////
// Class Health
Health::Health()
{
	m_type = GameObjectType_Health;
	m_width = kHealthwidth;
	m_x = 20;
	m_y = 20;
	m_destroyAfterDeath = false;
	m_physical = false;

}

void Health::render(sf::RenderWindow* rw)
{
	sf::IntRect healthRect = kHealthImage;
	healthRect.width = (m_health-1) * kPixelsPerCell;
	setTextureRect(healthRect);
	GameObject::render(rw);
}
