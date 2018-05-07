#ifndef CHAIN_HPP
#define CHAIN_HPP
#include <tuple>
#include <type_traits>
#include "OperatorHelper.hpp"
#include "ArtRollover.hpp"

namespace detail
{
	template<long index>
	struct foreach_helper
	{
		template<typename T>
		void operator()(T lambda)
		{
			foreach_helper<index-1>()(lambda);
			lambda(std::integral_constant<long,index>());
		}
	};
	template<>
	struct foreach_helper<0>
	{
		template<typename T>
		void operator()(T lambda)
		{
			lambda(std::integral_constant<long,0>());
		}
	};
	template<typename... list>
	using foreach = foreach_helper<sizeof...(list)-1>;

	template<long index, typename tuple>
	auto& get(std::integral_constant<long,index>, tuple& t)
	{
		return std::get<index>(t);
	}
	template<typename first, typename... rest>
	constexpr auto getOne()
	{
		return std::make_tuple(first(first::one()),rest(rest::zero())...);
	}
}


//First is the least significant
template<typename... l>
struct Chain : 
	PlusHelper<FullAddition<Chain<l...>>,Chain<l...>,Chain<l...>>,
	MinusHelper<FullAddition<Chain<l...>>,Chain<l...>,Chain<l...>>,
	ComparableHelper<Chain<l...>>,
	NegationHelper<FullAddition<Chain<l...>>,Chain<l...>,Chain<l...>>

{
	static constexpr Chain zero()
	{
		return Chain(l::zero()...);
	}
	static constexpr Chain one()
	{
		return Chain(detail::getOne<l...>());
	}
	static constexpr Chain max = Chain(l::max...);
	constexpr Chain(const std::tuple<l...>& tuple) : inner(tuple){}
	constexpr Chain(l... things) : inner(std::make_tuple(things...))
	{
	}
	FullAddition<Chain> operator+=(const Chain& other)
	{
		bool carry = false;
		detail::foreach<l...>()(
			[&](auto x)
			{
				using type = std::remove_reference_t<
					decltype(detail::get(x,this->inner))
				>;

				auto lhs = detail::get(x,other.inner);
				auto with_carry = lhs + type::one();
				using carry_t = decltype(with_carry);
				carry_t add = carry ? with_carry : carry_t(lhs);
				carry = detail::get(x,this->inner) += add;
				carry |= add;
			}
		);
		return *this;
	}
	Chain negate() const
	{
		Chain ret = *this;
		detail::foreach<l...>()(
			[&](auto x)
			{
				using type = std::remove_reference_t<
					decltype(detail::get(x,this->inner))
				>;
				auto& r = detail::get(x,ret.inner); 
				const auto& o = detail::get(x,this->inner);
				r = type((type)o.negate() - type::one());
			}
		);
		return ret+one();
	}
	bool operator==(const Chain& other) const
	{
		return this->inner == other.inner;
	}
	bool operator<(const Chain& other) const
	{
		bool lt[sizeof...(l)];
		bool eq[sizeof...(l)];
		detail::foreach<l...>()(
			[&](auto x)
			{
				lt[x()] = this->Get(x) < other.Get(x);
				eq[x()] = this->Get(x) == other.Get(x);
			}
		);
		for (size_t x = sizeof...(l)-1; x != size_t(-1); x--)
		{
			if (lt[x])
			{
				return true;
			}
			else if (eq[x])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	template<typename T>
	auto& Get(T index)
	{
		return detail::get(index,this->inner);
	}
	template<typename T>
	const auto& Get(T index) const
	{
		return detail::get(index,this->inner);
	}
	template<long index>
	auto& Get()
	{
		return detail::get(std::integral_constant<long,index>(),this->inner);
	}
	template<long index>
	const auto& Get() const
	{
		return detail::get(std::integral_constant<long,index>(),this->inner);
	}
protected:
	std::tuple<l...> inner;
};


#endif
