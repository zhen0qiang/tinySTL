#ifndef _UTILITY_H_
#define _UTILITY_H_

namespace tinySTL {
	//******[swap]*********//
	template<class T>
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}
	//*****[pair]*****//
	template<class T1, class T2>
	struct pair {
		public:
			typedef T1 first_type;
			typedef T2 second_type;
		public:
			T1 first;
			T2 second;
		public:
			pair() {}
			template<class U, class V>
			pair(const pair<U, V>& p);
			pair(const first_type& a, const second_type& b);
			void swap(pair& p);
		public:
			template<class T1, class T2>
			friend bool operator==(const pair<T1, T2>& p1, const pair<T1, T2>& p2);
			template<class T1, class T2>
			friend bool operator!=(const pair<T1, T2>& p1, const pair<T1, T2>& p2);
			template<class T1, class T2>
			friend bool operator<(const pair<T1, T2>& p1, const pair<T1, T2>& p2);
			template<class T1, class T2>
			friend bool operator>(const pair<T1, T2>& p1, const pair<T1, T2>& p2);
			template<class T1, class T2>
			friend bool operator<=(const pair<T1, T2>& p1, const pair<T1, T2>& p2);
			template<class T1, class T2>
			friend bool operator>=(const pair<T1, T2>& p1, const pair<T1, T2>& p2);
			template<class T1, class T2>
			friend void swap(pair<T1, T2>& p1, pair<T1, T2>& p2);
	};


#endif // !
