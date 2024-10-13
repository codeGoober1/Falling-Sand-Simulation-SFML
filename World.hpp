#pragma once
#include <SFML/Graphics.hpp>

class World
{
public:
	World();
	void clear();
	void placeSand(int x, int y);
	void placeSandRed(int x, int y);
	void placeSandGreen(int x, int y);
	void placeSandBlue(int x, int y);
	void placeStone(int x, int y);
	void Update();
	void Draw(sf::RenderWindow& window);

	int cellSize = 3;
private:
	static const int width = 161;
	static const int height = 161;

	int oldGrid[width][height]; 
	/*
	oldGrid is used for our previous grid.
	When a cell's state changes to 1 we will then update that cell.
	*/

	int newGrid[width][height]; 
	// newGrid is used for updating and drawing.

	sf::RectangleShape sand;
	sf::RectangleShape sandRed;
	sf::RectangleShape sandGreen;
	sf::RectangleShape sandBlue;
	sf::RectangleShape stone;
};
