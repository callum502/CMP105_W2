#include "Level.h"
#include "Framework/Input.h"
#include <iostream>
#include<string>
using namespace std;


Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	if (!fontx.loadFromFile("font/arial.ttf"))
	{
		std::cout << "error";
	}
	textx.setFont(fontx);
	textx.setPosition(0, 0);
	textx.setString("Hello world");
	textx.setCharacterSize(24);
	textx.setFillColor(sf::Color::Red);

	if (!fonty.loadFromFile("font/arial.ttf"))
	{
		std::cout << "error";
	}
	texty.setFont(fonty);
	texty.setPosition(60, 0);
	texty.setString("Hello world");
	texty.setCharacterSize(24);
	texty.setFillColor(sf::Color::Red);
}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	int x, y;
	x = input->getMouseX();
	y = input->getMouseY();
	string strX = std::to_string(x);
	string strY = std::to_string(y);
	
	textx.setString(strX);
	texty.setString(strY);


}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(textx);
		window->draw(texty);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}