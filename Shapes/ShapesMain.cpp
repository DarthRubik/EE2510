#include <fstream>
#include <iostream>
#include "Box.hpp"
#include "Rectangle.hpp"


int main()
{
	std::ifstream file;
	file.open("data.txt");
	if (file.is_open())
	{
		int numRectangles;
		int numBoxes;
		file >> numRectangles;
		file >> numBoxes;


		for (int x = 0; x < numRectangles + numBoxes; x++)
		{
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
	return 0;
}
