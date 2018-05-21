#ifndef ANT_HPP
#define ANT_HPP
#include "MoveableBug.hpp"
#include "Square.hpp"
#include "FoodBug.hpp"


class Ant : public MoveableBug, public FoodBug
{
public:
	Ant(Square* square);
	const FoodBug* AsFoodBug() const;
	FoodBug* AsFoodBug();
	std::string GetId() const;
	int PrioritizeMove(Square* square) const;
	int AmountOfFood() const;
	std::unique_ptr<MoveableBug> GetSpawn(Square* square) const;
	~Ant();
};

#endif
