#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include "BombManager.h"
#include "Missile.h"

//Class: Alien
class Alien
{
private:
	Sprite alien;
	bool hit;
	Vector2f initialPos;

public:
	//====================================================== 
	// Alien(): Constructor for Alien Class
	// parameters:  Vector2f pos, Texture &text
	// return type: n/a
	//====================================================== 
	Alien(Vector2f pos, Texture &text) {
		alien.setPosition(pos);
		alien.setTexture(text);
		initialPos = pos;
		alien.setScale(0.2, 0.2);
	}

	//====================================================== 
	// returnhit(): returns the current state of hit from struct
	// parameters: n/a
	// return type: bool hit
	//====================================================== 
	bool returnHit() {
		return hit;
	}

	//====================================================== 
	// makehit(): determines whether missile hit or not
	// parameters: ector2f pos, Missile &mis
	// return type: n/a
	//====================================================== 
	void makeHit(Vector2f pos, Missile &mis) {
		if (alien.getGlobalBounds().contains(pos)) {
			hit = true;
			mis.setCollision(true);
		}
	}

	//====================================================== 
	// makehit(): determines whether missile hit or not
	// parameters: ector2f pos, Missile &mis
	// return type: n/a
	//====================================================== 
	Vector2f getPosition() {
		return alien.getPosition();
	}

	//====================================================== 
	// makehit(): determines whether missile hit or not
	// parameters: ector2f pos, Missile &mis
	// return type: n/a
	//====================================================== 
	void draw(RenderWindow &win) {
		win.draw(alien);
		alien.move(0, 1);
	}

	//====================================================== 
	// makehit(): determines whether missile hit or not
	// parameters: ector2f pos, Missile &mis
	// return type: n/a
	//====================================================== 
	void dropBomb(Texture &text, BombManager &list) {
		Bomb* bomb = new Bomb(alien.getPosition(), text);
		list.addBomb(*bomb);
	}

	//====================================================== 
	// makehit(): determines whether missile hit or not
	// parameters: ector2f pos, Missile &mis
	// return type: n/a
	//====================================================== 
	Vector2f returnInitialPos() {
		return initialPos;
	}

	//====================================================== 
	// makehit(): determines whether missile hit or not
	// parameters: ector2f pos, Missile &mis
	// return type: n/a
	//====================================================== 
	void setPosition(Vector2f pos) {
		alien.setPosition(pos);
	}
};