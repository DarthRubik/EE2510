#ifndef SPHERE_HPP
#define SPHERE_HPP
#include <string>
#include "ThreeDShape.hpp"


class Sphere : public ThreeDShape
{
	float radius;
public:
	Sphere();
	Sphere(float radius, std::string name);
	void calculateVolume();
	void calculateSurfaceArea();
	virtual std::string to_string();
	
	float getRadius();
	void setRadius(float r);
};




#endif
