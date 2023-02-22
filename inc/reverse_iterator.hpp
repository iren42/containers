
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iter>
		class reverse_iterator 
		{
			private:
				template<typename _Tp>
					static _Tp*
					_S_to_pointer(_Tp* __p)
					{
						return (__p);
					}

				template<typename _Tp>
					static pointer
					_S_to_pointer(_Tp __t)
					{
						return (__t.operator->());
					}

			protected:
				Iter current;

			public:
				typedef Iter iterator_type;
				typedef typename iterator_traits<Iter>::iterator_category;
				typedef typename iterator_traits<Iter>::value_type;
				typedef typename iterator_traits<Iter>::difference_type;
				typedef typename iterator_traits<Iter>::pointer;
				typedef typename iterator_traits<Iter>::reference;

				reverse_iterator &operator=(const reverse_iterator<Iter>& rhs)
				{
					current = rhs.current;
					return (*this);
				}

				/**
				 *  @return  @c current, the %iterator used for underlying work.
				 */
				// Iterator base() const; // explicit ISO1998
				iterator_type base() const
				{
					return (current);
				}
				/**
				 *  @return  A reference to the value at @c --current
				 */
				reference operator*() const
				{
					Iter tmp = current;
					return (*--tmp);
				}

				/**
				 *  @return  A pointer to the value at @c --current
				 *
				 *  This requires that @c --current is dereferenceable.
				 */
				pointer operator->() const
				{
					Iter tmp = current;
					--tmp;
					return _S_to_pointer(tmp);

				}
				/**
				 *  @return  @c *this
				 *
				 *  Decrements the underlying iterator.
				 */
				reverse_iterator& operator++()
				{
					--current;
					return (*this);
				}
				/**
				 *  @return  The original value of @c *this
				 *
				 *  Decrements the underlying iterator.
				 */
				reverse_iterator operator++(int)
				{
					reverse_iterator tmp = *this;
					--current;
					return (tmp);
				}

				/**
				 *  @return  @c *this
				 *
				 *  Increments the underlying iterator.
				 */
				reverse_iterator& operator--()
				{
					++current;
					return (*this);
				}

				/**
				 *  @return  A reverse_iterator with the previous value of @c *this
				 *
				 *  Increments the underlying iterator.
				 */
				reverse_iterator operator--(int)
				{
					reverse_iterator tmp = *this;
					++current;
					return (tmp);
				}
				/**
				 *  @return  A reverse_iterator that refers to @c current - @a n
				 *
				 *  The underlying iterator must be a Random Access Iterator.
				 */

				reverse_iterator operator+(difference_type n) const
				{
					return reverse_iterator(current - n); 
				}

				/**
				 *  @return  *this
				 *
				 *  Moves the underlying iterator backwards @a n steps.
				 *  The underlying iterator must be a Random Access Iterator.
				 */
				reverse_iterator& operator+=(difference_type n)
				{
					current -= n;
					return (*this);
				}
				/**
				 *  @return  A reverse_iterator that refers to @c current - @a __n
				 *
				 *  The underlying iterator must be a Random Access Iterator.
				 */

				reverse_iterator operator-(difference_type __n) const
				{
					return reverse_iterator(current + __n);
				}

				/**
				 *  @return  *this
				 *
				 *  Moves the underlying iterator forwards @a __n steps.
				 *  The underlying iterator must be a Random Access Iterator.
				 */
				reverse_iterator& operator-=(difference_type __n)
				{
					current += __n;
					return *this;
				}

				/**
				 *  @return  The value at @c current - @a __n - 1
				 *
				 *  The underlying iterator must be a Random Access Iterator.
				 */

				reference operator[](difference_type __n) const
				{ return *(*this + __n); }
		};

	template <class Iterator>
		bool operator==(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{
			return (x.base() == y.base());

		}

	template <class Iterator>
		bool operator<(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{

			return (x.base() < y.base());

		}

	template <class Iterator>
		bool operator!=(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{

			return (x.base() != y.base());
		}

	template <class Iterator>
		bool operator>(
				const reverse_iterator<Iterator>& x,
				const reverse_iterator<Iterator>& y)
		{

			return (x.base() > y.base());

		}

}
#endif
