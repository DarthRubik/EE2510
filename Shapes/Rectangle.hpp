#include <iostream>


class Rectangle
{
	int length;
	int width;
public:
	//These functions do exactly what
	//you think they do
	int getArea();
	int getPerimeter();

	//This constructor will consume 
	//some chars from the input stream
	//to construct the box
	Rectangle(std::istream& stream);

	//Default constructor and destructor
	Rectangle() = default;
	virtual ~Rectangle() = default;
};
