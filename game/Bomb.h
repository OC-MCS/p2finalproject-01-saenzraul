#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>
#include <stdlib.h>     
#include <time.h> 
#include "CurrentPlayer.h"

class Bomb
{
private:
	Sprite bomb;
	bool isTargetHit;

public:
	Bomb(Vector2f pos, Texture &text); //Constructor
	void draw(RenderWindow &win); 
	bool isTargetStruck();
	Vector2f getBombPosition();
	void hitConfirm(Vector2f shipPosition);
};



