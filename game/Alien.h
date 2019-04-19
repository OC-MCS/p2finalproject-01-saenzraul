#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include "BombManager.h"

class Alien {
private:
	Sprite alien;
	bool hit;
	Vector2f initialPos;
public:
	Alien(Vector2f pos, Texture &text);
	bool returnHit();
	void seeHit(Vector2f missilepos);
	Vector2f getPosition();
	void draw(RenderWindow &win);
	void dropBomb(Texture &text, BombManager &list);
	Vector2f returnInitialPos();
	void setPosition(Vector2f pos);

};