


#include"player.h"
#include"player.cpp"

#include <iostream>
#include "cScreen.hpp"


#include <SFML/Graphics.hpp>
using namespace std;

class screen_1 : public cScreen , public Player

{
private:
	
	float movement_step;
	float posx;
	float posy;
	//sf::RectangleShape Rectangle;
	sf::Sprite frogger;
	sf::Texture frog;
	sf::IntRect rectSourceSprite;
	//Player playerScore;
	

	

	//Player position;// created an object of type player 

	


public:
	screen_1(void);
	virtual int Run(sf::RenderWindow &App);
	
};

screen_1::screen_1(void)
{
	
	movement_step = 5;
	posx = 320;
	posy = 240;
	//Setting sprite
	//Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
	//Rectangle.setSize({ 10.f, 10.f });
	
		
	//sf::Texture frog;
	frog.loadFromFile("spritesheet.png");
	rectSourceSprite.left = 0;
	rectSourceSprite.top = 0;
	rectSourceSprite.width = 75;
	rectSourceSprite.height = 150;
	frogger.setTexture(frog, true);
	frogger.setTextureRect(rectSourceSprite);
	

	//(0, 0, 75, 150);
	//sf::Sprite frogger(frog, rectSourceSprite);

}

int screen_1::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	cout << " player name: " << playerName << endl;
	cout << " number of lives:  " << numLives << endl;
	cout << " if the user is hit:  " << isHit << endl;

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
			
		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				sf::Vector2f pos = frogger.getPosition();
				if (pos.x < 0)
				{
					//cout << " WTF is going on " << endl;
					isHit = true;
					if (isHit == true)
					{
						cout << " The left side got hit" << endl;
						
					}
					

					
				}

				if (pos.x < 0)
				{
					frogger.move(0, 0);
				}// end if
				
				else
				{
					if (rectSourceSprite.left != 225)
					{
						rectSourceSprite.left = 225;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(-35, 0);
					
				}// end else
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				sf::Vector2f pos = frogger.getPosition();
				if(pos.x >= 800)
				{
				//	cout << " emilyyyyy" << endl;
					isHit = true;
					if (isHit == true)
					{
						cout << " The right side got hit" << endl;
					}
				}

				if (pos.x >= 800)
				{
					frogger.move(0, 0);
				}// end if
				
				else
				{
					if (rectSourceSprite.left != 85)
					{
						rectSourceSprite.left = 85;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(35, 0);
					

				}// end else
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				sf::Vector2f pos = frogger.getPosition();
				

				if (pos.y <= -30)
				{
					frogger.move(0, 0);
					//cout << " whatup tho" << endl;
					isHit = true;
					if (isHit == true)
					{
						cout << " The up side got hit" << endl;
					}
				}// end if
				
				else
				{
					if (rectSourceSprite.left != 0)
					{
						rectSourceSprite.left = 0;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(0, -35);
				}
				
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				sf::Vector2f pos = frogger.getPosition();

				if (pos.y >= 530)
				{
					frogger.move(0, 0);
					//cout << " its hitting the bott side" << endl;
					isHit = true;
					if (isHit == true)
					{
						cout << " The down side got hit" << endl;
					}
				}// end if
				
				else
				{
					if (rectSourceSprite.left != 139)
					{
						rectSourceSprite.left = 139;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(0, 35);
					

				}// end else
			}// end if
		
		}

		/*
		//Updating
		if (posx>630)
			posx = 630;
		if (posx<0)
			posx = 0;
		if (posy>470)
			posy = 470;
		if (posy<0)
			posy = 0;
		frogger.setPosition({ posx, posy });
		*/

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing
		App.draw(frogger);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}