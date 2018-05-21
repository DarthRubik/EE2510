#include "Ant.hpp"
#include <iostream>


Ant::Ant(Square* square) : Bug(square),MoveableBug(10000,3)
{
}

int Ant::PrioritizeMove(Square* square) const
{
	if (square->GetOccupant()->GetId() == "NullBug")
	{
		return 1;
	}
	return -1;
}

std::string Ant::GetId() const
{
	return "Ant";
}
FoodBug* Ant::AsFoodBug()
{
	return this;
}
const FoodBug* Ant::AsFoodBug() const
{
	return this;
}
int Ant::AmountOfFood() const
{
	return std::rand() % 2;
}
std::unique_ptr<MoveableBug> Ant::GetSpawn(Square* sqare) const
{
	return std::make_unique<Ant>(sqare);
}
Ant::~Ant()
{
}
