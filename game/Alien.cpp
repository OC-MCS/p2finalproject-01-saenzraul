#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include "Bomb.h"
#include "BombManager.h"
#include "Alien.h"

Alien::Alien(Vector2f pos, Texture &text){
	alien.setPosition(pos);
	alien.setTexture(text);
	initialPos = pos;
	alien.setScale(0,0);
}
bool Alien:: returnHit() {
	return hit;
}
void Alien:: seeHit(Vector2f missilepos) {
	if(alien.getGlobalBounds().contains(missilepos)) {
		hit = true;
	}
}
Vector2f Alien:: getPosition() {
	return alien.getPosition();
}
void Alien:: draw(RenderWindow &win) {
	win.draw(alien);
	alien.move(0, 1);
}
void Alien:: dropBomb(Texture &text, BombManager &list) {
	Bomb* bomb = new Bomb(alien.getPosition(), text);
	list.addBomb(*bomb);
}
Vector2f Alien:: returnInitialPos() {
	return initialPos;
}
void Alien:: setPosition(Vector2f pos) {
	alien.setPosition(pos);
}
