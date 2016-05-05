#include <iostream>
#include "cScreen.hpp"
#include"player.h"
//#include"player.cpp"
#include<iostream>
#include<string>
//#include <Text.hpp>


#include <SFML/Graphics.hpp>
using namespace std;
// using inheritance to bring in variables and methods from the base class cScreen.
class screen_0 : public cScreen, public Player

{
private:
	//int alpha_max;
	//int alpha_div;
	bool playing;
	
	
	
	
public:
	screen_0(void);
	virtual int Run(sf::RenderWindow &App);
};

screen_0::screen_0(void)
{
	//alpha_max = 3 * 255;
	//alpha_div = 3;
	playing = false;
	
}

int screen_0::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	//int alpha = 0;
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	sf::Text Menu4;
	sf::Text Menu5;
	int menu = 0;
	string str;
	sf::Text text;
	
	//cout << playerName << endl;
	// IF FILES DO NOT OPEN CORRECTLY OR IF THE FILES ARE NOT FOUND WITHIN THE DIRECTORY THEN WE WILL
	// AUTOMATICALLY EXIT THE GAME.

	if (!Texture.loadFromFile("background.jpg"))
	{
		std::cerr << "Error loading .png" << std::endl;
		return (-1);
	}
	Sprite.setTexture(Texture);
	//Sprite.setColor(sf::Color(255, 255, 255, alpha));
	if (!Font.loadFromFile("arial.ttf"))
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

	Menu5.setFont(Font);
	Menu5.setCharacterSize(30);
	Menu5.setString("Player Name:  ");
	Menu5.setPosition({ 280, 300 });



	//if (playing)
	//{
		//alpha = alpha_max;
	//}

	while (Running)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			//Messing with user input here*******
			/*
			if (Event.type == sf::Event::TextEntered)
			{
				// Handle ASCII characters only
				if (Event.text.unicode < 128)
				{
					this-> playerName += static_cast<char>(Event.text.unicode);
					//Text.SetText(this-> playerName);





				}
			}

			*/
			if (Event.type == sf::Event::TextEntered)
			{
				// Handle ASCII characters only
				if (Event.text.unicode < 128)
				{
					
					str += static_cast<char>(Event.text.unicode);
					text.setString(str);
					text.setFont(Font);
					text.setCharacterSize(25);
					text.setPosition({ 280, 350 });

				//	text.setString(str);
					//playerName = playerName + str;
					cout << str << endl;
					this->playerName = str;
				//	cout << this-> playerName << endl;
					setPlayerName(str);
				}
			}
		

			//************************************
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
	/*	
		if (alpha<alpha_max)
		{
			alpha++;
		}
*/		
		//Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
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
	//	App.draw(Sprite);
		App.draw(text);
		App.draw(Menu5);
		//if (alpha == alpha_max)
		//{
			if (playing)
			{
				App.draw(Menu3);
			}
			else
			{
				App.draw(Menu1);
			}
			App.draw(Menu2);
		//}
		App.display();
		
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}