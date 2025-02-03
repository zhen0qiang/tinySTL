#ifndef _REVERSE_ITERATOR_H_
#define _REVERSE_ITERATOR_H_

#include "Iterator.h"

namespace tinySTL {
	template<class Iterator>
	class reverse_iterator_t {
	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef const poiner const_pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef const reference const_reference;

	private:
		Iterator base_;
		Iterator cur_;

	public:
		// Constructor, copy, destructor
		reverse_iterator_t() : base_(0), cur_(0) {}

		explicit reverse_iterator_t(const iterator_type& it) : base_(it) {
			auto temp = it;
			cur_ = --temp;
		}
			
		templatte<class Iter>
			reverse_iterator_t(const reverse_iterator_t<Iter>& rev_it) {
			base_ = (iterator_type)rev_it.base_;
			auto temp = base_;
			cur_ = --temp;
		};

		// other methods
		iterator_type base() { return base_; }
		reference operator*() { return *cur_; }
		const_reference operator*() const { return *cur_; }
		pointer operator->() {
			return &(operator*());
		}
		reverse_iterator_t& operator++() {
			--base_;
			--cur_;
			return *this;
		}
		reverse_iterator_t operator++(int) {
			reverse_iterator_t temp = *this;
			++(*this);
			return temp;
		}
		reverse_iterator_t& operator--() {
			++base_;
			++cur_;
			return *this;
		}
		reverse_iterator_t operator--(int) {
			reverse_iterator_t temp = *this;
			--(*this);
			return temp;
		}

		reference operator[] (difference_type n) {
			return base()[-n - 1];
		}
		reverse_iterator_t operator + (difference_type n) const;
		reverse_iterator_t operator - (difference_type n) const;
		reverse_iterator_t& operator += (difference_type n);
		reverse_iterator_t& operator -= (difference_type n);
		
	private:
		Iterator advanceNStep(Iterator it, difference_type n, bool right, random_access_iterator_tag) {
			if (right) {
				it += n;
			}
			else {
				it -= n;
			}
			return it;
		}

		Iterator advanceNStep(Iterator it, difference_type n, bool right, bidirectional_iterator_tag) {
			difference_type i;
			difference_type absN = n>=0 ? n : -n;
			if ((right && n >= 0) || (!right && n < 0)) {
				for (i = 0; i < absN; ++i) {
					it = it + 1;
				}
			}
			else if ((right && n < 0) || (!right && n >= 0)) {
				for (i = 0; i < absN; ++i) {
					it = it - 1;
				}
			}
			return it;
		}
	public:






















#endif // !













