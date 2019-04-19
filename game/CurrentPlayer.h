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
	CurrentPlayer() {
		currentLevel = 0;
		livesLeft = 3;
		aliensKilled = 0;
	}

	int getLevel() {
		return currentLevel;
	}

	int getLives() {
		return livesLeft;
	}

	int getKills() {
		return aliensKilled;
	}

	void setLevel(int x) {
		currentLevel = x;
	}

	void setLives(int x) {
		livesLeft = x;
	}

	void setKills(int x) {
		aliensKilled = x;
	}
};