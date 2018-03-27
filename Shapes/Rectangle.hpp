#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <iostream>


class Rectangle
{
	int length;
	int width;
public:
	//These functions do exactly what
	//you think they do
	int getArea() const;
	int getPerimeter() const;

	int getLength() const;
	int getWidth() const;

	void setLength(int value);
	void setWidth(int value);

	//This constructor will consume 
	//some chars from the input stream
	//to construct the box
	Rectangle(std::istream& stream);

	Rectangle();
	Rectangle(int l,int w);
	Rectangle(const Rectangle& other);
	virtual ~Rectangle() = default;
};

#endif
