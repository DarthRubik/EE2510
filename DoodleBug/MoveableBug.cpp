#include "MoveableBug.hpp"
#include "FoodBug.hpp"
#include "Square.hpp"
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <assert.h>


MoveableBug::MoveableBug(int ttl, int tts) : 
	MaxTimeToLive(ttl),TimeToLive(ttl), TimeToSpawn(tts), TimeBetweenSpawns(rand()%(2*tts))
{
}

void MoveableBug::Update() 
{
	//Get a list of potential moves
	auto list = this->GetSquare()->GetAdjacentSquares();
	for (size_t x = 0; x < list.size(); x++)
	{
		if (this->PrioritizeMove(list[x]) < 0)
		{
			//Prune any moves that has a negative priority
			list.erase(list.begin()+x);
			x--;
		}
	}
	//Get the priorities of the list and find the max one
	std::vector<int> priorities;
	priorities.reserve(100);
	std::transform(list.begin(),list.end(),priorities.begin(),
		[&](Square* x) { 
			return this->PrioritizeMove(x);
		}
	);
	int max = *std::max_element(priorities.begin(),priorities.end());

	//Remove all items from our list that are not equal to the max priority
	list.erase(
		std::remove_if(list.begin(),list.end(),
			[&](auto x)
			{
				return this->PrioritizeMove(x) != max;
			}
		),
		list.end()
	);
	
	//If we have no options do nothing and count down till we die
	if (list.size() == 0)
	{
		this->TimeToLive--;
		return;
	}


	//Choose a square to move to
	size_t index = std::rand()%list.size();
	Square* oldSquare = this->GetSquare();
	Square* choosenSquare = list[index];

	//Eat the bug if it can be eaten
	FoodBug* eatenBug = choosenSquare->GetOccupant()->AsFoodBug();
	if (eatenBug)
	{
		this->TimeToLive += eatenBug->AmountOfFood() + 1;
		if (this->TimeToLive > MaxTimeToLive) this->TimeToLive = MaxTimeToLive;
	}

	//Move to the new square
	oldSquare->MoveTo(choosenSquare);
	this->TimeToSpawn--;
	if (this->TimeToSpawn < 0)
	{
		//Spawn our young if it is time
		this->TimeToSpawn = this->TimeBetweenSpawns;
		Square sq(0,0,0,std::move(this->GetSpawn(&sq)));
		sq.MoveTo(oldSquare);
	}

	//Die if it is our time
	this->TimeToLive--;
	if (this->TimeToLive < 0)
	{
		Square sq(0,0,0);
		sq.MoveTo(this->GetSquare());
	}
}

std::string MoveableBug::ToString() const
{
	return Bug::ToString() + "TTL: " + std::to_string(this->TimeToLive) + "\n";
}
