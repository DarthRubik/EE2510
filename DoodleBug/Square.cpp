#include "Square.hpp"
#include "Arena.hpp"
#include <iostream>


Square::Square() : Square(0,0,0)
{
}
Square::Square(int x,int y, Arena* arena, std::unique_ptr<Bug> Occupant) : 
	Occupant(std::move(Occupant)),
	host(arena),x(x),y(y)
{
}

Square::Square(int x, int y, Arena* arena) : 
	Occupant(new NullBug(this)), 
	host(arena),x(x),y(y)
{
}


std::vector<Square*> Square::GetAdjacentSquares() const
{
	std::vector<Square*> adj;
	struct pos_t { int x; int y; } pos = {x,y};
	auto add_square = [&](pos_t pos, 
			      int pos_t::* add_to, 
			      int (Arena::*limit)() const,
			      int add){
		pos.*add_to += add;
		if (pos.*add_to < (this->host->*limit)() && pos.*add_to >= 0)
		{
			adj.push_back(host->GetSquare(pos.x,pos.y));
		}
	};
	add_square(pos,&pos_t::x,&Arena::GetWidth,1);
	add_square(pos,&pos_t::x,&Arena::GetWidth,-1);
	add_square(pos,&pos_t::y,&Arena::GetHeight,1);
	add_square(pos,&pos_t::y,&Arena::GetHeight,-1);

	return std::move(adj);
}
void Square::Update() const
{
	Occupant->Update();
}
void Square::MoveTo(Square* other)
{
	other->Occupant = std::move(this->Occupant);
	this->Occupant = std::unique_ptr<Bug>(new NullBug(this));

	other->Occupant->SetSquare(other);
}
Bug* Square::GetOccupant() const
{
	return this->Occupant.get();
}
int Square::GetX() const
{
	return this->x;
}
int Square::GetY() const
{
	return this->y;
}
