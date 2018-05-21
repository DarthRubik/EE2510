#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <memory>
#include <vector>
#include <utility>
#include "Bug.hpp"
#include "NullBug.hpp"

struct Arena;
class Square
{
	//The bug that occupies the square
	//Note that the square is in charge of
	//managing the memory of the occupant
	std::unique_ptr<Bug> Occupant;

	//The arena that this square is a part of
	Arena* host;

	//The coordinates of this square
	int x,y;
public:
	Square();
	Square(int x,int y, Arena* host);
	Square(int x,int y, Arena* host, std::unique_ptr<Bug> Occupant);

	//Gets the squares touching this square (diagonals do not count)
	std::vector<Square*> GetAdjacentSquares() const;


	//Updates the bug inside of the square
	void Update() const;

	//Moves the occupant to another square
	void MoveTo(Square* other);

	//Gets the bug inside of this square
	Bug* GetOccupant() const;

	//Get the coordinates of this square
	int GetX() const;
	int GetY() const;
};

#endif
