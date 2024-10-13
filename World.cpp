#include "World.hpp"

// 0 = empty cell
// 1 = sand cell
// 2 = red sand cell
// 3 = green sand cell
// 4 = blue sand cell
// 5 = stone cell


World::World()
{
	for (int i = 0; i < width - 1; i++)
	{
		for (int j = 0; j < height - 1; j++)
		{
			oldGrid[i][j] = 0;
			newGrid[i][j] = 0;
		}
	}
}

void World::Update()
{
	for (int i = 0; i < width - 1; i++)
	{
		for (int j = 0; j < height - 1; j++)
		{
			// REGULAR SAND

			if (oldGrid[i][j] == 1)
			{

				// If there is a empty cell below then our sand cell will fall.
				if (newGrid[i][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i][j + 1] = 1;
				}

				// If there is a empty cell below an left then our sand cell will fall and go to left.
				else if (newGrid[i - 1][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i - 1][j + 1] = 1;
				}

				// If there is a empty cell below an right then our sand cell will fall and go to right.
				else if (newGrid[i + 1][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i + 1][j + 1] = 1;
				}

				// we will choose if we will go downright or downleft randomly.
				if (newGrid[i - 1][j + 1] == 1 && newGrid[i + 1][j + 1] == 1)
				{
					bool choice = rand() & 2;

					if (choice == 0)
					{
						newGrid[i - 1][j + 1] = 1;
					}

					else if (choice == 1)
					{
						newGrid[i + 1][j + 1] = 1;
					}
				}
			}

			// RED SAND

			// Same ideology as regular sand just a different color.

			if (oldGrid[i][j] == 2)
			{
				if (newGrid[i][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i][j + 1] = 2;
				}

				else if (newGrid[i - 1][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i - 1][j + 1] = 2;
				}

				else if (newGrid[i + 1][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i + 1][j + 1] = 2;
				}

				if (newGrid[i - 1][j + 1] == 2 && newGrid[i + 1][j + 1] == 2)
				{
					bool choice = rand() & 2;

					if (choice == 0)
					{
						newGrid[i - 1][j + 1] = 2;
					}

					else if (choice == 1)
					{
						newGrid[i + 1][j + 1] = 2;
					}
				}
			}

			// GREEN SAND

			// Same ideology as regular sand just a different color.

			if (oldGrid[i][j] == 3)
			{
				if (newGrid[i][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i][j + 1] = 3;
				}

				else if (newGrid[i - 1][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i - 1][j + 1] = 3;
				}

				else if (newGrid[i + 1][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i + 1][j + 1] = 3;
				}

				if (newGrid[i - 1][j + 1] == 3 && newGrid[i + 1][j + 1] == 3)
				{
					bool choice = rand() & 2;

					if (choice == 0)
					{
						newGrid[i - 1][j + 1] = 3;
					}

					else if (choice == 1)
					{
						newGrid[i + 1][j + 1] = 3;
					}
				}
			}

			// BLUE SAND

			// Same ideology as regular sand just a different color.

			if (oldGrid[i][j] == 4)
			{
				if (newGrid[i][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i][j + 1] = 4;
				}

				else if (newGrid[i - 1][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i - 1][j + 1] = 4;
				}

				else if (newGrid[i + 1][j + 1] == 0)
				{
					newGrid[i][j] = 0;
					newGrid[i + 1][j + 1] = 4;
				}

				if (newGrid[i - 1][j + 1] == 4 && newGrid[i + 1][j + 1] == 4)
				{
					bool choice = rand() & 2;

					if (choice == 0)
					{
						newGrid[i - 1][j + 1] = 4;
					}

					else if (choice == 1)
					{
						newGrid[i + 1][j + 1] = 4;
					}
				}
			}
		}
	}
}

void World::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < width - 1; i++)
	{
		for (int j = 0; j < height - 1; j++)
		{
			if (newGrid[i][j] == 1)
			{
				sand.setPosition(i * cellSize, j * cellSize);
				sand.setFillColor(sf::Color::Yellow);
				sand.setSize(sf::Vector2f(cellSize, cellSize));

				window.draw(sand);
			}

			if (newGrid[i][j] == 2)
			{
				sandRed.setPosition(i * cellSize, j * cellSize);
				sandRed.setFillColor(sf::Color::Red);
				sandRed.setSize(sf::Vector2f(cellSize, cellSize));

				window.draw(sandRed);
			}

			if (newGrid[i][j] == 3)
			{
				sandGreen.setPosition(i * cellSize, j * cellSize);
				sandGreen.setFillColor(sf::Color::Green);
				sandGreen.setSize(sf::Vector2f(cellSize, cellSize));

				window.draw(sandGreen);
			}

			if (newGrid[i][j] == 4)
			{
				sandBlue.setPosition(i * cellSize, j * cellSize);
				sandBlue.setFillColor(sf::Color::Blue);
				sandBlue.setSize(sf::Vector2f(cellSize, cellSize));

				window.draw(sandBlue);
			}

			if (newGrid[i][j] == 5)
			{
				stone.setPosition(i * cellSize, j * cellSize);
				stone.setFillColor(sf::Color(128, 128, 128));
				stone.setSize(sf::Vector2f(cellSize, cellSize));

				window.draw(stone);
			}

			oldGrid[i][j] = newGrid[i][j];
		}
	}
}

void World::clear()
{
	for (int i = 0; i < width - 1; i++)
	{
		for (int j = 0; j < height - 1; j++)
		{
			oldGrid[i][j] = 0;
			newGrid[i][j] = 0;
		}
	}
}

void World::placeSand(int x, int y)
{
	// make other cells around it 1
	newGrid[x][y] = 1;
	newGrid[x + 1][y + 1] = 1;
	newGrid[x - 1][y - 1] = 1;
	newGrid[x + 2][y - 1] = 1;
	newGrid[x - 2][y + 1] = 1;
}

void World::placeSandRed(int x, int y)
{
	newGrid[x][y] = 2;
	newGrid[x + 1][y + 1] = 2;
	newGrid[x - 1][y - 1] = 2;
	newGrid[x + 2][y - 1] = 2;
	newGrid[x - 2][y + 1] = 2;
}

void World::placeSandGreen(int x, int y)
{
	newGrid[x][y] = 3;
	newGrid[x + 1][y + 1] = 3;
	newGrid[x - 1][y - 1] = 3;
	newGrid[x + 2][y - 1] = 3;
	newGrid[x - 2][y + 1] = 3;
}

void World::placeSandBlue(int x, int y)
{
	newGrid[x][y] = 4;
	newGrid[x + 1][y + 1] = 4;
	newGrid[x - 1][y - 1] = 4;
	newGrid[x + 2][y - 1] = 4;
	newGrid[x - 2][y + 1] = 4;
}

void World::placeStone(int x, int y)
{
	newGrid[x][y] = 5;
}
