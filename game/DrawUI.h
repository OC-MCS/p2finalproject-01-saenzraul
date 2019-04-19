#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "CurrentPlayer.h"

class DrawUI
{
private:
	RectangleShape startBtn;
	Font font;
	Font font2;


public:
	DrawUI() {
		Vector2f size(80, 30);
		startBtn.setSize(size);
		startBtn.setPosition(385, 375);
		startBtn.setFillColor(Color::Black);

		if (!font.loadFromFile("C://Windows//Fonts//alger.ttf")) {
			cout << ("couldn't load font");
		}
		if (!font2.loadFromFile("C://Windows//Fonts//agencyb.ttf")) {
			cout << ("couldn't load font");
		}
	}

	void drawStart(RenderWindow & win) {
		Text title("ALIENS", font2, 72);
		title.setPosition(325, 200);
		Text sub("A Programing Story", font2, 36);
		sub.setPosition(290, 300);
		sub.setFillColor(Color::White);
		title.setFillColor(Color::White);
		Text text("PLAY", font2, 25);
		text.setPosition(startBtn.getPosition());
		text.setFillColor(Color::White);
		win.draw(title);
		win.draw(sub);
		win.draw(startBtn);
		win.draw(text);
	}

	void beginGame(Vector2f mousepos, CurrentPlayer &p) {
		if (startBtn.getGlobalBounds().contains(mousepos)) {
			p.setLevel(1);
		}
	}

	void drawKillAmount(RenderWindow & win, CurrentPlayer &p) {
		string displaykilled = "Score: " + to_string(p.getKills());
		Text numkilled(displaykilled, font, 25);
		numkilled.setPosition(0, 0);
		numkilled.setFillColor(Color::White);
		win.draw(numkilled);
	}

	void drawLevel(RenderWindow & win, CurrentPlayer &p) {
		string text = "Level:  " + to_string(p.getLevel());
		Text display(text, font, 25);
		display.setPosition(350, 0);
		display.setFillColor(Color::White);
		win.draw(display);
	}

	void drawEndGame(RenderWindow & win) {
		string text = "Game over. You Lost";
		Text display(text, font, 40);
		display.setPosition(200, 100);
		display.setFillColor(Color::White);
		win.draw(display);
	}

	void drawWinner(RenderWindow & win) {
		string text = "Congrats!! You win!!!";
		Text display(text, font, 40);
		display.setPosition(200, 100);
		display.setFillColor(Color::White);
		win.draw(display);
	}

	void drawLives(RenderWindow & win, CurrentPlayer p) {
		string text = "Lives:  " + to_string(p.getLives());
		Text display(text, font, 25);
		display.setPosition(700, 0);
		display.setFillColor(Color::White);
		win.draw(display);
	}
};
