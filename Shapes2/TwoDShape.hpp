#ifndef TWO_D_SHAPE_HPP
#define TWO_D_SHAPE_HPP
#include <string>
#include "Shape.hpp"


class TwoDShape : public Shape
{
protected:
	float area;
	float perimeter;
public:
	TwoDShape();
	TwoDShape(std::string name, int edges);

	virtual std::string to_string();
	virtual int getDimensionality();
	virtual float getArea();
	virtual float getPerimeter();
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
};




#endif
