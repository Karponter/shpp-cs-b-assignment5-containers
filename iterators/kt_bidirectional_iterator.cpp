#ifndef KT_BIDIRECTIONAL_ITERATOR
#define KT_BIDIRECTIONAL_ITERATOR

#include "kt_forward_iterator.cpp"
#include <iostream>
#include <cstddef>

namespace KT {
	
template <class T>
class kt_bidirectional_iterator : public kt_forward_iterator<T> {

protected:
	kt_bidirectional_iterator(T *data_pointer) : kt_forward_iterator<T>(data_pointer) {}
	kt_bidirectional_iterator(const kt_iterator<T> & other) : kt_forward_iterator<T>(other) {}

public:

	kt_bidirectional_iterator() : kt_forward_iterator<T>() {}

	virtual kt_bidirectional_iterator & operator --() {}

	virtual kt_bidirectional_iterator operator --(int i) {}

	~kt_bidirectional_iterator() {}
	
};
}

#endif