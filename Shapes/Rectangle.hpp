#include <iostream>


class Rectangle
{
	int length;
	int width;
public:
	int getArea();
	int getPerimeter();
	Rectangle(std::istream& stream);
	Rectangle() = default;
	virtual ~Rectangle() = default;
};
