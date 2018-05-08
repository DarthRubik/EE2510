#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>


class Shape
{
	std::string name;
	int numberOfEdges;
public:
	Shape();
	Shape(std::string name, int edges);
	virtual ~Shape();
	virtual std::string to_string();
	virtual int getDimensionality() = 0;


	std::string getName();
	int getNumberOfEdges();
	void setName(std::string name);
	void setNumberOfEdges(int edges);
};




#endif
