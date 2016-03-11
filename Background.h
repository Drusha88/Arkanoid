#pragma once

/////////////////////////////////////////////
//Include
#include <SFML/Graphics.hpp>
#include <string>

/////////////////////////////////////////////
//Extern
extern sf::RenderWindow* m_renderWindow;

/////////////////////////////////////////////
//Background
class Background
{
public:
	Background(std::string file, int x, int y, int w, int h)
	{
		backgroundTexture = new sf::Texture();
		backgroundTexture->loadFromFile(file);

		backgroundSprite = new sf::Sprite();
		backgroundSprite->setTexture(*backgroundTexture);
		backgroundSprite->setTextureRect(sf::IntRect(0, 0, w, h));
		backgroundSprite->setPosition(x, y);
	}
	~Background()
	{
		delete backgroundTexture;
		delete backgroundSprite;
	}
	void render(sf::RenderWindow* rw)
	{
		if (backgroundSprite)
		{
			rw->draw(*backgroundSprite);
		}
	}
private:
	sf::Texture* backgroundTexture = 0;
	sf::Sprite* backgroundSprite = 0;
};


