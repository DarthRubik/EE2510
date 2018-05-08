#include "Circle.hpp"
#include "Sphere.hpp"
#include "Rectangle.hpp"
#include "Box.hpp"
#include "iostream"
#include <vector>

std::string GetName()
{
	std::string name;
	std::cout << "Enter the name of this shape:";
	std::cin >> name;
	return name;
}

int main()
{
	std::vector<Shape*> shapes;
	//While the user is entering data, loop
	bool done = false;
	while (!done)
	{
		//Prompt the user
		std::cout << "Choose a shape to enter:\n"
			<< " 1) Circle\n"
			<< " 2) Rectangle\n"
			<< " 3) Box\n"
			<< " 4) Sphere\n"
			<< "Enter anything else to iterate through all others entered"
			<< std::endl;

		//Get their choice
		int choice;
		std::cin >> choice;

		//Create the new object and push it onto the vector
		switch (choice)
		{
			float radius;
			float length;
			float width;
			float height;
			case 1: //Circle
				std::cout << "Enter radius:";
				std::cin >> radius;
				shapes.push_back(new Circle(radius,GetName()));
				break;
			case 2: //Rectangle
				std::cout << "Enter length:";
				std::cin >> length;
				std::cout << "Enter width:";
				std::cin >> width;
				shapes.push_back(new Rectangle(length,width,GetName()));
				break;
			case 3: //Box
				std::cout << "Enter length:";
				std::cin >> length;
				std::cout << "Enter width:";
				std::cin >> width;
				std::cout << "Enter height:";
				std::cin >> height;
				shapes.push_back(new Box(length,width,height,GetName()));
				break;
			case 4: //Sphere
				std::cout << "Enter radius:";
				std::cin >> radius;
				shapes.push_back(new Sphere(radius,GetName()));
				break;
			default: //Exit
				done = true;
				break;
		}
	}

	//Loop through all the shapes, print and then delete them
	for (Shape* shape : shapes)
	{
		std::cout << shape->to_string() << std::endl;
		delete shape;
	}
}
