#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>

class Missile {

private:
	Sprite missile;
	bool collide;

public:
	Missile(Vector2f pos, Texture &text);
	bool hasCollided();
	Sprite returnSprite();
	void setCollison(bool collide);
	void draw(RenderWindow &win);
	Vector2f getPosition();
};