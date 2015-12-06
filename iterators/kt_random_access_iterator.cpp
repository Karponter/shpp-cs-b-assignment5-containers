#ifndef KT_RA_ITERATOR
#define KT_RA_ITERATOR

#include "kt_bidirectional_iterator.cpp"
#include <iostream>
#include <cstddef>

namespace KT {

template <class T>
class kt_random_access_iterator : public kt_bidirectional_iterator<T> {

protected:
	kt_random_access_iterator(T *data_pointer) : kt_bidirectional_iterator<T>(data_pointer) {}
	kt_random_access_iterator(const kt_iterator<T> & other) : kt_bidirectional_iterator<T>(other) {}
	
public:

	kt_random_access_iterator() : kt_bidirectional_iterator<T>() {}

	virtual kt_random_access_iterator<T> & operator +(int &n) {}

	friend kt_random_access_iterator<T> & operator +(int &n, kt_random_access_iterator<T> &unit) {
		return unit+n;
	}

	virtual kt_random_access_iterator<T> & operator -(int &n) {}

	friend kt_random_access_iterator<T> & operator -(int &n, kt_random_access_iterator<T> &unit) {
		return unit-n;
	}

	virtual kt_random_access_iterator<T> & operator +=(int &n) {}

	virtual kt_random_access_iterator<T> & operator -=(int &n) {}

	virtual bool operator >(kt_random_access_iterator<T> &u2) { return (int)kt_iterator<T>::_pointer > (int)u2._pointer; }

	virtual bool operator <(kt_random_access_iterator<T> &u2) { return (int)kt_iterator<T>::_pointer < (int)u2._pointer; }
	
	bool operator >=(kt_random_access_iterator<T> &u2) { return (int)kt_iterator<T>::_pointer >= (int)u2._pointer; }
	
	bool operator <=(kt_random_access_iterator<T> &u2) { return (int)kt_iterator<T>::_pointer <= (int)u2._pointer; }

	T & operator [](int offset) { return *((*this)+offset); }

	~kt_random_access_iterator() {}
	
};
}

#endif