//=========================================================
// This is just the starting point for your final project.
// You are expected to modify and add classes/files as needed.
// The code below is the original code for our first graphics
// project (moving the little green ship). 
//========================================================
#include <iostream>
#include <list>
using namespace std;
#include <SFML/Graphics.hpp>
#include "Missile.h"
#include "MissileManager.h"
#include "AlienManager.h"
#include "CurrentPlayer.h"
#include "Bomb.h"
#include "BombManager.h"
#include "DrawUI.h"
#include <stdlib.h>     
#include <time.h> 
using namespace sf;

//============================================================
// 
// 4/19/19
// Final Project: Space Invaders
//============================================================

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position
// ship.move(offsetX, offsetY) adds offsetX, offsetY to 
// the current position of the ship. 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen
void moveShip(Sprite& ship)
{
	const float DISTANCE = 5.0f;
	Vector2f location = ship.getPosition();
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		if (location.x > 0) {
			ship.move(-DISTANCE, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{

		// right arrow is pressed: move our ship right 5 pixels

		if (location.x < 780) {
			ship.move(DISTANCE, 0);
		}
	}
}

/*************
resetGame
- Sets kills, level, and lives to default settings,
- and remakes each list of aliens
Params: textures, player, and both lists of aliens
****************/
void resetGame(Texture &text, Texture &text2, CurrentPlayer &p, AlienManager &mgr, AlienManager &m)
{
	p.setKills(0);
	p.setLevel(0);
	p.setLives(3);
	mgr.deleteList();
	m.deleteList();
	mgr.remakeList(text);
	m.remakeList(text2);
}


int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture AlienTexture;
	if (!AlienTexture.loadFromFile("alienOne.jpg"))
	{
		cout << "unable to load alien texture" << endl;
		exit(EXIT_FAILURE);
	}
	Texture level2Alien;
	if (!level2Alien.loadFromFile("alientwo.jpg"))
	{
		cout << "unable to load alien texture" << endl;
		exit(EXIT_FAILURE);
	}
	Texture bombTexture;
	if (!bombTexture.loadFromFile("bomb.jpg"))
	{
		cout << "unable to load bomb texture" << endl;
		exit(EXIT_FAILURE);
	}



	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like

	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);

	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.2f;
	ship.setPosition(shipX, shipY);

	MissileManager missileMgr;
	AlienManager initialaliens(AlienTexture);
	AlienManager alienMgr(AlienTexture);
	AlienManager level2Aliens(level2Alien);
	BombManager bombMgr;
	CurrentPlayer play;
	DrawUI drawUI;

	int randomNum;
	bool drop;

	int counter = 0;
	int kills = 0;
	bool shoot = false;
	bool hasWon = false;
	bool hasLost = false;

	while (window.isOpen()){
		Event event;
		if (play.getLevel() == 0){
			while (window.pollEvent(event)){
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();
				else if (event.type == Event::MouseButtonReleased){
					//userinput for settings
					Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
					drawUI.beginGame(mousePos, play);
				}
			}
			window.clear();
			window.draw(background);
			drawUI.drawStart(window);
			if (hasWon == true){
				drawUI.drawWinner(window);
			}
			if (hasLost == true){
				drawUI.drawEndGame(window);
			}
			window.display();
		} else if (play.getLevel() == 1 && play.getLives() > 0) {
			if (hasWon == true) {
				drawUI.drawWinner(window);
			}
			counter++;
			if ((counter % 15) == 14) {
				shoot = true;
			}
			while (window.pollEvent(event)) {
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();
				else if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Space && shoot == true) {
						// handle space bar
						Missile *missile = new Missile(ship.getPosition(), missileTexture);
						missileMgr.addMissile(*missile);
						shoot = false;
					}
				}
			}
			window.clear();
			window.draw(background);
			moveShip(ship);
			window.draw(ship);
			drawUI.drawKillAmount(window, play);
			drawUI.drawLives(window, play);
			drawUI.drawLevel(window, play);
			alienMgr.setHit(missileMgr);
			// Resets Game when Aliens go past screen can't figure out how to move aliens back
			if (alienMgr.removeAlien(ship, play) == true) {
				window.clear();
				window.draw(background);
				drawUI.drawEndGame(window);
				resetGame(AlienTexture, level2Alien, play, alienMgr, level2Aliens);
				drawUI.drawStart(window);
				hasLost = true;
			}
			alienMgr.draw(window);
			bombMgr.removeBomb(ship, play);
			bombMgr.setHits(ship);
			bombMgr.draw(window);
			missileMgr.removeMissile(background);
			missileMgr.drawMissiles(window);

			if (counter % 50 == 1){
				drop = true;
			}
			randomNum = (rand() % 20);
			if (randomNum == 1 && drop == true){
				alienMgr.dropBombs(bombTexture, bombMgr);
				drop = false;
			}

			if (alienMgr.returnAlienCount() == 0){
				play.setLevel(2);
			}

			if (play.getLives() == 0) {
				window.clear();
				window.draw(background);
				drawUI.drawEndGame(window);
				resetGame(AlienTexture, level2Alien, play, alienMgr, level2Aliens);
				drawUI.drawStart(window);
				hasLost = true;
			}

			window.display();
		} else if (play.getLevel() == 2 && play.getLives() > 0) {
			counter++;
			if ((counter % 15) == 14) {
				shoot = true;
			}
			while (window.pollEvent(event)) {
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();
				else if (event.type == Event::KeyPressed) {
					if (event.key.code == Keyboard::Space && shoot == true) {
						// handle space bar
						Missile *missile = new Missile(ship.getPosition(), missileTexture);
						missileMgr.addMissile(*missile);
						shoot = false;
					}
				}
			}
			window.clear();
			window.draw(background);
			moveShip(ship);
			window.draw(ship);
			if (counter % 20 == 1) {
				drop = true;
			}
			randomNum = (rand() % 35);
			if (randomNum == 1 && drop == true){
				level2Aliens.dropBombs(bombTexture, bombMgr);
				drop = false;
			}

			drawUI.drawKillAmount(window, play);
			drawUI.drawLives(window, play);
			drawUI.drawLevel(window, play);
			level2Aliens.setHit(missileMgr);
			// Resets Game when Aliens go past screen can't figure out how to move aliens back
			if (level2Aliens.removeAlien(ship, play) == true) {
				window.clear();
				window.draw(background);
				drawUI.drawEndGame(window);
				resetGame(AlienTexture, level2Alien, play, alienMgr, level2Aliens);
				drawUI.drawStart(window);
				hasLost = true;
			}
			level2Aliens.draw(window);
			bombMgr.removeBomb(ship, play);
			bombMgr.setHits(ship);
			bombMgr.draw(window);
			missileMgr.removeMissile(background);
			missileMgr.drawMissiles(window);

			if (play.getLives() == 0) {
				window.clear();
				window.draw(background);
				drawUI.drawEndGame(window);
				resetGame(AlienTexture, level2Alien, play, alienMgr, level2Aliens);
				drawUI.drawStart(window);
				hasLost = true;
			}
			if (play.getKills() == 20) {
				window.clear();
				window.draw(background);
				drawUI.drawWinner(window);
				resetGame(AlienTexture, level2Alien, play, alienMgr, level2Aliens);
				drawUI.drawStart(window);
				hasWon = true;
			}

			window.display();
		}


		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it




		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================


		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);


		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)


		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}