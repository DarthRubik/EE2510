#include "Arena.hpp"
#include <cstdlib>
#include "DoodleBug.hpp"
#include "Ant.hpp"
#include <algorithm>
#include <iostream>



Arena::Arena()
{
	for (int x = 0; x < this->GetWidth(); x++)
	{
		for (int y = 0; y < this->GetHeight(); y++)
		{
			//Choose randomly between an ant, doodlebug, and nothing
			if (std::rand()< 5*(RAND_MAX/400))
				Squares[x][y] = 
					Square(
						x,y,this,
						std::make_unique<DoodleBug>(
							&Squares[x][y]
						)
					);
			else if (std::rand()< 100*(RAND_MAX/400))
				Squares[x][y] = 
					Square(
						x,y,this,
						std::make_unique<Ant>(
							&Squares[x][y]
						)
					);
			else
				Squares[x][y] = Square(x,y,this);
		}
	}
}

const Square* Arena::GetSquare(int x, int y) const
{
	return &Squares[x][y];
}
Square* Arena::GetSquare(int x, int y) 
{
	return &Squares[x][y];
}
int Arena::GetWidth() const
{
	return ARENA_WIDTH;
}
int Arena::GetHeight() const
{
	return ARENA_HEIGHT;
}


void Arena::Update()
{
	std::vector<Bug*> UpdatedBugs; //Keep a list of the bugs we have updated so we don't double dip
	for (int x = 0; x < this->GetWidth(); x++)
	{
		for (int y = 0; y < this->GetHeight(); y++)
		{
			Bug* bug = this->GetSquare(x,y)->GetOccupant();

			//If the bug has not been updated, update it
			if (std::find(UpdatedBugs.begin(),UpdatedBugs.end(),bug) 
					== UpdatedBugs.end())
			{
				UpdatedBugs.push_back(bug);
				bug->Update();
			}
		}
	}
}
