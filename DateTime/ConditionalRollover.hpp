#ifndef CONDITONAL_ROLLOVER_HPP
#define CONDITONAL_ROLLOVER_HPP
#include "ArtRollover.hpp"


template<typename Base>
struct NonZeroIdentity : 
	PlusHelper<
		FullAddition<
			NonZeroIdentity<Base>
		>,
		NonZeroIdentity<Base>,
		NonZeroIdentity<Base>
	>,
	NegationHelper<
		FullAddition<
			NonZeroIdentity<Base>
		>,
		NonZeroIdentity<Base>,
		NonZeroIdentity<Base>
	>,
	MinusHelper<
		FullAddition<
			NonZeroIdentity<Base>
		>,
		NonZeroIdentity<Base>,
		NonZeroIdentity<Base>
	>,
	ComparableHelper<
		NonZeroIdentity<Base>
	>
{

	struct DummyWrapper { 
		Base thing; 
		constexpr DummyWrapper(Base thing) : thing(thing){}
	};
	static constexpr NonZeroIdentity one()
	{
		return DummyWrapper(Base::zero());
	};
	static constexpr NonZeroIdentity zero()
	{
		return DummyWrapper(Base::max());
	};
	static constexpr NonZeroIdentity max()
	{
		return DummyWrapper(Base::one());
	};

	constexpr NonZeroIdentity(DummyWrapper b) : inner(b.thing){}
	NonZeroIdentity(Base b) : inner(b - Base::one){}
	template<typename T,typename = std::enable_if_t<std::is_integral<T>::value>>
	operator T() const
	{
		return inner;
	}
	operator bool()
	{
		return Base(inner + Base::one);
	}
	FullAddition<NonZeroIdentity> operator+=(const NonZeroIdentity& other)
	{
		Base ret = other.inner;
		bool carry = ret += Base::one;

		carry |= this->inner += ret;
		return FullAddition<NonZeroIdentity>(*this,carry);
	}
	NonZeroIdentity negate() const
	{
		return Base(this->inner + Base::one).negate();
	}
	bool operator==(const NonZeroIdentity& other) const
	{
		return this->inner == other.inner;
	}
	bool operator<(const NonZeroIdentity& other) const
	{
		return this->inner + Base::one < other.inner + Base::one;
	}


private:
	Base inner;
};

/*
template<typename Base>
const NonZeroIdentity<Base> NonZeroIdentity<Base>::one;
template<typename Base>
const NonZeroIdentity<Base> NonZeroIdentity<Base>::zero;
template<typename Base>
const NonZeroIdentity<Base> NonZeroIdentity<Base>::max;

template<typename T, typename O>
using rollover_callback = T (*)(T,O);

template<typename day_t, 
	typename month_t, 
	typename dday_t,
	rollover_callback<dday_t,month_t> callback,
	rollover_callback<dday_t,month_t> negate_cb
>
struct ConditionalRollover : 
	PlusHelper<
		FullAddition<
			ConditionalRollover<day_t,month_t,dday_t,callback,negate_cb>
		>,
		ConditionalRollover<day_t,month_t,dday_t,callback,negate_cb>,
		ConditionalRollover<day_t,month_t,dday_t,callback,negate_cb>
	>,
	MinusHelper<
		FullAddition<
			ConditionalRollover<day_t,month_t,dday_t,callback,negate_cb>
		>,
		ConditionalRollover<day_t,month_t,dday_t,callback,negate_cb>,
		ConditionalRollover<day_t,month_t,dday_t,callback,negate_cb>
	>
{
	static constexpr ConditionalRollover one = 
		ConditionalRollover(day_t::one,month_t::zero);
	static constexpr ConditionalRollover zero = 
		ConditionalRollover(day_t::zero,month_t::zero);
	static constexpr ConditionalRollover max = 
		ConditionalRollover(day_t::max,month_t::max);
	constexpr ConditionalRollover(day_t d, month_t m) : day(d), month(m){}
	FullAddition<ConditionalRollover> operator+=(const ConditionalRollover& other)
	{
		bool carry = this->month += other.month;
		this->day += other.day;
		dday_t temp = this->day;
		dday_t sub = callback(temp,this->month);
		temp = sub;
		bool carryMonth = this->day != temp;
		this->day = temp;
		if (carryMonth)
		{
			carry |= this->month += month_t::one;
		}
		return FullAddition<ConditionalRollover>(*this,carry);
	}
	FullAddition<ConditionalRollover> operator-=(const ConditionalRollover& other)
	{
		this->month -= other.month;
		for (day_t x = day_t::zero; x < other.day; x=x+day_t::one)
		{
			std::cout << (long) x << std::endl;
			*this += ConditionalRollover(day_t::max,month_t::max);
		}
		return FullAddition<ConditionalRollover>(one,0);
	}
	ConditionalRollover negate() const
	{
		if (this->month == month_t::zero && this->day == day_t::zero)
		{
			return *this;
		}
		ConditionalRollover ret = 
			ConditionalRollover(day_t::zero,month.negate());
		ret = ConditionalRollover(negate_cb(day,ret.month),ret.month);
		ret += one;
		return ret;
	}
	bool operator==(const ConditionalRollover& other)
	{
		return this->day == other.day && this->month == other.month;
	}
	day_t GetDay() const
	{
		return day;
	}
	month_t GetMonth() const
	{
		return month;
	}
	void print() const
	{
		std::cout << (long)this->GetMonth() + 1 << " " 
			<< ((long)this->GetDay() + 1) << std::endl;
	}

private:
	day_t day;
	month_t month;
};
*/


#endif
