#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>


class Box
{
	int length;
	int width;
	int height;
public:
	Box();
	Box(int length,int width, int height);
	Box(const Box& other);
	virtual ~Box() = default;


	//This constructor uses the stream
	//to find the dimensions of the box
	Box(std::istream& stream);

	int getLength() const;
	int getWidth() const;
	int getHeight() const;

	void setLength(int value);
	void setWidth(int value);
	void setHeight(int value);

	//These functions do exactly what
	//they sound like
	int getSurfaceArea() const;
	int getVolume() const;
};

#endif
