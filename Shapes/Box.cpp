#include "Box.hpp"
#include "assert.h"


Box::Box()
{
	this->setLength(0);
	this->setWidth(0);
	this->setHeight(0);
}
Box::Box(std::istream& stream)
{
	int length;
	int width;
	int height;

	//Input from the stream
	//the dimensions of the box
	stream >> length;
	stream >> width;
	stream >> height;

	this->setLength(length);
	this->setWidth(width);
	this->setHeight(height);
}
Box::Box(int l,int w,int h)
{
	this->setLength(l);
	this->setWidth(w);
	this->setHeight(h);
}
Box::Box(const Box& other) : length(other.length), width(other.width), height(other.height)
{
}
int Box::getLength() const
{
	return this->length;
}
int Box::getWidth() const
{
	return this->width;
}
int Box::getHeight() const
{
	return this->height;
}
void Box::setLength(int value)
{
	assert(value >= 0);
	this->length = value;
}
void Box::setWidth(int value)
{
	assert(value >= 0);
	this->width = value;
}
void Box::setHeight(int value)
{
	assert(value >= 0);
	this->height = value;
}
int Box::getSurfaceArea() const
{
	return 2*(this->length*this->width + 
		  this->width*this->height + 
		  this->height*this->length);
}
int Box::getVolume() const
{
	return this->length*this->width*this->height;
}
