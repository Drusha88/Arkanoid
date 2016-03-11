#pragma once
//Include
#include <cstdlib>
#include <cstdio>
#include <Windows.h>
#include "game.h"
#include "level.h"
#include "wall.h"
#include "Player.h"
#include "ball.h"
#include "Abyss.h"
#include "block.h"
#include "ceiling.h"
#include "health.h"
#include "Background.h"

//Global
sf::Texture* g_atlas00 = 0; 
sf::Font* font = 0;

//Class Game
Game::Game()
{
	m_isGameActive = true;
	m_startGame = true;
	m_clockLastFrame = 0;
	m_player = 0;
	m_ball = 0;
	m_ballHealth = kHealt;
	m_currentLevel = 0;
	m_renderWindow = 0;
	background = 0;
}

Game::~Game()
{
	if (m_renderWindow)
		delete m_renderWindow;
	if (g_atlas00)
		delete g_atlas00;
	if (font)
		delete font;
	if (background)
		delete background;
}

void Game::setupSystem()
{
	srand(time(0));

	m_renderWindow = new sf::RenderWindow(
		sf::VideoMode(kPixelsPerCell*kScreenColumns, kPixelsPerCell*kScreenRows, 32),
		"Arkanoid",
		sf::Style::Titlebar | sf::Style::Close);

	g_atlas00 = new sf::Texture();
	g_atlas00->loadFromFile("atlas00.png");

	font = new sf::Font;
	font->loadFromFile("BROADW.ttf");

	background = new Background("ImageSpace.jpg", 0,0, 1200, 600);
}

void Game::initialize()
{
	
	// Load level
	for (int r = 0; r < kScreenRows; r++)
	{
		for (int c = 0; c < kScreenColumns; c++)
		{
			unsigned char cellSymbol = kLevelData0[m_currentLevel][r][c];

			switch (cellSymbol)
			{
				case CellSymbol_Ceiling:
				{
					Ceiling* ceiling = (Ceiling*)createObject(GameObjectType_Ceiling, kPixelsPerCell*c, kPixelsPerCell*r);
					ceiling->setTextureRect(kCeilingImage);
					break;
				}
				case CellSymbol_Wall:
				{
					Wall* wall = (Wall*)createObject(GameObjectType_Wall, kPixelsPerCell*c, kPixelsPerCell*r);
					wall->setTextureRect(kWallImage);
					break;
				}
				case CellSymbol_Player:
				{
					Player* player = (Player*)createObject(GameObjectType_Player, kPixelsPerCell*c, kPixelsPerCell*r); //kPixelsPerCell*(c + 0.5), kPixelsPerCell*(r + 0.5));
					player->setTextureRect(kPlayerImage);
					player->setKeys(VK_LEFT, VK_RIGHT);
					m_player = player;
					break;
				}
				case CellSymbol_Ball:
				{
					Ball* ball = (Ball*)createObject(GameObjectType_Ball, kPixelsPerCell*c, kPixelsPerCell*r);
					ball->setTextureRect(kBallImage);
					m_ball = ball;
					break;
				}
				case CellSymbol_Abyss:
				{
					Abyss* abyss = (Abyss*)createObject(GameObjectType_Abyss, kPixelsPerCell*c, kPixelsPerCell*r);
					abyss->setTextureRect(kAbyssImage);
					break;
				}
				case CellSymbol_Block:
				{
					Block* block = (Block*)createObject(GameObjectType_Block, kPixelsPerCell*c, kPixelsPerCell*r);
					block->setTextureRect(kBlockImage);
					break;
				}
			}
		}
	}

	Health* health = (Health*)createObject(GameObjectType_Health, 0, 0);
	health->setTextureRect(kHealthImage);
	health->setHealth(m_ballHealth);
	m_health = health;
	
	
}

bool Game::loop()
{
	//Calculate delta time
	clock_t clockNow = clock();
	clock_t deltaClock = clockNow - m_clockLastFrame;
	float deltaTime = float(deltaClock) / CLOCKS_PER_SEC;
	m_clockLastFrame = clockNow;
	

	sf::Event event;
	while (m_renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_renderWindow->close();
			m_isGameActive = 0;
		}
			
	}
	render();
	update(deltaTime);
	
	return m_isGameActive;
}

void Game::destroyObject(GameObject* object)
{
	for (int i = 0; i < kObjectsCountMax; i++)
	{
		if (m_objects[i] == object)
		{
			delete m_objects[i];
			m_objects[i] = 0;
			return;
		}
	}
}

void Game::shutdown()
{
	for (int i = 0; i < kObjectsCountMax; i++)
		if (m_objects[i] != 0)
		{
			delete m_objects[i];
			m_objects[i] = 0;
		}
}

void Game::render()
{
	//Start frame
	m_renderWindow->clear(sf::Color(28, 28, 28));
	if (m_startGame)
	{
		drawText("ARKANOID", 40, 170, 200);
		m_startGame = false; 

		char buff[16];
		sprintf_s(buff, "Level %d", m_currentLevel+1);
		drawText(buff, 500, 250, 50);
	}
		
	else
	{
		//Draw background
		background->render(m_renderWindow);
		// Draw all game objects
		for (int i = 0; i < kObjectsCountMax; i++)
			if (m_objects[i] != 0)
			{
				m_objects[i]->render(m_renderWindow);
			}
	}
	//End frame

	m_renderWindow->display();

}

