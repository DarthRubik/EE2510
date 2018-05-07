#ifndef ART_ROLLOVER_HPP
#define ART_ROLLOVER_HPP
#include <type_traits>
#include "OperatorHelper.hpp"

template<typename int_t>
struct FullAddition
{
	FullAddition(int_t value, bool carry = false) : value(value), carry(carry){}
	operator int_t() const { return value; }
	operator bool() const { return carry; }
private:
	int_t value;
	bool carry;
};

//For now we will have double_t has a template parameter, but
//eventually it would be nice to have it calculated automagically
template<typename int_t, typename double_t, int_t rollover>
struct ArtRollover : 
	PlusHelper<FullAddition<ArtRollover<int_t,double_t,rollover>>,ArtRollover<int_t,double_t,rollover>,ArtRollover<int_t,double_t,rollover>>,
	MinusHelper<FullAddition<ArtRollover<int_t,double_t,rollover>>,ArtRollover<int_t,double_t,rollover>,ArtRollover<int_t,double_t,rollover>>,
	NegationHelper<FullAddition<ArtRollover<int_t,double_t,rollover>>,ArtRollover<int_t,double_t,rollover>,ArtRollover<int_t,double_t,rollover>>
{
	static_assert(std::is_unsigned<int_t>::value,"");
	static_assert(std::is_unsigned<double_t>::value,"");
	constexpr ArtRollover() = default;
	template<typename T,typename = std::enable_if_t<std::is_integral<T>::value>>
	constexpr ArtRollover(const T& t) : inner(unsigned_mod(t)){}
	static constexpr ArtRollover one()
	{
		return 1;
	}
	static constexpr ArtRollover zero()
	{
		return 0;
	}
	static constexpr ArtRollover max = rollover - 1;
	template<typename T>
	ArtRollover& operator=(const T& other)
	{
		this->inner = unsigned_mod(other);
		return *this;
	}

	template<typename T,typename = std::enable_if_t<std::is_integral<T>::value>>
	constexpr operator T() const { return inner; }

	FullAddition<ArtRollover> operator+=(const ArtRollover& other)
	{
		double_t ret = this->inner += other.inner;
		this->inner %= rollover;
		return FullAddition<ArtRollover>(ret,this->inner != ret);
	}
	ArtRollover negate() const
	{
		return -inner;
	}
	bool operator==(const ArtRollover& other) const
	{
		return this->inner == other.inner;
	}
	bool operator<(const ArtRollover& other) const
	{
		return this->inner < other.inner;
	}
private:
	template<typename T>
	static constexpr int_t unsigned_mod(const T& other)
	{
		return (other%rollover+rollover)%rollover;
	}
	int_t inner;
};

#endif
