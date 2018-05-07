#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "iostream"
#include "ConditionalRollover.hpp"
#include "ArtRollover.hpp"
#include "cstdint"
#include "Date.hpp"

using month_t = NonZeroIdentity<ArtRollover<uint8_t,uint8_t,12>>;
using day_t = NonZeroIdentity<ArtRollover<uint8_t,uint8_t,100>>;

day_t negate(day_t day,month_t month)
{
	int days_in_month = 0;
	switch(int(month) + 1)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days_in_month = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days_in_month = 30;
			break;
		case 2:
			days_in_month = 28;
			break;
	}
	int tempDay = day_t(day - day_t::one).negate();
	tempDay = days_in_month + tempDay;
	tempDay %= 100;
	return day.negate();
}
day_t rollover(day_t day,month_t month)
{
	int days_in_month = 0;
	switch(int(month) + 1)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days_in_month = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days_in_month = 30;
			break;
		case 2:
			days_in_month = 28;
			break;
	}
	int tempDay = day;
	if (tempDay > 50) 
	{
		tempDay = day.negate();
		tempDay = days_in_month - tempDay;
		tempDay %= days_in_month;
		return day_t(tempDay+1);
	}
	tempDay %= days_in_month;
	return day_t(tempDay+1);
}

using cr = ConditionalRollover<
	day_t,month_t,day_t,rollover,negate
>;

cr monthDay(std::uint8_t month, std::uint8_t day)
{
	return cr(day_t(day),month_t(month));
}



TEST_GROUP(Date)
{
};

TEST(Date,Addition)
{

	CHECK_TRUE(PartialDate(1,1) ==  PartialDate(1,1) +  PartialDate(0,0));
	CHECK_TRUE(PartialDate(3,30) == PartialDate(3,30) + PartialDate(0,0));
	CHECK_TRUE(PartialDate(3,30) == PartialDate(0,0) +  PartialDate(3,30));
	CHECK_TRUE(PartialDate(12,1) == PartialDate(0,1) + PartialDate(11,30));
	CHECK_TRUE(PartialDate(2,1) ==  PartialDate(1,1) + PartialDate(12,31));
	CHECK_TRUE(PartialDate(1,1) ==  PartialDate(0,1) + PartialDate(12,31));
	CHECK_TRUE(PartialDate(1,12) == PartialDate(0,12) +PartialDate(12,31));
	CHECK_TRUE(PartialDate(1,1) ==   PartialDate(1,1) -   PartialDate(0,0));
	CHECK_TRUE(PartialDate(3,30) ==  PartialDate(3,30) -  PartialDate(0,0));
	CHECK_TRUE(PartialDate(11,29) == PartialDate(11,30) - PartialDate(0,1));
	CHECK_TRUE(PartialDate(9,30) ==  PartialDate(11,20) - PartialDate(1,20));
}



TEST_GROUP(ConditionalRolloverTest)
{
};

IGNORE_TEST(ConditionalRolloverTest,Addition)
{

	cr(monthDay(1,1) + monthDay(0,0)).print();
	CHECK_TRUE(monthDay(1,1) == monthDay(1,1) + monthDay(0,0));
	CHECK_TRUE(monthDay(3,30) == monthDay(3,30) + monthDay(0,0));
	CHECK_TRUE(monthDay(3,30) == monthDay(0,0) + monthDay(3,30));

	CHECK_TRUE(monthDay(12,1) == monthDay(0,1) + monthDay(11,30));
	CHECK_TRUE(monthDay(2,1) == monthDay(1,1) + monthDay(12,31));
	CHECK_TRUE(monthDay(1,1) == monthDay(0,1) + monthDay(12,31));
	CHECK_TRUE(monthDay(1,12) == monthDay(0,12) + monthDay(12,31));
}
TEST(ConditionalRolloverTest,Negation)
{
	CHECK_TRUE(monthDay(0,0) == monthDay(0,0).negate());
	//CHECK_TRUE(monthDay(12,31) == monthDay(0,1).negate());
}
IGNORE_TEST(ConditionalRolloverTest,Subtraction)
{
	std::cout << "HERE" << std::endl;
	cr(monthDay(11,20) - monthDay(1,20)).print();
	CHECK_TRUE(monthDay(1,1) == monthDay(1,1) - monthDay(0,0));
	CHECK_TRUE(monthDay(3,30) == monthDay(3,30) - monthDay(0,0));

	CHECK_TRUE(monthDay(11,29) == monthDay(11,30) - monthDay(0,1));
	CHECK_TRUE(monthDay(10,31) == monthDay(11,30) - monthDay(0,31));
	CHECK_TRUE(monthDay(9,30) == monthDay(11,20) - monthDay(1,20));
}
int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac,av);
}

