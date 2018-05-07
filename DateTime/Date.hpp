#ifndef DATE_HPP
#define DATE_HPP
#include <type_traits>
#include "OperatorHelper.hpp"
#include "ArtRollover.hpp"
#include "Chain.hpp"
#include "Time.hpp"
#include "sstream"
#include "string"

unsigned char DaysIn(unsigned int month)
{
	int days_in_month = 0;
	switch(month)
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
	return days_in_month;
}
unsigned int DaysUpTo(unsigned char month)
{
	unsigned int sum = 0;
	for (int x = 1; x < month; x++)
	{
		sum += DaysIn(x);
	}
	return sum;
}

struct PartialDate : 
	PlusHelper<FullAddition<PartialDate>,PartialDate,PartialDate>,
	MinusHelper<FullAddition<PartialDate>,PartialDate,PartialDate>,
	ComparableHelper<PartialDate>
{
	constexpr PartialDate(int months,int days) : days(days), months(months){}
	static constexpr PartialDate one()
	{
		return PartialDate(0,1);
	}
	static constexpr PartialDate zero()
	{
		return PartialDate(0,0);
	}
	FullAddition<PartialDate> operator+=(const PartialDate& other)
	{
		bool carry = false;
		this->months += other.months;
		if (this->months > 12)
		{
			this->months -= 12;
			carry = true;
		}
		this->days += other.days;
		if (this->days > DaysIn(this->months))
		{
			this->days -= DaysIn(this->months);
			this->months += 1;
		}
		if (this->months > 12)
		{
			this->months -= 12;
			carry = true;
		}
		return FullAddition<PartialDate>(*this,carry);
	}
	FullAddition<PartialDate> operator-=(const PartialDate& other)
	{
		bool carry = false;
		this->months -= other.months;
		if (this->months > 12)
		{
			this->months += 12;
			carry = true;
		}
		this->days -= other.days;

		while (this->days > DaysIn(this->months) || !this->days)
		{
			this->months -= 1;
			*this += PartialDate(0,DaysIn(this->months));
		}
		if (this->months > 12)
		{
			this->months += 12;
			carry = true;
		}
		return FullAddition<PartialDate>(*this,carry);
	}
	PartialDate negate() const
	{
		PartialDate ret = zero();

		ret -= *this;
		return ret;
	}

	bool operator==(const PartialDate& other) const
	{
		return this->days == other.days && this->months == other.months;
	}
	bool operator<(const PartialDate& other) const
	{
		if (this->months < other.months)
			return true;
		if (this->days < other.days)
			return true;
		return false;
	}

	std::string to_string() const
	{
		return std::to_string(months) + " " + std::to_string(days);
	}

private:
	unsigned char days;
	unsigned char months;
};

struct Date : Chain<PartialDate,ArtRollover<unsigned long, unsigned long , 1000000> >
{
	Date(int year,int mo,int d) : Chain(PartialDate(mo,d),year) {}

	template<typename T>
	Date(const T& other) : Chain(other) {}
	template<typename T>
	Date& operator=(const T& other)
	{
		Chain::operator=(other);
		return *this;
	}
	operator Chain()
	{
		return this->inner;
	}

	std::string to_string() const
	{
		return this->Get<0>().to_string() +  " " + std::to_string((long)this->Get<1>());
	}

};

struct DateTime : Chain<Time,Date>,
	PlusHelper<DateTime,DateTime,Date>,
	MinusHelper<DateTime,DateTime,Date>,
	PlusHelper<DateTime,DateTime,Time>,
	MinusHelper<DateTime,DateTime,Time>
{
	DateTime(Date date,Time time) : Chain(time,date) {}
	template<typename T>
	DateTime(const T& other) : Chain(other) {}
	template<typename T>
	DateTime& operator=(const T& other)
	{
		Chain::operator=(other);
		return *this;
	}
	using Chain<Time,Date>::operator+;
	using Chain<Time,Date>::operator-;
	using PlusHelper<DateTime,DateTime,Date>::operator+;
	using MinusHelper<DateTime,DateTime,Date>::operator-;
	using PlusHelper<DateTime,DateTime,Time>::operator+;
	using MinusHelper<DateTime,DateTime,Time>::operator-;
	DateTime operator+=(const Date& other)
	{
		Chain::operator+=(Chain(Time(0,0,0),other));
		return *this;
	}
	DateTime operator-=(const Date& other)
	{
		Chain::operator-=(Chain(Time(0,0,0),other));
		return *this;
	}
	DateTime operator+=(const Time& other)
	{
		Chain::operator+=(Chain(other,Date(0,0,0)));
		return *this;
	}
	DateTime operator-=(const Time& other)
	{
		Chain::operator-=(Chain(other,Date(0,0,0)));
		return *this;
	}
	std::string to_string() const
	{
		return this->Get<0>().to_string() +  " " + this->Get<1>().to_string();
	}
};


#endif
