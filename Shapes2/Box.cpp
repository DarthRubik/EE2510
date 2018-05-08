#include "Box.hpp"
#include <assert.h>
#include <string>



Box::Box()
{
}
Box::Box(float length,float width, float height, std::string name) : ThreeDShape(name,1)
{
	this->setLength(length);
	this->setWidth(width);
	this->setHeight(height);
}
void Box::calculateVolume()
{
	this->volume = this->getLength() * this->getWidth()*this->getHeight();
}
void Box::calculateSurfaceArea()
{
	this->surfaceArea = this->getLength()*this->getWidth()*2
		+this->getLength()*this->getHeight()*2
		+this->getHeight()*this->getWidth()*2;
}
std::string Box::to_string()
{
	std::string ret;
	ret += "Box:\n";
	ret += "Length:" + std::to_string(this->getLength()) + "\n";
	ret += "Width:" + std::to_string(this->getWidth()) + "\n";
	ret += "Height:" + std::to_string(this->getHeight()) + "\n";
	ret += ThreeDShape::to_string();
	return ret;
}
float Box::getLength()
{
	return this->length;
}
void Box::setLength(float length)
{
	this->length = length;
}
float Box::getWidth()
{
	return this->width;
}
void Box::setWidth(float width)
{
	this->width = width;
}
float Box::getHeight()
{
	return this->height;
}
void Box::setHeight(float height)
{
	this->height = height;
}
