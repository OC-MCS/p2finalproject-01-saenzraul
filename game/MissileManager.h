#pragma once
#include <iostream>
using namespace std;
#include<SFML/Graphics.hpp>
using namespace sf;
#include<list>
#include "Missile.h"

class MissileManager {

private:
	list<Missile> listOfMissiles;

public:
	MissileManager();
	void addMissile(Missile m);
	void removeMissile(Sprite Backdrop);
	void draw(RenderWindow &win);
	list<Missile> returnMissileList();
	void setList(list<Missile> x);
};