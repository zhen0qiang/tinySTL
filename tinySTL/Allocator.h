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
	template<class T>
	T* allocator<T>::allocate(size_t n) {
		return static_cast<T*>(alloc::allocate(n * sizeof(T)));
	}

	template<class T>
	void allocator<T>::deallocate(T* p) {
		alloc::deallocate(static_cast<void*>(p), sizeof(T));
	}
	template<class T>
	void allocator<T>::deallocate(T* p, size_t n) {
		if (n==0) return;
		alloc::deallocate(static_cast<void*>(p), n * sizeof(T));
	}

	template<class T>
	void allocator<T>::construct(T* p) {
		new(p) T();
	}
	template<class T>
	void allocator<T>::construct(T* p, const T& value) {
		new(p) T(value);
	}

	template<class T>
	void allocator<T>::destroy(T* p) {
		p->~T();
	}
	template<class T>
	void allocator<T>::destroy(T* frist, T* last) {
		for (; frist!= last; ++frist) {
			frist->~T();
		}
	}
} // namespace tinySTL

#endif // _ALLOCATOR_H_