#pragma once
#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include<string>
using namespace std;
class Object {
protected:
	//sf::Sprite obj;
	//sf::Texture objTexture;
	//sf::IntRect rectSprite;
	bool right;
	bool left;
	string spriteName;
	int posX;
	int posY;
	double speed;
public:
	Object();
	//Object(string objName, int posX, int posY, double speed, bool right, bool left);

	void setRight(bool right);
	void setLeft(bool left);
	void setSpriteName(string spriteName);
	void setPosX(int posX);
	void setPosY(int posY);
	void setSpeed(double speed);
	

	bool getRight()const { return right; }
	bool getLeft()const { return left; }
	string getSpriteName() const{ return spriteName; }
	int getPosX()const { return posX; }
	int getPosY()const { return posY; }
	double getSpeed()const { return speed; }



};
#endif