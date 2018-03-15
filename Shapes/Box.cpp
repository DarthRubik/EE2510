#include "Box.hpp"



Box::Box(std::istream& stream)
{
	//Input from the stream
	//the dimensions of the box
	stream >> this->length;
	stream >> this->width;
	stream >> this->height;
}

int Box::getSurfaceArea()
{
	return 2*(this->length*this->width + 
		  this->width*this->height + 
		  this->height*this->length);
}
int Box::getVolume()
{
	return this->length*this->width*this->height;
}
