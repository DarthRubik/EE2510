#ifndef THREE_D_SHAPE_HPP
#define THREE_D_SHAPE_HPP
#include <string>
#include "Shape.hpp"


class ThreeDShape : public Shape
{
protected:
	float volume;
	float surfaceArea;
public:
	ThreeDShape();
	ThreeDShape(std::string name, int edges);

	virtual std::string to_string();
	virtual int getDimensionality();
	float getVolume();
	float getSurfaceArea();
	virtual void calculateVolume() = 0;
	virtual void calculateSurfaceArea() = 0;
};




#endif
