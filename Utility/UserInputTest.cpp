#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "UserInput.hpp"


TEST_GROUP(GetIntFromUser)
{
	std::istringstream stream;
	void setup()
	{
		stream = std::istringstream("");
	}
	
};
TEST(GetIntFromUser, isIntegerFailsOnEmpty)
{
	CHECK_FALSE(isInteger(""));
}
TEST(GetIntFromUser, isIntegerPreGarbage)
{
	CHECK_FALSE(isInteger("dfsaf1231"));
}
TEST(GetIntFromUser, isIntegerPostGarbage)
{
	CHECK_FALSE(isInteger("1234fassdf"));
}
TEST(GetIntFromUser, isIntegerInnerGarbage)
{
	CHECK_FALSE(isInteger("1234f1234123"));
}
TEST(GetIntFromUser, isIntegerAcceptsRealData)
{
	CHECK_TRUE(isInteger("53627"));
}

TEST(GetIntFromUser,GarbageIsRejected)
{
	stream = std::istringstream("gaskf\n123ds\n12312\n");
	LONGS_EQUAL(12312,GetIntFromUser(std::cout,stream));
}
TEST(GetIntFromUser,TestIntArray)
{
	stream = std::istringstream("10\n1\n2\n3\n4\n5\n6\n7\n8\n9\n10");
	int* array;
	int length;
	GetIntArrayFromUser(std::cout,stream,&array,&length);
	for (int x = 0; x < length; x++)
	{
		LONGS_EQUAL(x+1,array[x]);
	}
	delete[] array;
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac,av);
}

