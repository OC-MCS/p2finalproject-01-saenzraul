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
	void addMissile(Missile m) {
		listOfMissiles.push_back(m);
	}

	void drawMissiles(RenderWindow &win) {
		list<Missile>::iterator iter;
		for (iter = listOfMissiles.begin(); iter != listOfMissiles.end(); iter++) {
			iter->draw(win);
		}

	}

	void removeMissile(Sprite background) {
		list<Missile>::iterator iter;
		for (iter = listOfMissiles.begin(); iter != listOfMissiles.end(); ) {
			if (!background.getGlobalBounds().contains(iter->getPosition()) || iter->getCollision() == true) {
				iter = listOfMissiles.erase(iter);
			}
			else {
				iter++;
			}
		}

	}

	list<Missile> returnMissileList() {
		return listOfMissiles;
	}

	void setList(list<Missile> x) {
		listOfMissiles = x;
	}
};
