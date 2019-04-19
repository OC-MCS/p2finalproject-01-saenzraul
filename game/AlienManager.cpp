#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Alien.h"
#include "Bomb.h"
#include "BombManager.h"
#include "MissileManager.h"
#include "CurrentPlayer.h"
#include "AlienManager.h"

AlienManager::AlienManager(Texture &text) {
	Vector2f pos;
	pos.y = 20;
	pos.x = 0;
	for (int i = 0; i < 10; i++){

		pos.x += 65;
		addAlien(pos, text);
	}
}
void AlienManager::addAlien(Vector2f pos, Texture &text) {
	Alien *alien = new Alien(pos, text);
	listOfAliens.push_back(*alien);
}
void AlienManager::removeAlien(Sprite &sprite, CurrentPlayer &player) {
	list<Alien>::iterator iter;

	for (iter = listOfAliens.begin(); iter != listOfAliens.end(); ) {
		if (iter->returnHit() == true){

			int kills = player.getKills();
			kills++;
			player.setKills(kills);
			iter = listOfAliens.erase(iter);
		} else if (iter->getPosition().y > sprite.getPosition().y + 20) {

			Vector2f initial = iter->returnInitialPos();
			iter->setPosition(initial);
			int life = player.getLives();
			life--;
			player.setLives(life);
		} else {
			iter++;
		}
	}
}
void AlienManager::draw(RenderWindow &win) {
	list<Alien>::iterator iter;

	for (iter = listOfAliens.begin(); iter != listOfAliens.end(); iter++){
		iter->draw(win);
	}
}
void AlienManager::setHit(MissileManager &mgr) {
	list<Alien>::iterator iter;
	list<Missile>::iterator it;
	list<Missile> missilelist = mgr.returnMissileList();

	for (iter = listOfAliens.begin(); iter != listOfAliens.end(); iter++) {
		for (it = missilelist.begin(); it != missilelist.end(); it++) {
			iter->seeHit(it->getPosition());
		}
	}
}
void AlienManager::dropBombs(Texture &text, BombManager &bombMgr) {
	int x;
	list<Alien>::iterator iter;
	srand(time(0));
	bool shoot = true;

	for (iter = listOfAliens.begin(); iter != listOfAliens.end() && shoot == true; iter++) {
		x = (rand() % 10);
		if (x == 1) {
			iter->dropBomb(text, bombMgr);
			shoot = false;
		}
	}
}
int  AlienManager::returnAlienCount() {
	return listOfAliens.size();
}