void Game::update(float dt)
{
	for (int i = 0; i < kObjectsCountMax; i++)
		if (m_objects[i] != 0)
		{
			m_objects[i]->update(dt);

			if (m_objects[i]->getHealth() <= 0 && m_objects[i]->getDestroyAfterDeath())
				destroyObject(m_objects[i]);
		}

	
	int blockInLevel = getObjectsCount(GameObjectType_Block);


	// Ball dead
	if (m_health->getHealth() <= 0)
	{
		drawText("GAME OVER", 130, 170, 150);
		m_isGameActive = false;
		shutdown();
	}



	if (!(blockInLevel) && (m_currentLevel < (level - 1)))
		{
			m_ballHealth = m_health->getHealth();
			m_currentLevel++;
			//Draw number for level
			char buff[16];
			sprintf_s(buff, "Level %d", m_currentLevel+1);
			drawText(buff, 500, 250, 50);

			shutdown(); //Del
			m_renderWindow->clear(sf::Color(20, 20, 20));
			initialize();
		}
			else if (!(blockInLevel) && (m_currentLevel == (level - 1)))
			{
				drawText("GAME OVER", 130, 170, 150);
				m_isGameActive = false;
				shutdown();
			}
}

GameObject* Game::checkIntersects(float x, float y, float width, float height, GameObject* exceptObject)
{
	int r00 = int(y);
	int c00 = int(x);
	int r01 = r00 + height -1;
	int c01 = c00 + width -1;

	for (int i = 0; i < kObjectsCountMax; i++)
	if (m_objects[i] != 0 && m_objects[i]->getPhysical() && m_objects[i] != exceptObject && exceptObject->getPhysical())
		{
			int r10 = int(m_objects[i]->getY());
			int c10 = int(m_objects[i]->getX());
			int r11 = r10 + m_objects[i]->getHeight() - 1;
			int c11 = c10 + m_objects[i]->getWidth() - 1;

			if (r00 <= r11 && r01 >= r10 && c00 <= c11 && c01 >= c10)
				return m_objects[i];
		}

	return 0;
}

bool Game::moveObjectTo(GameObject* object, float x, float y)
{
	int r0 = int(y);
	int c0 = int(x);
	int r1 = r0 + object->getHeight() - 1;
	int c1 = c0 + object->getWidth() - 1;

	if (r0 < 0 || c0 < 0 || r1 >= kScreenRows*kPixelsPerCell || c1 >= kScreenColumns*kPixelsPerCell)
		return false;


	bool canMoveToCell = false;

	GameObject* otherObject = checkIntersects(x, y, object->getWidth(), object->getHeight(), object);

	if (otherObject)
		object->intersect(otherObject);
	else
		canMoveToCell = true;


	if (canMoveToCell)
	{
		object->setX(x);
		object->setY(y);
	}

	return canMoveToCell;
}

int Game::getObjectsCount(GameObjectType type)
{
	int totalCount = 0;

	for (int i = 0; i < kObjectsCountMax; i++)
	{
		if (m_objects[i] == 0)
			continue;

		if (m_objects[i]->getType() == type)
			totalCount++;
	}

	return totalCount;
}

GameObject* Game::getPlayer()
{
	return m_player;
}

GameObject* Game::getHealth()
{
	return m_health;
}



GameObject* Game::createObject(GameObjectType type, float x, float y)
{
	// Find free pointer and create object
	for (int i = 0; i < kObjectsCountMax; i++)
	{
		if (m_objects[i] == 0)
		{
			GameObject* object = 0;

			switch (type)
			{
				case GameObjectType_Wall:			object = new Wall();			break;
				case GameObjectType_Ceiling:		object = new Ceiling();			break;
				case GameObjectType_Player:			object = new Player();			break;
				case GameObjectType_Ball:			object = new Ball();			break;
				case GameObjectType_Abyss:			object = new Abyss();			break;
				case GameObjectType_Block:			object = new Block();			break;
				case GameObjectType_Health:			object = new Health();			break;
			}

			if (object == 0)
				return 0;

			object->setGame(this);

			if (moveObjectTo(object, x, y) == false)
			{
				delete object;
				return 0;
			}

			m_objects[i] = object;

			return object;
		}
	}
	return 0;
}

void Game::drawText(std::string text, int x, int y, int size)
{

	m_renderWindow->clear(sf::Color(28, 28, 28));
	sf::Text textToDraw(text, *font, size);
	textToDraw.setColor(sf::Color::Green);
	textToDraw.setString(text);
	textToDraw.setPosition(x, y);

	m_renderWindow->draw(textToDraw);//draw this text
	m_renderWindow->display();
	Sleep(3000);
	m_renderWindow->clear(sf::Color(28, 28, 28));
}