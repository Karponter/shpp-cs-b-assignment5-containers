#ifndef KT_FORWARD_ITERATOR
#define KT_FORWARD_ITERATOR

#include "kt_basic_iterator.cpp"
#include <iostream>
#include <cstddef>

namespace KT {
	
template <class T>
class kt_forward_iterator : public kt_iterator<T> {

protected:
	kt_forward_iterator(T *data_pointer) : kt_iterator<T>(data_pointer) {}
	kt_forward_iterator(const kt_iterator<T> & other) : kt_iterator<T>(other) {}

public:

	kt_forward_iterator() : kt_iterator<T>() { kt_iterator<T>::_pointer = NULL; }

	virtual T * operator ->() { return kt_iterator<T>::_pointer; }

	friend bool operator ==(const kt_forward_iterator<T> & u1, const kt_forward_iterator<T> & u2) {
		return u1._pointer == u2._pointer;
	}

	friend bool operator !=(const kt_forward_iterator<T> & u1, const kt_forward_iterator<T> & u2) {
		return u1._pointer != u2._pointer;
	}

	~kt_forward_iterator() {}
	
};
}

#endif