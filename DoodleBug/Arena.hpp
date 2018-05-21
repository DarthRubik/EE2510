#ifndef ARENA_HPP
#define ARENA_HPP
#include "Square.hpp"

#define ARENA_WIDTH 180
#define ARENA_HEIGHT 40

class Arena
{
	//The array of squares
	std::array<std::array<Square,ARENA_HEIGHT>,ARENA_WIDTH> Squares;
public:
	Arena();

	//Get squares at the locations given
	const Square* GetSquare(int x, int y) const;
	Square* GetSquare(int x, int y);

	//Update all the squares
	void Update();

	//Get the dimensions of the arena
	int GetWidth() const;
	int GetHeight() const;
};


#endif
