#ifndef KT_VEC_ITERATOR
#define KT_VEC_ITERATOR

#include "../iterators/kt_random_access_iterator.cpp"

namespace KT {

template <class T>
class kt_vector_iterator : public kt_random_access_iterator<T> {

public:
	kt_vector_iterator() : kt_random_access_iterator<T>() {}

	kt_vector_iterator(const kt_iterator<T> & other) : kt_random_access_iterator<T>(other) {}

	kt_vector_iterator(T *data_pointer) : kt_random_access_iterator<T>(data_pointer) {}

	kt_iterator<T> & operator ++() {
		kt_iterator<T>::_pointer++;
		return *this;
	}
	
	kt_iterator<T> operator ++(int i) {
		auto tmp = *this;
		kt_iterator<T>::_pointer++;
		return tmp;
	}

	kt_bidirectional_iterator<T> & operator --() {
		kt_iterator<T>::_pointer--;
		return *this;
	}
	
	kt_bidirectional_iterator<T> operator --(int i) {
		auto tmp = *this;
		kt_iterator<T>::_pointer--;
		return tmp;
	}

	kt_random_access_iterator<T> operator +(int n) {
		kt_vector_iterator<T> tmp(*this);
		for (int i=0; i<n; i++)
			tmp++;
		return tmp;
	}

	kt_random_access_iterator<T> operator -(int n) {
		kt_vector_iterator<T> tmp(*this);
		for (int i=0; i<n; i++)
			tmp--;
		return tmp;
	}
};
}

#endif