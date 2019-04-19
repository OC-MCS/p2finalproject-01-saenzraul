#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include <stdlib.h>     
#include <time.h> 
#include "CurrentPlayer.h"

class Bomb
{
private:
	Sprite bomb;
	bool hit;

public:
	Bomb(Vector2f pos, Texture &text) {
		hit = false;
		bomb.setPosition(pos);
		bomb.setTexture(text);
		bomb.setScale(0.20, 0.20);
	}

	void draw(RenderWindow &win) {
		win.draw(bomb);
		bomb.move(0, 4.0f);
	}

	bool returnHit() {
		return hit;
	}

	Vector2f getPosition() {
		return bomb.getPosition();
	}

	void sethit(Vector2f shippos) {
		if (bomb.getGlobalBounds().contains(shippos)) {
			cout << "The Space Ship was Hit with A bomb \n";
			hit = true;
		}
	}

};


