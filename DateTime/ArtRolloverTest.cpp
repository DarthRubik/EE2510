#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "ArtRollover.hpp"
#include "cstdint"

using _100_t = ArtRollover<std::uint8_t,std::uint16_t,100>;

TEST_GROUP(ArtRollover)
{
};
void InitializationTest(int x,int expect)
{
	_100_t v0 = x;
	LONGS_EQUAL(expect,v0);
}
TEST(ArtRollover, InitializationTest)
{
	InitializationTest(123,23);
	InitializationTest(100,0);
	InitializationTest(0,0);
	InitializationTest(42,42);
	InitializationTest(-1,99);
}

void AssignmentTest(int x,int expect)
{
	_100_t v0;
	v0 = x;
	LONGS_EQUAL(expect,v0);
}
TEST(ArtRollover, AssignmentTest)
{
	AssignmentTest(123,23);
	AssignmentTest(100,0);
	AssignmentTest(0,0);
	AssignmentTest(42,42);
	AssignmentTest(-1,99);
}
void AdditionTest(int intial, int add, int expect)
{
	_100_t var = intial;
	LONGS_EQUAL(expect, _100_t(var + add));
	var += _100_t(add);
	LONGS_EQUAL(expect, var);
}
TEST(ArtRollover, AdditionTest)
{
	AdditionTest(10,23,33);
	AdditionTest(50,50,0);
	AdditionTest(50,75,25);
	AdditionTest(10,-23,87);
	AdditionTest(10,-5,5);
}
void NegationTest(int value, int expect)
{
	_100_t var = _100_t(value).negate();
	LONGS_EQUAL(expect,var);
}
TEST(ArtRollover, NegationTest)
{
	NegationTest(23,77);
	NegationTest(0,0);
	NegationTest(1,99);
	NegationTest(99,1);
	NegationTest(45,55);
}
void MinusTest(int intial, int add, int expect)
{
	_100_t var = intial;
	LONGS_EQUAL(expect, _100_t(var - _100_t(add)));
	var -= _100_t(add);
	LONGS_EQUAL(expect, var);
}
TEST(ArtRollover, MinusTest)
{
	MinusTest(10,23,87);
	MinusTest(50,50,0);
	MinusTest(50,75,75);
	MinusTest(10,-23,33);
	MinusTest(10,-5,15);
}
int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac,av);
}

