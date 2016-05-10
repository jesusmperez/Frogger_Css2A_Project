#pragma once
//
//  screen_1.hpp
//  Frogger
//
//  Created by Kristine Laranjo on 4/22/16.
//  Copyright © 2016 Kristine Laranjo. All rights reserved.
//

#include <iostream>
#include "objects.h"
#include "create.h"
#include "cScreen.hpp"
//#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

class screen_1 : public cScreen
{
private:
	float movement_step;
	float posx;
	float posy;

	//sf::RectangleShape Rectangle;
	sf::Sprite frogger;
	sf::Texture texture1;
	sf::Texture texture2;
	sf::IntRect rectSourceSprite;
	sf::Sprite background;
	sf::Texture bg;
	sf::Sprite truck;
	sf::Sprite truck2;
	sf::Sprite car;
	sf::Sprite car2;
	sf::Sprite car3;
	sf::Sprite shortLog;
	sf::Sprite shortLog2;
	sf::Sprite shortLog3;
	sf::Sprite longLog;
	sf::Sprite longLog2;
	sf::Sprite lillypad;
	sf::Sprite lillypad2;
	sf::Sprite lillypad3;
	sf::Sprite lillypad4;
	sf::Sprite lillypad5;

public:
	screen_1(void);
	virtual int Run(sf::RenderWindow &App);
};

screen_1::screen_1(void)
{
	texture1.loadFromFile(resourcePath() + "spritesheet.png");
	texture2.loadFromFile(resourcePath() + "vehicles.png");

	Create t1(truck, rectSourceSprite, texture2, 0, 0, 148, 159, 1.5, 1.5, 130, 420);
	Create t2(truck2, rectSourceSprite, texture2, 148, 0, 148, 159, 1.5, 1.5, 550, 290);
	Create c1(car, rectSourceSprite, texture2, 300, 0, 146, 149, 1.7, 1.7, -230, 420);
	Create c2(car2, rectSourceSprite, texture2, 446, 0, 146, 149, 1.7, 1.7, 280, 289);
	Create c3(car3, rectSourceSprite, texture2, 446, 0, 146, 149, 1.7, 1.7, 0, 289);
	Create s1(shortLog, rectSourceSprite, texture1, 289, 0, 146, 196, 1, 1, 0, 129);
	Create s2(shortLog2, rectSourceSprite, texture1, 435, 0, 141, 196, 1, 1, 200, 65);
	Create s3(shortLog3, rectSourceSprite, texture1, 289, 0, 146, 196, 1, 1, 300, 8);
	Create l1(longLog, rectSourceSprite, texture1, 577, 0, 205, 196, 1, 1, 799, 8.3);
	Create l2(longLog2, rectSourceSprite, texture1, 577, 0, 205, 196, 1, 1, 500, 138);
	Create leaf(lillypad, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 0, -32);
	Create leaf2(lillypad2, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 167.5, -32);
	Create leaf3(lillypad3, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 335, -32);
	Create leaf4(lillypad4, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 502.5, -32);
	Create leaf5(lillypad5, rectSourceSprite, texture2, 610, 0, 115, 196, 1, 1, 670, -32);

	//Frogger
	rectSourceSprite.left = 0;
	rectSourceSprite.top = 55;
	rectSourceSprite.width = 89;
	rectSourceSprite.height = 83;
	frogger.setTexture(texture1, true);
	frogger.setTextureRect(rectSourceSprite);
	frogger.setPosition(320, 605);

	//Create background
	bg.loadFromFile(resourcePath() + "background.jpg");
	background.setTexture(bg, true);

}

int screen_1::Run(sf::RenderWindow &App)
{
	sf::Event Event;

	bool Running = true;

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				sf::Vector2f pos = frogger.getPosition();

				if (pos.x <= 15 || (pos.x <= 15 && pos.y <= 675))
				{
					frogger.move(0, 0);
				}// end if
				else
				{
					if (rectSourceSprite.left != 216)
					{
						rectSourceSprite.left = 216;
						rectSourceSprite.width = 55;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(-50, 0);

				}// end else
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				sf::Vector2f pos = frogger.getPosition();

				if (pos.x >= 690)
				{
					frogger.move(0, 0);
				}// end if
				else
				{
					if (rectSourceSprite.left != 89)
					{
						rectSourceSprite.left = 89;
						rectSourceSprite.width = 60;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(50, 0);

				}// end else
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				sf::Vector2f pos = frogger.getPosition();

				if (pos.y <= -35)
				{
					frogger.move(0, 0);
				}// end if
				else
				{
					if (rectSourceSprite.left != 0)
					{
						rectSourceSprite.left = 0;
						rectSourceSprite.width = 89;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(0, -50);
				}
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				sf::Vector2f pos = frogger.getPosition();

				if (pos.y >= 540)
				{
					frogger.move(0, 0);
				}// end if
				else
				{
					if (rectSourceSprite.left != 149)
					{
						rectSourceSprite.left = 149;
						rectSourceSprite.width = 67;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(0, 50);

				}// end else
			}// end if
		}

		// Creating the objects
		Object t1(130, 420, 0.5);
		Object t2(550, 290, 0.3);
		Object c1(-50, 420, 0.5);
		Object c2(280, 289, 0.3);
		Object c3(0, 289, 0.3);
		Object sl1(0, 125, 0.2);
		Object sl2(200, 61, 0.3);
		Object sl3(300, 8, 0.4);
		Object l1(799, 8.3, 0.4);
		Object l2(500, 125, 0.2);

		t1.moveRight(truck);
		t2.moveLeft(truck2);
		c1.moveRight(car);
		c2.moveLeft(car2);
		c3.moveLeft(car3);
		sl1.moveRight(shortLog);
		sl2.moveLeft(shortLog2);
		sl3.moveRight(shortLog3);
		l1.moveRight(longLog);
		l2.moveRight(longLog2);

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));

		//Drawing
		App.draw(background);
		App.draw(truck);
		App.draw(truck2);
		App.draw(car);
		App.draw(car2);
		App.draw(car3);
		App.draw(longLog);
		App.draw(longLog2);
		App.draw(shortLog);
		App.draw(shortLog2);
		App.draw(shortLog3);
		App.draw(lillypad);
		App.draw(lillypad2);
		App.draw(lillypad3);
		App.draw(lillypad4);
		App.draw(lillypad5);
		App.draw(frogger);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}