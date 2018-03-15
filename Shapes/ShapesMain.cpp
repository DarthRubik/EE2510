#include <fstream>
#include <iostream>
#include "Box.hpp"
#include "Rectangle.hpp"


int main()
{
	//Open up our input file
	std::ifstream file;
	file.open("data.txt");


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
				std::cout << "Rectangle:\n"
					  << "Area: " << rectangle.getArea() << '\n'
					  << "Perimeter: " << rectangle.getPerimeter() 
					  << std::endl << std::endl;

			}
			else
			{
				Box box(file);
				std::cout << "Box:\n"
					  << "Volume: " << box.getVolume() << '\n'
					  << "Surface Area: " << box.getSurfaceArea() 
					  << std::endl << std::endl;
			}
		}
	}
	else
	{
		std::cout << "IO Error" << std::endl;
	}
	return 0;
}
