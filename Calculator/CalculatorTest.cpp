#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "CalculatorFunctions.h"


TEST_GROUP(Calculator)
{
	float answer;

	void TestOutOfRange(int value, int x, int y)
	{
		int result = my_basic_math(value,x,y,&answer);
		CHECK_TRUE(result == 1); //Result should be 1
	}
	void TestInRange(int value, int x, int y)
	{
		int result = my_basic_math(value,x,y,&answer);
		CHECK_FALSE(result == 1);
	}
	void TestAddition(int x,int y, float ans)
	{
		my_basic_math(1,x,y,&answer);
		DOUBLES_EQUAL(ans,answer,.01);
	}
	void TestSubtraction(int x,int y, float ans)
	{
		my_basic_math(2,x,y,&answer);
		DOUBLES_EQUAL(ans,answer,.01);
	}
	void TestMultiplication(int x,int y, float ans)
	{
		my_basic_math(3,x,y,&answer);
		DOUBLES_EQUAL(ans,answer,.01);
	}
	void TestDivision(int x,int y, float ans)
	{
		my_basic_math(4,x,y,&answer);
		DOUBLES_EQUAL(ans,answer,.01);
	}
	void TestExponentiation(int x,int y, float ans)
	{
		my_basic_math(5,x,y,&answer);
		DOUBLES_EQUAL(ans,answer,.0001);
	}
	template<typename... T>
	void RealAvgProbIsNotError(T... values)
	{
		int array[] = { values ...};
		int result = my_average(array,sizeof...(values),&answer);
		LONGS_EQUAL(0,result);
	}
	template<typename... T>
	void Average(float expect,T... values)
	{
		int array[] = { values ...};
		my_average(array,sizeof...(values),&answer);
		DOUBLES_EQUAL(expect,answer,.01);
	}
	template<typename... T>
	void MinMaxOfSomethingIsNotError(T... values)
	{
		int array[] = { values... };
		int value1;
		int value2;
		int result = my_find_large_small(array,sizeof...(values),&value1,&value2);
		LONGS_EQUAL(0,result);
	}
	template<typename... T>
	void MinMax(int max,int min,T... values)
	{
		int array[] = { values...};
		int got_max;
		int got_min;
		my_find_large_small(array,sizeof...(values),&got_max,&got_min);
		LONGS_EQUAL(max,got_max);
		LONGS_EQUAL(min,got_min);
	}
	template<typename... T>
	void Series(float expect,T... values)
	{
		int array[] = { values... };
		my_series_parallel(array,sizeof...(values),1,&answer);
		DOUBLES_EQUAL(expect,answer,.01);
	}
	template<typename... T>
	void Parallel(float expect,T... values)
	{
		int array[] = { values... };
		my_series_parallel(array,sizeof...(values),2,&answer);
		DOUBLES_EQUAL(expect,answer,.01);
	}
};


