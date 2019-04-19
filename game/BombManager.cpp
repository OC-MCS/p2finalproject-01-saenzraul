#include <iostream>
using namespace std;
#include<SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include "BombManager.h"
#include "CurrentPlayer.h"

BombManager::BombManager() {
	listOfBombs = {};
}
void BombManager::addBomb(Bomb a) {
	listOfBombs.push_back(a);
}
void BombManager::removeBomb(Sprite &sprite, CurrentPlayer &player) {
	list<Bomb>::iterator iter;
	for (iter = listOfBombs.begin(); iter != listOfBombs.end(); iter++) {
		if (iter->isTargetStruck() == true) {
			iter = listOfBombs.erase(iter);
			int life = player.getLives();
			life--;
			player.setLives(life);
			cout << "Ship Destoyed.   " << life << "    Amount of Lifes Remaining \n";
		} else if (iter->getBombPosition().y > sprite.getPosition().y + 20) {
			iter = listOfBombs.erase(iter);
		}
	}
}
void BombManager::draw(RenderWindow &win) {
	list<Bomb>::iterator iter;

	for (iter = listOfBombs.begin(); iter != listOfBombs.end(); iter++){
		iter->draw(win);
	}

}
void BombManager::setHit(Sprite &sprite) {
	list<Bomb>::iterator iter;

	for (iter = listOfBombs.begin(); iter != listOfBombs.end(); iter++) {
		iter->hitConfirm(sprite.getPosition());
	}

}