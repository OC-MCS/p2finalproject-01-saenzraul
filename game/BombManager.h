#pragma once
#include <iostream>
using namespace std;
#include<SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include<time.h>
#include <stdlib.h>
#include "Bomb.h"
#include "CurrentPlayer.h"

class BombManager{
private:
	list<Bomb> listOfBombs;
public:
	BombManager() {
		listOfBombs = {};
	}

	void addBomb(Bomb a) {
		listOfBombs.push_back(a);
	}

	void removeBomb(Sprite &s, CurrentPlayer &p) {
		list<Bomb>::iterator iter;
		for (iter = listOfBombs.begin(); iter != listOfBombs.end(); ) {
			if (iter->returnHit() == true) {
				iter = listOfBombs.erase(iter);
				int life = p.getLives();
				life--;
				p.setLives(life);
				cout << "delete life ";
			}
			else if (iter->getPosition().y > s.getPosition().y + 20) {
				iter = listOfBombs.erase(iter);
			}
			else {
				iter++;
			}
		}
	}

	void draw(RenderWindow &win) {
		list<Bomb>::iterator iter;
		for (iter = listOfBombs.begin(); iter != listOfBombs.end(); iter++) {
			iter->draw(win);
		}
	}

	void setHits(Sprite &s)
	{
		list<Bomb>::iterator iter;
		for (iter = listOfBombs.begin(); iter != listOfBombs.end(); iter++) {
			iter->sethit(s.getPosition());
		}
	}

};
