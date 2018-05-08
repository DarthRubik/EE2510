#include "Shape.hpp"
#include <assert.h>


Shape::Shape()
{
	this->setName("");
	this->setNumberOfEdges(0);
}

Shape::Shape(std::string name, int edges) 
{
	this->setName(name);
	this->setNumberOfEdges(edges);
}

Shape::~Shape()
{
}
std::string Shape::to_string()
{
	std::string ret = "Shape:\n";
	ret += "Name:" + this->getName() + "\n";
	ret += "Number Of Edges:" + std::to_string(this->getNumberOfEdges()) + "\n";
	ret += "Dimensionality:" + std::to_string(this->getDimensionality()) + "\n";
	return ret;
}

std::string Shape::getName()
{
	return this->name;
}
int Shape::getNumberOfEdges()
{
	return this->numberOfEdges;
}
void Shape::setName(std::string name)
{
	this->name = name;
}
void Shape::setNumberOfEdges(int edges)
{
	this->numberOfEdges = edges;
	assert(edges > 0);
}
