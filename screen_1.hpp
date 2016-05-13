



//MANIUPLATING HERE 

#pragma once
//
//  screen_1.hpp
//  Frogger
//
//  Created by Kristine Laranjo on 4/22/16.
//  Copyright © 2016 Kristine Laranjo. All rights reserved.
//

#include <iostream>
#include "object.h"
#include"object.cpp"
#include "create.h"
#include"create.cpp"
#include "cScreen.hpp"
//#include "ResourcePath.hpp"
#include <SFML/Graphics.hpp>
using namespace std;

class screen_1 : public cScreen, public Player

{
private:
	float movement_step;
	float posx;
	float posy;

	//sf::RectangleShape Rectangle;
	sf::Sprite river;
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
	bool isOnLog;
	bool isOnLog2;
	bool isOnLog3;
	bool isOnLog4;
	bool isOnLog5;

	//lilypad booleans
	bool isOnLily;
	bool isOnLily2;
	bool isOnLily3;
	bool isOnLily4;
	bool isOnLily5;

	


	

public:
	screen_1(void);
	virtual int Run(sf::RenderWindow &App);
};

screen_1::screen_1(void)
{
	texture1.loadFromFile( "spritesheet.png");
	texture2.loadFromFile("vehicles.png");

	Create t1(truck, rectSourceSprite, texture2, 0, 30, 130, 62, 1.5, 1.5, 130, 420);
	Create t2(truck2, rectSourceSprite, texture2, 148, 0, 120, 159, 1.5, 1.5, 550, 290);
	Create c1(car, rectSourceSprite, texture2, 310, 0, 146, 149, 1.7, 1.7, -230, 420);
	Create c2(car2, rectSourceSprite, texture2, 460, 0, 146, 149, 1.7, 1.7, 280, 289);
	Create c3(car3, rectSourceSprite, texture2, 460, 0, 146, 149, 1.7, 1.7, 0, 289);
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
	rectSourceSprite.top = 70;
	rectSourceSprite.width = 70;
	rectSourceSprite.height = 70;
	frogger.setTexture(texture1, true);
	frogger.setTextureRect(rectSourceSprite);
	frogger.setPosition(320, 605);

	//Create background
	bg.loadFromFile( "background.jpg");
	background.setTexture(bg, true);
	isOnLog = false;
	isOnLog2 = false;
	isOnLog3 = false;
	isOnLog4 = false;
	isOnLog5 = false;


	isOnLily = false;
	isOnLily2 = false;
	isOnLily3 = false;
	isOnLily4 = false;
	isOnLily5 = false;
}


