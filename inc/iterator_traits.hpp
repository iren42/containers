#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{

	/**
	 *  @brief  Traits class for iterators.
	 *
	 *  This class does nothing but define nested typedefs.  The general
	 *  version simply @a forwards the nested typedefs from the Iterator
	 *  argument.  Specialized versions for pointers and pointers-to-const
	 *  provide tighter, more correct semantics.
	 */

	template <class Iter>
		struct iterator_traits
		{
			typedef typename Iter::iterator_category iterator_category;
			typedef typename Iter::value_type        value_type;
			typedef typename Iter::difference_type   difference_type;
			typedef typename Iter::pointer           pointer;
			typedef typename Iter::reference         reference;
		}

	/// Partial specialization for pointer types.
	template <class T>
		struct iterator_traits<T*>
		{
			typedef random_access_iterator_tag iterator_category;
			typedef T                         value_type;
			typedef ptrdiff_t                   difference_type;
			typedef T*                        pointer;
			typedef T&                        reference;
		};

	/// Partial specialization for const pointer types.
	template <class T>
		struct iterator_traits<const T*>
		{
			typedef random_access_iterator_tag iterator_category;
			typedef T                         value_type;
			typedef ptrdiff_t                   difference_type;
			typedef const T*                  pointer;
			typedef const T&                  reference;
		};
}
#endif
