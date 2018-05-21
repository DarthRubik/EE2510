#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "MoveableBug.hpp"
#include "Square.hpp"


class DoodleBug : public MoveableBug
{
public:
	DoodleBug(Square* square);
	const FoodBug* AsFoodBug() const;
	FoodBug* AsFoodBug();
	std::string GetId() const;
	int PrioritizeMove(Square* square) const;
	std::unique_ptr<MoveableBug> GetSpawn(Square* square) const;
	~DoodleBug();
};

#endif
