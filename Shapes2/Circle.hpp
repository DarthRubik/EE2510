#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <string>
#include "TwoDShape.hpp"


class Circle : public TwoDShape
{
	float radius;
public:
	Circle();
	Circle(float radius, std::string name);
	virtual void calculateArea();
	virtual void calculatePerimeter();
	virtual std::string to_string();
	
	float getRadius();
	void setRadius(float r);
};




#endif
