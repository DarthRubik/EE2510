#ifndef BOX_HPP
#define BOX_HPP
#include <string>
#include "ThreeDShape.hpp"


class Box : public ThreeDShape
{
	float length;
	float width;
	float height;
public:
	Box();
	Box(float length,float width, float height, std::string name);
	void calculateVolume();
	void calculateSurfaceArea();
	virtual std::string to_string();
	
	float getLength();
	void setLength(float r);
	float getWidth();
	void setWidth(float r);
	float getHeight();
	void setHeight(float r);
};




#endif
