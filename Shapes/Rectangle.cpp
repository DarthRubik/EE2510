#include "Rectangle.hpp"
#include <iostream>
#include "assert.h"


int Rectangle::getArea() const
{
	return this->length*this->width;
}

int Rectangle::getPerimeter() const
{
	return this->length*2 + this->width*2;
}
int Rectangle::getLength() const
{
	return this->length;
}
int Rectangle::getWidth() const
{
	return this->width;
}
void Rectangle::setLength(int value) 
{
	assert(value >= 0);
	this->length = value;
}
void Rectangle::setWidth(int value)
{
	assert(value >= 0);
	this->width = value;
}

Rectangle::Rectangle(std::istream& stream)
{
	int length;
	int width;
	//Input from the stream the length and width
	stream >> length;
	stream >> width;

	this->setLength(length);
	this->setWidth(width);
}
Rectangle::Rectangle()
{
	this->setLength(0);
	this->setWidth(0);
}
Rectangle::Rectangle(int length, int width)
{
	this->setLength(length);
	this->setWidth(width);
}
Rectangle::Rectangle(const Rectangle& other) : length(other.length), width(other.width)
{
}
