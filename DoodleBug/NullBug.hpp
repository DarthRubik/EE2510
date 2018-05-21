#ifndef NULL_BUG_HPP
#define NULL_BUG_HPP

#include "Bug.hpp"


//Null Bugs represent an empty square, but are actual types because
//it helps to not have to check for null pointers everywhere
class NullBug : public Bug
{
public:
	NullBug(Square* square) : Bug(square) {}
	void Update() {}
	FoodBug* AsFoodBug() { return 0; }
	const FoodBug* AsFoodBug() const { return 0; }
	std::string GetId() const { return "NullBug"; }
	std::string ToString() const { return ""; }
};


#endif
