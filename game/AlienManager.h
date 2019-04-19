#pragma once
#include <iostream>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include<time.h>
#include <stdlib.h>
#include "Alien.h"
#include "Bomb.h"
#include "BombManager.h"
#include "CurrentPlayer.h"

class AlienManager {
private:
	list<Alien> alienList;

public:
	AlienManager(Texture &text) {
		Vector2f pos;
		pos.y = 20;
		pos.x = 0;
		for (int i = 0; i < 10; i++) {
			pos.x += 65;
			addAlien(pos, text);
		}

	}

	void addAlien(Vector2f pos, Texture &text) {
		Alien *alien = new Alien(pos, text);
		alienList.push_back(*alien);
	}

	void removeAlien(Sprite &s, CurrentPlayer &p) {
		list<Alien>::iterator iter;
		for (iter = alienList.begin(); iter != alienList.end(); ) {
			if (iter->returnHit() == true) {
				int kills = p.getKills();
				kills++;
				p.setKills(kills);
				iter = alienList.erase(iter);
			}
			else if (iter->getPosition().y > s.getPosition().y + 20) {
				Vector2f initial = iter->returnInitialPos();
				iter->setPosition(initial);
				int life = p.getLives();
				life--;
				p.setLives(life);

			}
			else {
				iter++;
			}

		}
	}

	void draw(RenderWindow &win) {
		list<Alien>::iterator iter;

		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			iter->draw(win);
		}
	}
	/*******
	setHit
	- Goes through each alien and missile and checks if they have collided
	Prams: missile manager
	Returns: None
	*****/
	void setHit(MissileManager &mgr) {
		list<Alien>::iterator iter;
		list<Missile>::iterator it;
		list<Missile> missilelist = mgr.returnMissileList();

		for (iter = alienList.begin(); iter != alienList.end(); iter++)
		{
			for (it = missilelist.begin(); it != missilelist.end(); it++)
			{
				iter->makeHit(it->getPosition(), *it);
			}
		}
		mgr.setList(missilelist);
	}


	void dropBombs(Texture &text, BombManager &bombMgr) {
		int x;
		list<Alien>::iterator iter;
		srand(time(0));

		bool shoot = true;
		for (iter = alienList.begin(); iter != alienList.end() && shoot == true; iter++) {
			x = (rand() % 10);
			if (x == 1)
			{
				iter->dropBomb(text, bombMgr);
				shoot = false;
			}
		}
	}

	int returnAlienCount(){
		return alienList.size();
	}

	void deleteList() {
		list<Alien>::iterator iter;

		for (iter = alienList.begin(); iter != alienList.end(); iter++) {
			iter = alienList.erase(iter);
		}
	}

	void remakeList(Texture &text) {
		Vector2f pos;
		pos.y = 20;
		pos.x = 0;
		for (int i = 0; i < 10; i++) {
			pos.x += 65;
			addAlien(pos, text);
		}
	}
};
