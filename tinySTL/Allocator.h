#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include "Alloc.h"
#include "Construct.h"

#include <new>
#include <cassert>

namespace tinySTL {

	template<class T>
	class allocator {
		public:
			typedef T       value_type;
			typedef T*      pointer;
			typedef const T* const_pointer;
			typedef T&      reference;
			typedef const T& const_reference;
			typedef size_t  size_type;
			typedef ptrdiff_t difference_type;

		public:
			static T* allocate();
			static T* allocate(size_t n);
			static void deallocate(T* p);
			static void deallocate(T* p, size_t n);

			static void construct(T* p);
			static void construct(T* p, const T& value);
			static void destroy(T* p);
			static void destroy(T* frist, T* last);
	};

	template<class T>
	T* allocator<T>::allocate() {
		return static_cast<T*>(alloc::allocate(sizeof(T)));
	}


#endif // _ALLOCATOR_H_
