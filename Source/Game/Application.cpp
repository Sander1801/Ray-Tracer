#include "World.h"
#include "Utilities/Dimension.h"

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// Window dimensions
	Dimension windowDimension;
	windowDimension.m_iHeight = 750;
	windowDimension.m_iWidth = 800;

	// Setup window
	sf::RenderWindow window(sf::VideoMode(windowDimension.m_iWidth, windowDimension.m_iHeight), "Ray Tracer");

	// Create the World.
	World gameWorld(windowDimension, window);

	// Setup a clock so we can track the delta time.
	//sf::Clock clock;
//	float fCurrentTime = clock.getElapsedTime().asSeconds();

	while (window.isOpen())
	{
		// Calculate the delta time
	//	float fNewTime = clock.getElapsedTime().asSeconds();
	//	float fDeltaTime = fNewTime - fCurrentTime;

	//	fCurrentTime = fNewTime;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//window.clear();
	//	window.display();
	}

	return 0;
}