int screen_1::Run(sf::RenderWindow &App)
{
	sf::Event Event;

	bool Running = true;
	int sum = 0;// for log testing purposes
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;
	int sum5 = 0;
	int sum6 = 0;
	int sum7 = 0;
	int sum8 = 0;
	int sum9 = 0;
	int sum10 = 0;

	



	while (Running)
	{
		
		// Creating the objects
		Object t1(130, 420,0.2 );
		Object t2(550, 290, 0.2);
		Object c1(-50, 420, 0.3);
		Object c2(280, 289, 0.2);
		Object c3(0, 289, 0.2);
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

		sf::RectangleShape rect;
		sf::RectangleShape rect2;
		sf::RectangleShape rect3;
		sf::RectangleShape rect4;
		sf::RectangleShape rect5;
		sf::RectangleShape rect6;


		sf::RectangleShape rect7;
		sf::RectangleShape rect8;
		sf::RectangleShape rect9;

		sf::RectangleShape rect10;
		sf::RectangleShape rect11;
		//Positioning of the river
		sf::RectangleShape rect12;

		//positioning the lilypads
		sf::RectangleShape rect13;
		sf::RectangleShape rect14;
		sf::RectangleShape rect15;
		sf::RectangleShape rect16;
		sf::RectangleShape rect17;






		//float bottom, left, right, up;
		// TESTING HERE FOR RECTANGLES*****************************************************************

		//sf::Vector2f position;
		sf::Vector2f size(40, 40);
		sf::Vector2f size2(120, 70);
		sf::Vector2f size3(120, 70);
		sf::Vector2f size4(95, 70);
		sf::Vector2f size5(95, 70);
		sf::Vector2f size6(95, 70);


		sf::Vector2f size7(80, 40);
		sf::Vector2f size8(80, 40);
		sf::Vector2f size9(80, 40);

		sf::Vector2f size10(120, 40);
		sf::Vector2f size11(120, 40);
		sf::Vector2f size12(800, 230);

		sf::Vector2f size13(60, 60);
		sf::Vector2f size14(60, 60);
		sf::Vector2f size15(60, 60);
		sf::Vector2f size16(60, 60);
		sf::Vector2f size17(60, 60);


		sf::Color color;
		sf::Vector2f objectPos = truck.getPosition();
		sf::Vector2f objectPos2 = truck2.getPosition();
		sf::Vector2f objectPos3 = car.getPosition();
		sf::Vector2f objectPos4 = car2.getPosition();
		sf::Vector2f objectPos5 = car3.getPosition();

		sf::Vector2f objectPos6 = shortLog.getPosition();
		sf::Vector2f objectPos7 = shortLog2.getPosition();
		sf::Vector2f objectPos8 = shortLog3.getPosition();

		sf::Vector2f objectPos9 = longLog.getPosition();
		sf::Vector2f objectPos10 = longLog2.getPosition();

		rect12.setPosition(0, 0);
		rect12.setSize(size12);
		rect12.setFillColor(sf::Color::Transparent);
		rect12.setOutlineColor(sf::Color::Red);
		rect12.setOutlineThickness(5);

		sf::Vector2f objectPos11 = lillypad.getPosition();
		sf::Vector2f objectPos12 = lillypad2.getPosition();
		sf::Vector2f objectPos13 = lillypad3.getPosition();
		sf::Vector2f objectPos14 = lillypad4.getPosition();
		sf::Vector2f objectPos15 = lillypad5.getPosition();

		rect13.setPosition(objectPos11.x + 40, objectPos11.y+40);
		rect13.setSize(size13);
		rect13.setFillColor(sf::Color::Transparent);
		rect13.setOutlineColor(sf::Color::Red);
		rect13.setOutlineThickness(5);

		rect14.setPosition(objectPos12.x + 40 , objectPos12.y+40);
		rect14.setSize(size14);
		rect14.setFillColor(sf::Color::Transparent);
		rect14.setOutlineColor(sf::Color::Red);
		rect14.setOutlineThickness(5);

		rect15.setPosition(objectPos13.x +40, objectPos13.y+40);
		rect15.setSize(size15);
		rect15.setFillColor(sf::Color::Transparent);
		rect15.setOutlineColor(sf::Color::Red);
		rect15.setOutlineThickness(5);

		rect16.setPosition(objectPos14.x +40 , objectPos14.y+40);
		rect16.setSize(size16);
		rect16.setFillColor(sf::Color::Transparent);
		rect16.setOutlineColor(sf::Color::Red);
		rect16.setOutlineThickness(5);

		rect17.setPosition(objectPos15.x +40 , objectPos15.y+40);
		rect17.setSize(size17);
		rect17.setFillColor(sf::Color::Transparent);
		rect17.setOutlineColor(sf::Color::Red);
		rect17.setOutlineThickness(5);






		sf::Vector2f pos = frogger.getPosition();

		rect.setPosition(pos.x + 30 , pos.y +10);
		rect.setSize(size);
		rect.setFillColor(sf::Color::Transparent);
		rect.setOutlineColor(sf::Color::Red);
		rect.setOutlineThickness(5);

		rect2.setPosition(objectPos.x + 30, objectPos.y + 20);
		rect2.setSize(size2);
		rect2.setFillColor(sf::Color::Transparent);
		rect2.setOutlineColor(sf::Color::Red);
		rect2.setOutlineThickness(5);

		rect3.setPosition(objectPos2.x + 30, objectPos2.y + 70);
		rect3.setSize(size3);
		rect3.setFillColor(sf::Color::Transparent);
		rect3.setOutlineColor(sf::Color::Red);
		rect3.setOutlineThickness(5);

		rect4.setPosition(objectPos3.x + 45, objectPos3.y + 80);
		rect4.setSize(size4);
		rect4.setFillColor(sf::Color::Transparent);
		rect4.setOutlineColor(sf::Color::Red);
		rect4.setOutlineThickness(5);

		rect5.setPosition(objectPos4.x + 45, objectPos4.y + 80);
		rect5.setSize(size5);
		rect5.setFillColor(sf::Color::Transparent);
		rect5.setOutlineColor(sf::Color::Red);
		rect5.setOutlineThickness(5);

		rect6.setPosition(objectPos5.x + 45, objectPos5.y + 80);
		rect6.setSize(size6);
		rect6.setFillColor(sf::Color::Transparent);
		rect6.setOutlineColor(sf::Color::Red);
		rect6.setOutlineThickness(5);

		rect7.setPosition(objectPos6.x + 45, objectPos6.y + 80);
		rect7.setSize(size7);
		rect7.setFillColor(sf::Color::Transparent);
		rect7.setOutlineColor(sf::Color::Red);
		rect7.setOutlineThickness(5);

		rect8.setPosition(objectPos7.x + 45, objectPos7.y + 80);
		rect8.setSize(size8);
		rect8.setFillColor(sf::Color::Transparent);
		rect8.setOutlineColor(sf::Color::Red);
		rect8.setOutlineThickness(5);

		rect9.setPosition(objectPos8.x + 45, objectPos8.y + 80);
		rect9.setSize(size9);
		rect9.setFillColor(sf::Color::Transparent);
		rect9.setOutlineColor(sf::Color::Red);
		rect9.setOutlineThickness(5);

		rect10.setPosition(objectPos9.x + 45, objectPos9.y + 70);
		rect10.setSize(size10);
		rect10.setFillColor(sf::Color::Transparent);
		rect10.setOutlineColor(sf::Color::Red);
		rect10.setOutlineThickness(5);

		rect11.setPosition(objectPos10.x + 45, objectPos10.y + 70);
		rect11.setSize(size11);
		rect11.setFillColor(sf::Color::Transparent);
		rect11.setOutlineColor(sf::Color::Red);
		rect11.setOutlineThickness(5);
		if (rect.getGlobalBounds().intersects(rect2.getGlobalBounds()))

		{
			//cout << " Frogger Hit Truck number one" << endl;
			numLives--;
			isHit = true;
		}

		if (rect.getGlobalBounds().intersects(rect3.getGlobalBounds()))
		{
			//cout << " Frogger Hit Truck number two" << endl;
			numLives--;
			isHit = true;
		}

		if (rect.getGlobalBounds().intersects(rect4.getGlobalBounds()))
		{
			//cout << " Frogger Hit car number one" << endl;
			numLives--;
			isHit = true;
		}

		if (rect.getGlobalBounds().intersects(rect5.getGlobalBounds()))
		{
			//cout << " Frogger Hit car number two" << endl;
			numLives--;
			isHit = true;
		}

		if (rect.getGlobalBounds().intersects(rect6.getGlobalBounds()))
		{
			//cout << " Frogger Hit car number three" << endl;
			numLives--;
			isHit = true;
		}

	

















		//Below this line Im working on the logs
		//*************************************************************************************8
		
		
		

		
		if (rect.getGlobalBounds().intersects(rect7.getGlobalBounds()))
		{
			frogger.setPosition(objectPos6.x + 45 + sum2 , objectPos6.y + 80 + sum);
			isOnLog = true;
		}
		else
		{
			isOnLog = false;
			sum = 0;
			sum2 = 0;
		}

		if (rect.getGlobalBounds().intersects(rect8.getGlobalBounds()))
		{
			
			frogger.setPosition(objectPos7.x + 45 + sum4, objectPos7.y + 80 + sum3);
			isOnLog2 = true;
		}
		else
		{
			isOnLog2 = false;
			sum3 = 0;
			sum4 = 0;
		}
		if (rect.getGlobalBounds().intersects(rect9.getGlobalBounds()))
		{
			frogger.setPosition(objectPos8.x + 45+sum6, objectPos8.y + 80+sum5);
			isOnLog3 = true;
		}
		else
		{
			isOnLog3 = false;
			sum5 = 0;
			sum6 = 0;

		}
		if (rect.getGlobalBounds().intersects(rect10.getGlobalBounds()))
		{
			frogger.setPosition(objectPos9.x + 45 + sum8, objectPos9.y + 70+ sum7);
			isOnLog4 = true;
			
		}
		else
		{
			isOnLog4 = false;
			sum7 = 0;
			sum8 = 0;
		}
		if (rect.getGlobalBounds().intersects(rect11.getGlobalBounds()))
		{
			frogger.setPosition(objectPos10.x + 45+ sum10, objectPos10.y + 70+sum9);
			isOnLog5 = true;
		}
		else
		{
			isOnLog5 = false;
			sum9 = 0;
			sum10 = 0;
		}
		if (rect.getGlobalBounds().intersects(rect13.getGlobalBounds()))
		{
			isOnLily = true;
			
		}
		if (rect.getGlobalBounds().intersects(rect14.getGlobalBounds()))
		{
			isOnLily = true;
		}
		if (rect.getGlobalBounds().intersects(rect15.getGlobalBounds()))
		{
			isOnLily = true;

		}
		if (rect.getGlobalBounds().intersects(rect16.getGlobalBounds()))
		{
			isOnLily = true;
		}
		if (rect.getGlobalBounds().intersects(rect17.getGlobalBounds()))
		{
			isOnLily = true;
		}
		sf::Vector2f location = frogger.getPosition();
		
		
		if (rect.getGlobalBounds().intersects(rect12.getGlobalBounds()))
		{
			if ((isOnLog || isOnLog2 || isOnLog3 || isOnLog4 || isOnLog5) && (location.x >= 740 || location.x < 0))
			{
				//cout <<" frogger went out of bounds " << endl;
				isHit = true;
				numLives--;

			}
		}
		

		if (rect.getGlobalBounds().intersects(rect12.getGlobalBounds()))
		{
			if (isOnLog || isOnLog2 || isOnLog3 || isOnLog4 || isOnLog5)
			{
				//cout << " this frogger is on the logs not the water" << endl;
			}
			else if (isOnLily || isOnLily2 || isOnLily3 || isOnLily4 || isOnLily5)
			{
				cout << " the frog has landed on the lilly pad" << endl;
				isHit = true;
			}
			
			else
			{
				isHit = true;
				numLives--;
			}
			
		} 

		
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

				if (isOnLog)
				{
					sum2 = (sum2 + (20 * -1));
					//isOnLog = false;
				}
				if (isOnLog2)
				{
					sum4 = (sum4 + (20 * -1));
					//isOnLog2 = false;
				}
				if (isOnLog3)
				{
					sum6 = (sum6 + (20 * -1));
					//isOnLog3 = false;
				}
				if (isOnLog4)
				{
					sum8 = (sum8 + (20 * -1));
					//isOnLog4 = false;
				}
				if (isOnLog5)
				{
					sum10 = (sum10 + (20 * -1));
					//isOnLog5 = false;
				}


				sf::Vector2f pos = frogger.getPosition();
				

				if (pos.x < 0)
				{
					frogger.move(0, 0);
					//cout << " left is working " << endl;
				}// end if
				else
				{
					if (rectSourceSprite.left != 216)
					{
						rectSourceSprite.left = 216;
						rectSourceSprite.width = 55;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(-40, 0);

				}// end else
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (isOnLog)
				{
					sum2 = (sum2 + (20));
					//isOnLog = false;
				}
				if (isOnLog2)
				{
					sum4 = (sum4 + (20));
					//isOnLog2 = false;
				}
				if (isOnLog3)
				{
					sum6 = (sum6 + (20));
					//isOnLog3 = false;
				}
				if (isOnLog4)
				{
					sum8 = (sum8 + (20));
					//isOnLog4 = false;
				}
				if (isOnLog5)
				{
					sum10 = (sum10 + (20));
					//isOnLog5 = false;
				}



				
				sf::Vector2f pos = frogger.getPosition();
				
				

				if (pos.x >= 640)
				{
					cout << " right is working" << endl;
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

					frogger.move(40, 0);

				}// end else
					//frogger.move(50, 0);
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{


			if (isOnLog)
			{
				sum = (sum + (20 * -1));
				//isOnLog = false;
			}

			if (isOnLog2)
			{
				sum3 = (sum3 + (20 * -1));
				//isOnLog2 = false;
			}
			if (isOnLog3)
			{
				sum5 = (sum5 + (20 * -1));
				//isOnLog3 = false;
			}
			if (isOnLog4)
			{
				sum7 = (sum7 + (20 * -1));
				//isOnLog4 = false;
			}
			if (isOnLog5)
			{
				sum9 = (sum9 + (20 * -1));
				//isOnLog5 = false;
			}

				
				if (pos.y <= -35)
				{
					frogger.move(0, 0);
					//cout << " top is working" << endl;
				}// end if
				
				else
				{
					if (rectSourceSprite.left != 0)
					{
						rectSourceSprite.left = 0;
						rectSourceSprite.width = 89;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(0, -40);
				}
			}// end if
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{


				if (isOnLog)
				{
					sum = (sum + 20);
					//isOnLog = false;
				}

				if (isOnLog2)
				{
					sum3 = (sum3 + 20);
					//isOnLog2 = false;
				}
				if (isOnLog3)
				{
					sum5 = (sum5 + 20);
					//isOnLog3 = false;
				}

				if (isOnLog4)
				{
					sum7 = (sum7 + 20);
					//isOnLog4 = false;
				}
				if (isOnLog5)
				{
					sum9 = (sum9 + 20);
					//isOnLog5 = false;
				}

				
				sf::Vector2f pos = frogger.getPosition();
				

				if (pos.y >= 650)
				{
					frogger.move(0, 0);
					//cout <<" bottom is working" << endl;
				}// end if
				else
				{
					if (rectSourceSprite.left != 149)
					{
						rectSourceSprite.left = 149;
						rectSourceSprite.width = 67;
						frogger.setTextureRect(rectSourceSprite);
					}// end if

					frogger.move(0, 40);

				}// end else
			}// end if
		}

		//ITS HREREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

		if (isHit == true)
		{
			cout << " Number of lives" << numLives << endl;
			isHit = false;
			rectSourceSprite.left = 0;
			rectSourceSprite.width = 89;
			frogger.setTextureRect(rectSourceSprite);
			frogger.setPosition(320, 605);
		}
		if (numLives < 0)
		{
			return 0;

		}
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
		App.draw(rect);
		//App.draw(rect2);
		//App.draw(rect3);
		//App.draw(rect4);
		//App.draw(rect5);
		//App.draw(rect6);
		//App.draw(rect7);
		//App.draw(rect8);
		//App.draw(rect9);
		//App.draw(rect10);
		//App.draw(rect11);
		//App.draw(rect12);
		App.draw(rect13);
		App.draw(rect14);
		App.draw(rect15);
		App.draw(rect16);
		App.draw(rect17);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}