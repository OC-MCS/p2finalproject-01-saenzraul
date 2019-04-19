#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

#include "CurrentPlayer.h"

CurrentPlayer::CurrentPlayer() {
	livesLeft = 3;
	aliensKilled = 0;
	currentLevel = 1;
}
int CurrentPlayer::getLevel() {
	return currentLevel;
}
int CurrentPlayer::getKills() {
	return aliensKilled;
}
int CurrentPlayer::getLives() {
	return livesLeft;
}
void CurrentPlayer::setLevel(int level) {
	currentLevel = level;
}
void CurrentPlayer::setKills(int kills) {
	aliensKilled = kills;
}
void CurrentPlayer::setLives(int lives) {
	; livesLeft = lives;
}