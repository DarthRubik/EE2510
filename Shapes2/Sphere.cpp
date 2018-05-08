#include "Sphere.hpp"
#include <assert.h>
#include <string>



Sphere::Sphere()
{
}
Sphere::Sphere(float radius, std::string name) : ThreeDShape(name,1)
{
	this->setRadius(radius);
}
void Sphere::calculateVolume()
{
	this->volume = (4.0/3.0)*3.14159*
		this->getRadius()*this->getRadius()*this->getRadius();// 4/3 Pi r^3
}
void Sphere::calculateSurfaceArea()
{
	this->surfaceArea = 3.14159*4*this->getRadius()*this->getRadius(); //4 Pi r^2
}
std::string Sphere::to_string()
{
	std::string ret;
	ret += "Sphere:\n";
	ret += "Radius:" + std::to_string(this->getRadius()) + "\n";
	ret += ThreeDShape::to_string();
	return ret;
}
float Sphere::getRadius()
{
	return this->radius;
}
void Sphere::setRadius(float r)
{
	assert(r > 0);
	this->radius = r;
}
