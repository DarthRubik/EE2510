#include <iostream>


class Box
{
	int length;
	int width;
	int height;
public:
	//Default constructors and destructors
	Box() = default;
	virtual ~Box() = default;

	//This constructor uses the stream
	//to find the dimensions of the box
	Box(std::istream& stream);

	//These functions do exactly what
	//they sound like
	int getSurfaceArea();
	int getVolume();
};
