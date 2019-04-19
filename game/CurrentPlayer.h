#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class CurrentPlayer {
private:
	int livesLeft;
	int aliensKilled;
	int currentLevel;
	RectangleShape startButton;
public:
	CurrentPlayer();
	int getLevel();
	int getKills();
	int getLives();
	void setLevel(int level);
	void setKills(int kills);
	void setLives(int lives);

};