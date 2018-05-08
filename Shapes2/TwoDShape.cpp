#include "TwoDShape.hpp"
#include <assert.h>
#include <string>



TwoDShape::TwoDShape() : Shape()
{
}
TwoDShape::TwoDShape(std::string name, int edges) : Shape(name, edges)
{
}

std::string TwoDShape::to_string()
{
	std::string ret = "";
	ret += "TwoDShape:\n";
	ret += "Area:" + std::to_string(this->getArea()) + "\n";
	ret += "Perimeter:" + std::to_string(this->getPerimeter()) + "\n";
	ret += Shape::to_string();
	return ret;
}
int TwoDShape::getDimensionality()
{
	return 2; //2D Shapes have 2 dimensions
}
float TwoDShape::getArea()
{
	this->calculateArea();
	return this->area;
}
float TwoDShape::getPerimeter()
{
	this->calculatePerimeter();
	return this->perimeter;
}
