


//
//  screen_0.hpp
//  Frogger
//
//  Created by Kristine Laranjo on 4/16/16.
//  Copyright © 2016 Kristine Laranjo. All rights reserved.
//
#include"player.h"
#include"player.cpp"
#include <iostream>
#include "cScreen.hpp"
//#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
// using inheritance to bring in variables and methods from the base class cScreen.
class screen_0 : public cScreen

{
private:
	
	bool playing;
public:
	screen_0(void);
	virtual int Run(sf::RenderWindow &App);
};

screen_0::screen_0(void)
{
	
	playing = false;
}

int screen_0::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	int menu = 0;
	// IF FILES DO NOT OPEN CORRECTLY OR IF THE FILES ARE NOT FOUND WITHIN THE DIRECTORY THEN WE WILL
	// AUTOMATICALLY EXIT THE GAME.
	/*
	if (!Texture.loadFromFile("background.jpg"))
	{
		std::cerr << "Error loading .png" << std::endl;
		return (-1);
	}
	*/
	Sprite.setTexture(Texture);
	Sprite.setColor(sf::Color(255, 255, 255));
	if (!Font.loadFromFile("VIDEOPHREAK.ttf"))
	{
		std::cerr << "Error loading .ttf" << std::endl;
		return (-1);
	}
	Menu1.setFont(Font);
	Menu1.setCharacterSize(40);
	Menu1.setString("Ready to play!");
	Menu1.setPosition({ 280, 160 });

	Menu2.setFont(Font);
	Menu2.setCharacterSize(40);
	Menu2.setString("Exit");
	Menu2.setPosition({ 280, 220 });


	

	while (Running)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
				case sf::Keyboard::Return:
					if (menu == 0)
					{
						//Let's get play !
						playing = true;
						return (1);
					}
					else
					{
						//Let's get work...
						return (-1);
					}
					break;
				default:
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		
		Sprite.setColor(sf::Color(255, 255, 255));
		if (menu == 0)
		{
			Menu1.setColor(sf::Color(255, 0, 0, 255));
			Menu2.setColor(sf::Color(255, 255, 255, 255));
			Menu3.setColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			Menu1.setColor(sf::Color(255, 255, 255, 255));
			Menu2.setColor(sf::Color(255, 0, 0, 255));
			Menu3.setColor(sf::Color(255, 255, 255, 255));
		}

		//Clearing screen
		App.clear();
		//Drawing
		App.draw(Sprite);
		
			if (playing)
			{
				App.draw(Menu3);
			}
			else
			{
				App.draw(Menu1);
			}
			App.draw(Menu2);
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}