#ifndef OPERATOR_HELPER_HPP
#define OPERATOR_HELPER_HPP
#include <type_traits>
#include <new>
#define OPERATOR_CLASS_DEFINE(Name, Operation, PEOperation) \
	template<typename Ret,typename R,typename L> \
	struct Name \
	{\
		Ret operator Operation(const L& other) const\
		{\
			R ret = *static_cast<const R*>(this);\
			return ret PEOperation other;\
		}\
	}
OPERATOR_CLASS_DEFINE(PlusHelper,+,+=);
OPERATOR_CLASS_DEFINE(MinusHelper,-,-=);
OPERATOR_CLASS_DEFINE(MultiplicationHelper,*,*=);
OPERATOR_CLASS_DEFINE(DivisionHelper,/,/=);
OPERATOR_CLASS_DEFINE(ModuloHelper,%,%=);


template<typename Ret,typename R,typename L>
struct NegationHelper
{
	Ret operator-=(const L& other) 
	{
		return *static_cast<R*>(this) += other.negate();
	}
};
template<typename T>
struct ComparableHelper
{
	bool operator!=(const T& other) const
	{
		return !(This() == other);
	}
	bool operator<=(const T& other) const
	{
		return (This() == other) || (This() < other);
	}
	bool operator>(const T& other) const
	{
		return other < This();
	}
	bool operator>=(const T& other) const
	{
		return other <= This();
	}

private:
	constexpr const T& This() const { return *static_cast<const T*>(this); }
	constexpr T& This()  { return *static_cast<T*>(this); }
};





#undef OPERATOR_CLASS_DEFINE
#endif
