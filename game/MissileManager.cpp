#include "MissileManager.h"
#include "Missile.h"
#include <iostream>
using namespace std;
#include<SFML/Graphics.hpp>
using namespace sf;
#include<list>


MissileManager::MissileManager() {
	listOfMissiles = {};
}
void MissileManager::addMissile(Missile m) {
	listOfMissiles.push_back(m);
}
void MissileManager::removeMissile(Sprite Backdrop) {
	list<Missile>::iterator iter;
	for (iter = listOfMissiles.begin(); iter != listOfMissiles.end(); iter++ ) {
		if (!Backdrop.getGlobalBounds().contains(iter->getPosition()) || iter->hasCollided() == true){
			iter = listOfMissiles.erase(iter);
		} 
	}
}
void MissileManager::draw(RenderWindow &win) {
	list<Missile>::iterator iter;

	for (iter = listOfMissiles.begin(); iter != listOfMissiles.end(); iter++){
		iter->draw(win);
	}
}
list<Missile> MissileManager::returnMissileList() {
	return listOfMissiles;
}
void MissileManager::setList(list<Missile> x) {
	listOfMissiles = x;
}