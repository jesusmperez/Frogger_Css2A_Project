#include"object.h"
#include<iostream>
#include<string>
using namespace std;



Object::Object()
{
		
	objTexture.loadFromFile("spritesheet.png");
	right = true;
	left = false;
	spriteName = "car";
	posX = 0;
    posY = 0;
	speed = 1;
	rectSprite.left = 0;
	rectSprite.top = 0;
	rectSprite.width = 75;
	rectSprite.height = 150;


	obj.setTexture(objTexture, true);
	obj.setTextureRect(rectSprite);
	

	
}

//Object(string objName, int posX, int posY, double speed, bool right, bool left);

void Object::setRight(bool right)
{
	this->right = right;
	
}
void Object::setLeft(bool left)
{
	this->left = left;
	
}
void Object::setSpriteName(string spriteName)
{
	this->spriteName = spriteName;
		
}
void Object::setPosX(int posX)
{
	this->posX = posX;
}
void Object::setPosY(int posY)
{
	this->posY = posY;
}
void Object::setSpeed(double speed)
{
	this->speed = speed;
}


