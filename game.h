#pragma once

//Include
#include <SFML/Graphics.hpp>
#include <ctime>
#include "gameObject.h"
#include "gameObjectType.h"
#include "Background.h"


//Constans
const int kObjectsCountMax = 1024;

/////////////////////////////////////
// Forward declaration
class GameObject;

//Class Game
class Game
{
public:
	Game();
	~Game();

	void setupSystem();
	void initialize();
	bool loop();
	void shutdown();

	GameObject* createObject(GameObjectType type, float x, float y);
	void destroyObject(GameObject* object);
	GameObject* checkIntersects(float x, float y, float width, float height, GameObject* exceptObject);
	bool moveObjectTo(GameObject* object, float x, float y);
	int getObjectsCount(GameObjectType type);
	GameObject* getPlayer();
	GameObject* getHealth();

private:
	void render();
	void update(float dt);
	void drawText(std::string text, int x, int y, int size);

private:
	int m_currentLevel;
	int m_ballHealth;
	bool m_isGameActive;
	bool m_drawTitle;
	bool m_startGame;

	

	clock_t m_clockLastFrame;

	GameObject* m_player;
	GameObject* m_ball;
	GameObject* m_health;

	GameObject* m_objects[kObjectsCountMax];

	sf::RenderWindow* m_renderWindow;
	Background* background;

};