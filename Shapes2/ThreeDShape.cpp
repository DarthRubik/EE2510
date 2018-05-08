#include "ThreeDShape.hpp"
#include <assert.h>
#include <string>



ThreeDShape::ThreeDShape() : Shape()
{
}
ThreeDShape::ThreeDShape(std::string name, int edges) : Shape(name, edges)
{
}

std::string ThreeDShape::to_string()
{
	std::string ret = "";
	ret += "ThreeDShape:\n";
	ret += "Volume:" + std::to_string(this->getVolume()) + "\n";
	ret += "Surface Area:" + std::to_string(this->getSurfaceArea()) + "\n";
	ret += Shape::to_string();
	return ret;
}
int ThreeDShape::getDimensionality()
{
	return 3; //3D Shapes have 3 dimensions
}
float ThreeDShape::getVolume()
{
	this->calculateVolume();
	return this->volume;
}
float ThreeDShape::getSurfaceArea()
{
	this->calculateSurfaceArea();
	return this->surfaceArea;
}
