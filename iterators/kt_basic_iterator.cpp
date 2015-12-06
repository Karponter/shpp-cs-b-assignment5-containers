#ifndef KT_BASIC_ITERATOR
#define KT_BASIC_ITERATOR

#include <iostream>

namespace KT {
	
template <class T>
class kt_iterator {

protected:
	T *_pointer;
	kt_iterator(){}
	kt_iterator(T *data_pointer) {
		_pointer = data_pointer;
	}

public:
	kt_iterator(const kt_iterator &other) {
		_pointer = other._pointer;
	}

	virtual T & operator *() { return *_pointer; } 

	virtual kt_iterator & operator =(const kt_iterator& other) {
		if (this != &other)
			this->_pointer = other._pointer;
		return *this;
	}

	virtual kt_iterator & operator ++() {}

	virtual kt_iterator operator ++(int i) {}

	virtual ~kt_iterator() {}

	void dump() {
		std::cout << (unsigned int)_pointer << std::endl;
	}

};

}

#endif