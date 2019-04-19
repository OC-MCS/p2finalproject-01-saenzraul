#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include"Missile.h"

Missile:: Missile(Vector2f pos, Texture &text) {
	missile.setPosition(pos);
	missile.setTexture(text);
	collide = false;
}
bool Missile:: hasCollided() {
	return collide;
}
Sprite Missile:: returnSprite() {
	return missile;
}
void Missile::setCollison(bool collided) {
	collide = collided;
}
void Missile:: draw(RenderWindow &win) {
	win.draw(missile);
	missile.move(0, -10.0f);
}
Vector2f Missile::getPosition() {
	return missile.getPosition();
}