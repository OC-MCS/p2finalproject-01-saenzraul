#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include <list>

class AlienTexture {
private:
	Texture alienTexture;
public:
	AlienTexture() {
		Texture alienText;
		if (!alienText.loadFromFile("alieninvader.jpg"))
		{
			cout << "Unable to load alien texture!" << endl;
			exit(EXIT_FAILURE);
		}
		alienTexture = alienText;
	}
};

