#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "Arena.hpp"
#include "Square.hpp"
#include <algorithm>


TEST_GROUP(DoodleBug)
{
};

TEST(DoodleBug, MoveAlgorithm)
{
	Square s1(0,0,0);
	Square s2(0,0,0);
	s1.MoveTo(&s2);//This is here to make sure that we did not leak memory
}

TEST(DoodleBug, AdjInMiddle)
{
	Arena arena;
	Square* square = arena.GetSquare(4,5);
	std::vector<Square*> adj = square->GetAdjacentSquares();
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(3,5)) != adj.end());
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(5,5)) != adj.end());
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(4,6)) != adj.end());
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(4,4)) != adj.end());
	LONGS_EQUAL(4,adj.size());
}
TEST(DoodleBug, AdjOnSide)
{
	Arena arena;
	Square* square = arena.GetSquare(0,5);
	std::vector<Square*> adj = square->GetAdjacentSquares();
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(0,6)) != adj.end());
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(0,4)) != adj.end());
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(1,5)) != adj.end());
	LONGS_EQUAL(3,adj.size());
}
TEST(DoodleBug, AdjInCorner)
{
	Arena arena;
	Square* square = arena.GetSquare(19,19);
	std::vector<Square*> adj = square->GetAdjacentSquares();
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(18,19))!= adj.end());
	CHECK_TRUE(std::find(adj.begin(),adj.end(),arena.GetSquare(19,18))!= adj.end());
	LONGS_EQUAL(2,adj.size());
}


int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac,av);
}
