#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "Allocator.h"
#include "Iterator.h"
#include "Utility.h"
#include "ReverseIterator.h"

namespace tinySTL {
    template<class T, class Alloc = allocator<T>>
    class deque;
    namespace Detail {
        // class dq_iter
        template<class T>
        class dq_iter : public iterator<bidirectional_iterator_tag, T> {
        private:
            template<class T, class Alloc>
            friend class ::tinySTL::deque;
        public:
            typedef const ::tinySTL::deque<T>* cntrPtr;
            size_t mapIndex_;
            T* cur_;
            cntrPtr container_;
        public:
            dq_iter() :mapIndex_(-1), cur_(0), container_(0) {}
            dq_iter(size_t index, T* ptr, cntrPtr cntr) :mapIndex_(index), cur_(ptr), container_(cntr) {}
            dq_iter(const dq_iter& it) :mapIndex_(it.mapIndex_), cur_(it.cur_), container_(it.container_) {}

            dq_iter& operator = (const dq_iter& it);
            void swap(dq_iter& it);
            reference operator *() { return *cur_; }
            const reference operator *() const { return *cur_; }
            pointer operator ->() { return &(operator*()); }
            const pointer operator ->() const { return &(operator*()); }
            dq_iter& operator ++();
            dq_iter operator ++(int);
            dq_iter& operator --();
            dq_iter& operator --(int);
            bool operator ==(const dq_iter& it) const;
            bool operator !=(const dq_iter& it) const;
        private:
            T* getBuckHead(size_t mapIndex) const;
            T* getBuckTail(size_t mapIndex) const;
            size_t getBuckSize() const;
        public:
            template<class T>
            friend dq_iter<T> operator +(const dq_iter<T>& it, typename dq_iter<T>::difference_type n);
            template<class T>
            friend dq_iter<T> operator -(const dq_iter<T>& it, typename dq_iter<T>::difference_type n);
            template<class T>
            friend dq_iter<T> operator +(typename dq_iter<T>::difference_type n, const dq_iter<T>& it);
            template<class T>
            friend dq_iter<T> operator -(typename dq_iter<T>::difference_type n, const dq_iter<T>& it);
            template<class T>
            friend typename dq_iter<T>::difference_type operator -(const dq_iter<T>& it1, const dq_iter<T>& it2);
            template<class T>
            friend void swap(dq_iter<T>& it1, dq_iter<T>& it2);
        };
    }// namespace Detail

    // class deque
    template<class T, class Alloc>
    class deque {
    private:
        template<class T>
        friend class ::tinySTL::Detail::dq_iter:
    public:
        typedef T value_type;
        typedef Detail::dq_iter<T> iterator;
        typedef Detail::dq_iter<const T> const_iterator;
        typedef T& reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef Alloc allocator_type;
    private:
        typedef Alloc dataAlloctor;
        enum class EBuckSize { BUCK_SIZE = 64 };
    private:
        iterator beg_, end_;
        size_t mapSize_;
        T **map_;
    public:
        deque();
        explicit deque(size_type n, const value_type& value = value_type());
        template<class InputIterator>
        deque(InputIterator first, InputIterator last);
        deque(const deque& other);

        ~deque();

        deque& operator = (const deque& other);
        deque& operator = (deque&& other);
    
        iterator begin();
        iterator begin() const;
        iterator end();
        iterator end() const;
    public:
        size_type size() const { return end() - begin(); }
        bool empty() const { return size() == 0; }

        reference operator[] (size_type n);
        const_reference operator[] (size_type n) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;

        void push_front(const value_type& value);
        void push_back(const value_type& value);
        void pop_front();
        void pop_back();
        void swap(deque& other);
        void clear();
    private:
        T* getnNewBuck();
        T** getNewMap(const size_t size);
        size_t getNewMapSize(const size_t size);
        size_t getBuckSize() const;
        void init();
        bool back_full() const;
        bool front_full() const;
        void deque_aux(size_t n, const value_type& value, std::true_type);
        template<class InputIterator>
        void deque_aux(InputIterator first, InputIterator last, std::false_type);
        void reallocateAndCopy();
    public:
        template<class T, class Alloc>
        friend bool operator ==(const deque<T, Alloc>& d1, const deque<T, Alloc>& d2);
        template<class T, class Alloc>
        friend bool operator !=(const deque<T, Alloc>& d1, const deque<T, Alloc>& d2);
        template<class T, class Alloc>
        friend void swap(deque<T, Alloc>& d1, deque<T, Alloc>& d2);
    };// class deque
}
// #include "Deque.cpp"
#endif // _DEQUE_H_