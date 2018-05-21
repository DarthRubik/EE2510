#ifndef MOVEABLE_BUG_HPP
#define MOVEABLE_BUG_HPP
#include "Bug.hpp"
#include <utility>
#include <memory>

class MoveableBug : virtual public Bug
{
	int MaxTimeToLive; //The maximum amount of time that this bug can survive (without eating)
	int TimeToLive; //The current amount of time before the bug dies (without eating)
	int TimeToSpawn; //The ammount of time before the bug spawns young
	int TimeBetweenSpawns;  //Time max time between spawns
public:
	//Takes the Time to live, and time to spawn for this bug
	MoveableBug(int ttl, int tts);

	//Should return a priority for each square given
	//A negative number represents imposibility to move
	//to the given square
	virtual int PrioritizeMove(Square* square) const = 0;

	//Returns the spawn of the bug
	virtual std::unique_ptr<MoveableBug> GetSpawn(Square* square) const = 0;
	void Update();
	std::string ToString() const;
};



#endif
