#include "World.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 480), "Falling Sand", sf::Style::Close | sf::Style::Titlebar);
	sf::Event event;

	window.setFramerateLimit(120);

	const float updateRate = 0.0088f; // Adjust to change the rate at which the sand falls.
	float updateTimer = updateRate;

	World world;

	sf::Clock clock;

	bool sandSelect = true, sandRedSelect = false, sandGreenSelect = false, sandBlueSelect = false, stoneSelect = false;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				sandSelect = true;
				sandRedSelect = false;
				sandGreenSelect = false;
				sandBlueSelect = false;
				stoneSelect = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				sandSelect = false;
				sandRedSelect = true;
				sandGreenSelect = false;
				sandBlueSelect = false;
				stoneSelect = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			{
				sandSelect = false;
				sandRedSelect = false;
				sandGreenSelect = true;
				sandBlueSelect = false;
				stoneSelect = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				sandSelect = false;
				sandRedSelect = false;
				sandGreenSelect = false;
				sandBlueSelect = true;
				stoneSelect = false;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			{
				sandSelect = false;
				sandRedSelect = false;
				sandGreenSelect = false;
				sandBlueSelect = false;
				stoneSelect = true;
			}

			// Makes it so we can place the sand where we click.
			sf::Vector2i pos = sf::Mouse::getPosition(window);

			int posX = floor(pos.x / world.cellSize);
			int posY = floor(pos.y / world.cellSize);
            
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (sandSelect) world.placeSand(posX, posY);
				else if (sandRedSelect) world.placeSandRed(posX, posY);
				else if (sandGreenSelect) world.placeSandGreen(posX, posY);
				else if (sandBlueSelect) world.placeSandBlue(posX, posY);
				else if (stoneSelect) world.placeStone(posX, posY);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				world.clear();
			}
		}

		float Timer = clock.restart().asSeconds();
		updateTimer -= Timer;

		if (updateTimer < 0.0f)
		{
			world.Update();
			updateTimer = updateRate;
		}

		window.clear(sf::Color::Black);
		world.Draw(window);
		window.display();
	}
}
