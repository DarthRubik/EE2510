#include "Square.hpp"
#include "Bug.hpp"
#include "Arena.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


void DrawArena(const Arena& arena)
{
	std::cout << " ";
	for (int x = 0; x < arena.GetWidth(); x++)
		std::cout << "_";
	std::cout << std::endl;
	int ants = 0;
	int doodleBugs = 0;
	for (int y = 0; y < arena.GetHeight(); y++)
	{
		std::cout << "|";
		for (int x = 0; x < arena.GetWidth(); x++)
		{
			std::string id = arena.GetSquare(x,y)->GetOccupant()->GetId();
			if (id == "NullBug")
			{
				std::cout << " ";
			}
			else if (id == "DoodleBug")
			{
				std::cout << "&";
				doodleBugs++;
			}
			else if (id == "Ant")
			{
				std::cout << ".";
				ants++;
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << " ";
	for (int x = 0; x < arena.GetWidth(); x++)
		std::cout << "_";
	std::cout << std::endl;
	std::cout << "Ants: " << ants << "  DoodleBugs: " << doodleBugs << std::endl;
}


int main()
{
	std::srand(std::time(0));
	Arena arena;
	DrawArena(arena);
	while (true)
	{
		int timeSteps;
		std::cout << "Enter time steps: " << std::endl;
		std::cin >> timeSteps;
		int everyNTimes = timeSteps/100;
		for (int x = 0; x < 100; x++)
		{
			std::cout << "_";
		}
		std::cout << std::endl;
		for (int x = 0; x < timeSteps; x++)
		{
			arena.Update();
			if (everyNTimes)
			{
				if (x % everyNTimes == 0)
				{
					std::cout << "=";
					std::cout << std::flush;
				}
			}
		}
		DrawArena(arena);
	}
}
