#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Alien.h"
#include "Bomb.h"
#include "BombManager.h"
#include "CurrentPlayer.h"

class AlienManager {
private:
	list<Alien> listOfAliens;

public:
	AlienManager(Texture &text);
	void addAlien(Vector2f pos, Texture &text);
	void removeAlien(Sprite &sprite, CurrentPlayer &player);
	void draw(RenderWindow &win);
	void setHit(MissileManager &mgr);
	void dropBombs(Texture &text, BombManager &bombMgr);
	int returnAlienCount();
};
