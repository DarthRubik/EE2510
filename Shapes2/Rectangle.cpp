#include "Rectangle.hpp"
#include <assert.h>
#include <string>



Rectangle::Rectangle() : TwoDShape()
{
	this->setWidth(0);
	this->setLength(0);
}
Rectangle::Rectangle(float length,float width, std::string name) : TwoDShape(name,4)
{
	this->setLength(length);
	this->setWidth(width);
}
void Rectangle::calculateArea()
{
	this->area = this->getWidth() * this->getLength();
}
void Rectangle::calculatePerimeter()
{
	this->perimeter = this->getWidth() * 2 + this->getLength()*2;
}
std::string Rectangle::to_string()
{
	std::string ret;
	ret += "Rectangle:\n";
	ret += "Length:" + std::to_string(this->getLength()) + "\n";
	ret += "Width:" + std::to_string(this->getWidth()) + "\n";
	ret += TwoDShape::to_string();
	return ret;
}

float Rectangle::getLength()
{
	return this->length;
}
void Rectangle::setLength(float length)
{
	this->length = length;
}
float Rectangle::getWidth()
{
	return this->width;
}
void Rectangle::setWidth(float width)
{
	this->width = width;
}
