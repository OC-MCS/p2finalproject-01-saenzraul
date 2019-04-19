#pragma once
#include <iostream>
using namespace std;
#include<SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include "CurrentPlayer.h"

class BombManager{
private:
	list<Bomb> listOfBombs;
public:
	BombManager();
	void addBomb(Bomb a);
	void removeBomb(Sprite &sprite, CurrentPlayer &player);
	void draw(RenderWindow &win);
	void setHit(Sprite &sprite);
};