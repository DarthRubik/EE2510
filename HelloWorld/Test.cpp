#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"


TEST_GROUP(Test)
{
};



TEST(Test,Test)
{
	
}


int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac,av);
}
