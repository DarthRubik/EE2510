#include <fstream>
#include <iostream>
#include "Box.hpp"
#include "Rectangle.hpp"

void PrintRectangle(Rectangle rectangle)
{
	std::cout << "Rectangle:\n"
		<< "\tLength: " << rectangle.getLength() << '\n'
		<< "\tWidth : " << rectangle.getWidth() << '\n'
		<< "\tArea: " << rectangle.getArea() << '\n'
		<< "\tPerimeter: " << rectangle.getPerimeter() 
		<< std::endl << std::endl;
}
void PrintBox(Box box)
{
	std::cout << "Box:\n"
		<< "\tLength: " << box.getLength() << '\n'
		<< "\tWidth : " << box.getWidth() << '\n'
		<< "\tHeight : " << box.getHeight() << '\n'
		<< "\tVolume: " << box.getVolume() << '\n'
		<< "\tSurface Area: " << box.getSurfaceArea() 
		<< std::endl << std::endl;
}

int main(int arc, char** arv)
{

	if (arc != 2) return -1;
	//Open up our input file
	std::ifstream file;
	file.open(arv[1]);


	if (file.is_open())
	{
		//Get the count of objects
		int numRectangles;
		int numBoxes;
		file >> numRectangles;
		file >> numBoxes;


		//For each object in the file
		for (int x = 0; x < numRectangles + numBoxes; x++)
		{
			//Determine whether or not it is
			//a rectangle or a box
			//and then call the appropriate constructor
			char type;
			file >> type;
			if (type == 'R')
			{
				Rectangle rectangle(file);
				PrintRectangle(rectangle);
			}
			else
			{
				Box box(file);
				PrintBox(box);
			}
		}
	}
	else
	{
		std::cout << "IO Error" << std::endl;
	}
	return 0;
}
