#include <iostream>


class Box
{
	int length;
	int width;
	int height;
public:
	Box() = default;
	virtual ~Box() = default;
	Box(std::istream& stream);
	int getSurfaceArea();
	int getVolume();
};
