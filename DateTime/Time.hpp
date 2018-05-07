#ifndef TIME_HPP
#define TIME_HPP
#include "Chain.hpp"
#include "ArtRollover.hpp"
#include "cstdint"
#include <string>
#include <sstream>
#include <iomanip>


struct Time : 
	Chain<
		ArtRollover<std::uint8_t,std::uint16_t,60>,
		ArtRollover<std::uint8_t,std::uint16_t,60>,
		ArtRollover<std::uint8_t,std::uint16_t,24>
	> 
{
	Time() : Chain(0,0,0) {}

	operator Chain()
	{
		return this->inner;
	}
	Time(int hour, int min, int sec) : Chain(sec,min,hour){}
	Time(FullAddition<Chain> fa) : Chain(fa){}
	std::string to_string() const
	{
		std::ostringstream ss;


		ss << std::setfill('0') << std::setw(2) << (int)this->Get<2>() << ":"
		   <<  std::setfill('0') << std::setw(2) << (int)this->Get<1>() << ":"
		   <<  std::setfill('0') << std::setw(2) << (int)this->Get<0>();
		return ss.str();
	}

private:
};



#endif
