#include "DoodleBug.hpp"

DoodleBug::DoodleBug(Square* square) : Bug(square),MoveableBug(3,8)
{
}

const FoodBug* DoodleBug::AsFoodBug() const
{
	return 0;
}
FoodBug* DoodleBug::AsFoodBug()
{
	return 0;
}
std::string DoodleBug::GetId() const
{
	return "DoodleBug";
}
int DoodleBug::PrioritizeMove(Square* square) const
{
	if (square->GetOccupant()->GetId() == "Ant")
	{
		return 1;
	}
	if (square->GetOccupant()->GetId() == "DoodleBug")
	{
		return -1;
	}
	return 0;
}

std::unique_ptr<MoveableBug> DoodleBug::GetSpawn(Square* square) const
{
	return std::make_unique<DoodleBug>(square);
}

DoodleBug::~DoodleBug()
{
}
