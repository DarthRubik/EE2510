#include "Circle.hpp"
#include <assert.h>
#include <string>



Circle::Circle()
{
}
Circle::Circle(float radius, std::string name) : TwoDShape(name,1)
{
	this->setRadius(radius);
}
void Circle::calculateArea()
{
	this->area = 3.14159*this->getRadius()*this->getRadius();//Pi r^2
}
void Circle::calculatePerimeter()
{
	this->perimeter = 3.14159*2*this->getRadius(); //2 Pi r
}
std::string Circle::to_string()
{
	std::string ret;
	ret += "Circle:\n";
	ret += "Radius:" + std::to_string(this->getRadius()) + "\n";
	ret += TwoDShape::to_string();
	return ret;
}
float Circle::getRadius()
{
	return this->radius;
}
void Circle::setRadius(float r)
{
	assert(r > 0);
	this->radius = r;
}
