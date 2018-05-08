#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <string>
#include "TwoDShape.hpp"


class Rectangle : public TwoDShape
{
	float length;
	float width;
public:
	Rectangle();
	Rectangle(float length,float width, std::string name);
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual std::string to_string();
	
	float getLength();
	void setLength(float length);
	float getWidth();
	void setWidth(float width);
};




#endif
