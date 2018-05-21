#ifndef FOOD_BUG_HPP
#define FOOD_BUG_HPP
#include "Bug.hpp"

class FoodBug : virtual public Bug
{
public:
	//How much sustinance this bug gives bugs that eat it
	virtual int AmountOfFood() const = 0;
};


#endif
