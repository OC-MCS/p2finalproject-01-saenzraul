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
	Missile(Vector2f pos, const Texture & text) {
		missile.setPosition(pos);
		missile.setTexture(text);
		collide = false;
	}

	bool getCollision() {
		return collide;
	}

	void setCollision(bool x) {
		collide = x;
	}

	void draw(RenderWindow &win) {
		win.draw(missile);
		missile.move(0, -10.0f);
	}

	Vector2f getPosition() {
		return missile.getPosition();
	}

};