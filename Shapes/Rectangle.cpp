#include "Rectangle.hpp"
#include <iostream>


int Rectangle::getArea()
{
	return this->length*this->width;
}

int Rectangle::getPerimeter()
{
	return this->length*2 + this->width*2;
}

Rectangle::Rectangle(std::istream& stream)
{
	//Input from the stream the length and width
	stream >> this->length;
	stream >> this->width;
}
