#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include <stdlib.h>     
#include <time.h> 
#include "CurrentPlayer.h"
#include "Bomb.h"

Bomb::Bomb(Vector2f pos, Texture &text) {
	isTargetHit = false;
	bomb.setPosition(pos);
	bomb.setTexture(text);
	//bomb.setScale()
}
void Bomb::draw(RenderWindow &win) {
	win.draw(bomb);
	bomb.move(0, 4.0f);
}
bool Bomb::isTargetStruck() {
	return isTargetHit;
}
Vector2f Bomb::getBombPosition() {
	return bomb.getPosition();
}
void Bomb::hitConfirm(Vector2f shipPosition) {
	if (bomb.getGlobalBounds().contains(shipPosition)) {
		cout << "The Ship has recieved Damage from a Bomb! \n";
		isTargetHit = true;

		}
}
