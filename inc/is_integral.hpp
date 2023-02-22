#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <class T, T v>
		struct integral_constant
		{
			static const T	value = v; // constexpr
			typedef T value_type;
			typedef integral_constant<T,v> type;
// constexpr operator value_type() const noexcept { return value; }
		};

	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;


	// Primary type categories.


	template<typename>
		struct __is_integral_helper
		: public false_type { };

	template<>
		struct __is_integral_helper<bool>
		: public true_type { };

	template<>
		struct __is_integral_helper<char>
		: public true_type { };

	template<>
		struct __is_integral_helper<signed char>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned char>
		: public true_type { };

	template<>
		struct __is_integral_helper<wchar_t>
		: public true_type { };

	template<>
		struct __is_integral_helper<char8_t>
		: public true_type { };

	template<>
		struct __is_integral_helper<char16_t>
		: public true_type { };

	template<>
		struct __is_integral_helper<char32_t>
		: public true_type { };

	template<>
		struct __is_integral_helper<short>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned short>
		: public true_type { };

	template<>
		struct __is_integral_helper<int>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned int>
		: public true_type { };

	template<>
		struct __is_integral_helper<long>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned long>
		: public true_type { };

	template<>
		struct __is_integral_helper<long long>
		: public true_type { };

	template<>
		struct __is_integral_helper<unsigned long long>
		: public true_type { };

	/// is_integral
	template<typename _Tp>
		struct is_integral
		: public __is_integral_helper<_Tp>::type
		{ };

}

#endif
