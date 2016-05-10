#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.hpp"
#include"player.h"

using namespace std;

int main(int argc, char** argv)
{
	//Applications variables
	std::vector<cScreen*> Screens;// creating an object of type cScreen pointer  that is called screens
								// Without the asterisk we get a nasty error.
	int screen = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(799, 675, 76), "FROGGER DEMO");

	//Mouse cursor no more visible
	//App.setMouseCursorVisible(false);

	//Screens preparations
	screen_0 s0;
	Screens.push_back(&s0);
	screen_1 s1;
	Screens.push_back(&s1);

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}


/*
int main(int argc, char** argv)
{
	sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Frogger Game");
	//sf::Event event;
	sf::Font font;
	font.loadFromFile("arial.ttf");
	// A Clock starts counting as soon as it's created
	sf::Clock clock;
	sf::Text text;
	
	text.setFont(font);


	text.setString("Welcome To Frogger");
	text.setCharacterSize(30);
	text.setColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	
	sf::FloatRect bounds(text.getLocalBounds());
	text.setPosition(renderWindow.getSize().x / 2 - (bounds.left + bounds.width / 2),
		renderWindow.getSize().y / 2 - (bounds.top + bounds.height / 2));

	//renderWindow.draw(text);
	//renderWindow.display();
	//renderWindow.clear();
	
	while (renderWindow.isOpen())
	{
		sf::Event event;
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)// this closes the window
				renderWindow.close();

			
				
			
		}
		if (clock.getElapsedTime().asSeconds() > 5.0)
		{
			renderWindow.draw(text);
			renderWindow.display();
			renderWindow.clear();

		}
			

		
		// A microsecond is 1/1,000,000th of a second, 1000 microseconds == 1 millisecond
		//std::cout << "Elapsed time since previous frame(microseconds): " << clock.getElapsedTime().asMicroseconds() << std::endl;
		// Start the countdown over.  Think of laps on a stop watch.
		//clock.restart();

		renderWindow.clear();
		// Draw our text object to the window
		//renderWindow.draw(text);
		//renderWindow.display();
		
		
	}


}
*/