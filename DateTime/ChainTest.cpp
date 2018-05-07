#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "Chain.hpp"
#include "ArtRollover.hpp"
#include "cstdint"
#include "type_traits"
#include <iostream>

template<class T>
inline constexpr T pow(const T base, unsigned int const exponent)
{
    return (exponent == 0) ? 1 : (base * pow(base, exponent-1));
}

template<char... str>
struct convert
{
};
template<char first,char... str>
struct convert<first,str...>
{
	auto operator()()
	{
		//auto rest = convert<str...>()();
		return std::integral_constant<long,
		       (first-'0')*pow(10,sizeof...(str))
		>();
	}
};
template<>
struct convert<>
{
	auto operator()()
	{
		return std::integral_constant<long,
		       0
		>();
	}
};
template<char... str>
auto operator""_c()
{
	return convert<str...>()();
}

using chain_t = Chain<
	ArtRollover<uint8_t,uint16_t,10>,
	ArtRollover<uint8_t,uint16_t,20>,
	ArtRollover<uint8_t,uint16_t,30>
>;
TEST_GROUP(ChainTest)
{
};
TEST(ChainTest,AddTest)
{
	CHECK_TRUE(chain_t(5,7,9)   == chain_t(1,2,3)+chain_t(4,5,6)     );
	CHECK_TRUE(chain_t(5,7,4)   == chain_t(1,2,24)+chain_t(4,5,10)   );
	CHECK_TRUE(chain_t(3,8,4)   == chain_t(9,2,24)+chain_t(4,5,10)   );
	CHECK_TRUE(chain_t(8,19,1)  == chain_t(9,19,0)+chain_t(9,19,0)   );
	CHECK_TRUE(chain_t(0,0,0)   == chain_t(0,0,0)+chain_t(0,0,0)     );
	CHECK_TRUE(chain_t(8,19,29) == chain_t(9,19,29)+chain_t(9,19,29) );
}
TEST(ChainTest,Negation)
{
	CHECK_TRUE(chain_t(1,0,0).negate() == chain_t(9,19,29));
	CHECK_TRUE(chain_t(0,0,0).negate() == chain_t(0,0,0));
}
TEST(ChainTest, LessThan)
{
	CHECK_TRUE(chain_t(1,0,0) < chain_t(9,19,29));
	CHECK_TRUE(chain_t(1,0,0) < chain_t(2,0,0));
	CHECK_TRUE(chain_t(1,2,9) < chain_t(2,2,9));

	CHECK_FALSE(chain_t(1,0,0) < chain_t(1,0,0));
	CHECK_FALSE(chain_t(1,2,0) < chain_t(2,0,0));
	CHECK_FALSE(chain_t(3,2,9) < chain_t(2,2,9));
}
int main(int ac, char** av)
{
	return CommandLineTestRunner::RunAllTests(ac,av);
}