TEST(Calculator,TestOutOfRange)
{
	TestOutOfRange(123,123,123);
	TestOutOfRange(0,123,123);
	TestOutOfRange(-1,123,123);
	TestOutOfRange(6,123,123);
	TestOutOfRange(43,123,123);

}
TEST(Calculator,TestNullAns)
{
	LONGS_EQUAL(3,my_basic_math(1,1,1,0));
}
TEST(Calculator,TestInRange)
{
	TestInRange(1,123,123);
	TestInRange(2,123,123);
	TestInRange(3,123,123);
	TestInRange(4,123,123);
	TestInRange(5,123,123);

}
TEST(Calculator,TestAddition)
{
	TestAddition(1,0,1);
	TestAddition(9,-123,-114);
	TestAddition(3,2,5);
	TestAddition(2,-12,-10);
	TestAddition(-42,2,-40);
	TestAddition(3,6,9);
}
TEST(Calculator,TestSubtraction)
{	
	TestSubtraction(1,2,-1);
	TestSubtraction(9,-123,132);
	TestSubtraction(3,2,1);
	TestSubtraction(2,-12,14);
	TestSubtraction(-42,2,-44);
	TestSubtraction(3,6,-3);
}
TEST(Calculator,TestMultiplication)
{	
	TestMultiplication(1,2,2);
	TestMultiplication(9,-123,-1107);
	TestMultiplication(3,2,6);
	TestMultiplication(2,-12,-24);
	TestMultiplication(-42,2,-84);
	TestMultiplication(3,6,18);
}
TEST(Calculator,TestDivision)
{	
	TestDivision(1,2,.5);
	TestDivision(9,-123,-.073);
	TestDivision(3,2,1.5);
	TestDivision(2,-12,-.167);
	TestDivision(-42,2,-21);
	TestDivision(3,6,.5);
}
TEST(Calculator,DivideByZero)
{
	int result = my_basic_math(4,123,0,&answer);
	CHECK_TRUE(result == 2);
}
TEST(Calculator,TestExponentiation)
{	
	TestExponentiation(1,2,1);
	TestExponentiation(9,-123,0);
	TestExponentiation(3,2,9);
	TestExponentiation(2,-12,.00024414);
	TestExponentiation(-42,2,1764);
	TestExponentiation(3,6,729);
	TestExponentiation(3,0,1);
}
TEST(Calculator,AverageOfNothingIsError)
{
	int array[] = {1,2};
	int result = my_average(array,0,&answer);
	LONGS_EQUAL(1,result);
}
TEST(Calculator,AverageOfNullIsError)
{
	int result = my_average(0,120,&answer);
	LONGS_EQUAL(2,result);
}
TEST(Calculator,AverageNullAns)
{
	int array[] = {1,2};
	LONGS_EQUAL(3,my_average(array,2,0));
}
TEST(Calculator, RealAvgProbIsNotError)
{
	RealAvgProbIsNotError(1,2,3,4,5);
	RealAvgProbIsNotError(1,2);
	RealAvgProbIsNotError(4,5);
	RealAvgProbIsNotError(1,2,3);
}
TEST(Calculator, Average)
{
	Average(3,1,2,3,4,5);
	Average(1.5,1,2);
	Average(4.5,4,5);
	Average(2,1,2,3);
}
TEST(Calculator, MinMaxOfNothingIsError)
{
	int array[] = {1,2};
	int answer[2];
	LONGS_EQUAL(1,my_find_large_small(array,0,&answer[0],&answer[1]));
}
TEST(Calculator, MinMaxOfNullIsError)
{
	int answer[2];
	LONGS_EQUAL(2,my_find_large_small(0,2,&answer[0],&answer[1]));
}
TEST(Calculator, MinMaxOfSomethingIsNotError)
{
	MinMaxOfSomethingIsNotError(1,2,3,4,5);
	MinMaxOfSomethingIsNotError(1,2,34,5);
	MinMaxOfSomethingIsNotError(13,4,5,2);
	MinMaxOfSomethingIsNotError(1,23,4,5);
	MinMaxOfSomethingIsNotError(1,2,3,45);
}
TEST(Calculator, MinMaxPointersRestrict)
{
	int array[2];
	int answer;
	LONGS_EQUAL(3,my_find_large_small(array,2,&answer,&answer));
}
TEST(Calculator, MinMaxPointersNonNull)
{
	int array[2];
	int answer;
	LONGS_EQUAL(4,my_find_large_small(array,2,0,&answer));
	LONGS_EQUAL(5,my_find_large_small(array,2,&answer,0));
}
TEST(Calculator, MinMax)
{
	MinMax(5,1,1,2,3,4,5);
	MinMax(34,1,1,2,34,5);
	MinMax(213,4,213,4,52);
	MinMax(45,23,23,45);
	MinMax(45,45,45);
}
TEST(Calculator, SeriesOfNothing)
{
	int array[2];
	LONGS_EQUAL(1,my_series_parallel(array,0,1,&answer));
}
TEST(Calculator, Series)
{
	Series(10,1,2,3,4);
	Series(720,100,223,354,43);
	Series(357,123,234);
}
TEST(Calculator, Parallel)
{
	Parallel(.48,1,2,3,4);
	Parallel(24.65,100,223,354,43);
	Parallel(80.62,123,234);
}

int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac,av);
}
