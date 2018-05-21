#include "Bug.hpp"
#include <assert.h>
#include "Square.hpp"


Bug::Bug() : currentSquare(0) {}
Bug::Bug(Square* square)
{
	this->SetSquare(square);
}
Square* Bug::GetSquare() const
{
	return currentSquare;
}

void Bug::SetSquare(Square* square)
{
	this->currentSquare = square;
	assert(square != 0);
}
std::string Bug::ToString() const
{
	std::string str = "";
	str += "Type: " + this->GetId() + "\n";
	str += "Location: " +  std::to_string(this->GetSquare()->GetX()) 
		+ "," + std::to_string(this->GetSquare()->GetY()) + "\n";
	return str;
}
Bug::~Bug(){}
