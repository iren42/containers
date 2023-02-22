#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <class T1, class T2>
		struct pair {
			typedef T1 first_type;
			typedef T2 second_type;
			T1 first;
			T2 second;

			pair();
			pair(const T1& x, const T2& y);
			template<class U, class V>
				pair(const pair<U, V> &p);

			pair& operator=( const pair& other )
			{
				first = other.first;
				second = other.second;
				return (*this);
			}
		}


	template <class T1, class T2>
		bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{
			return (  x.first == y.first && x.second == y.second );
		}

	template <class T1, class T2>
		bool operator< (const pair<T1,T2>&, const pair<T1,T2>&)
		{
			return (  x.first < y.first && x.second < y.second );
		}

	template <class T1, class T2>
		bool operator!=(const pair<T1,T2>&, const pair<T1,T2>&)
		{
			return (  x.first != y.first && x.second != y.second );
		}

	template <class T1, class T2>
		bool operator> (const pair<T1,T2>&, const pair<T1,T2>&)
		{
			return (  x.first > y.first && x.second > y.second );
		}

	template <class T1, class T2>
		bool operator>=(const pair<T1,T2>&, const pair<T1,T2>&)
		{
			return (  x.first >= y.first && x.second >= y.second );
		}

	template <class T1, class T2>
		bool operator<=(const pair<T1,T2>&, const pair<T1,T2>&)
		{
			return (  x.first <= y.first && x.second <= y.second );

		}

	template< class T1, class T2 >
		pair<T1, T2> make_pair(const T1& x, const T2& y )
		{
			return (pair<T1, T2>(x, y));
		}
}

#endif
