#ifndef BUG_HPP
#define BUG_HPP
#include <string>


class Square;
class FoodBug;


//Class that represents bugs
class Bug
{
	//The square that the bug is on
	Square* currentSquare;
public:
	//The square object passed in is the starting square for the bug
	Bug(Square* square);
	Bug();

	//Called once per turn
	virtual void Update() = 0;

	//Returns the current bug as a food bug, other wise null
	virtual FoodBug* AsFoodBug() = 0;
	virtual const FoodBug* AsFoodBug() const = 0;

	//Gets the ID of the bug ("Ant", "DoodleBug", etc)
	virtual std::string GetId() const = 0;

	//Gets a string representation of the bug
	virtual std::string ToString() const;

	//Gets the current square
	Square* GetSquare() const;

	//Sets the current square
	void SetSquare(Square* square);
	virtual ~Bug();
};

#endif
