#ifndef KT_DEQ_ITERATOR
#define KT_DEQ_ITERATOR

#include "deqnode.cpp"
#include "../iterators/kt_bidirectional_iterator.cpp"

namespace KT {

template <class T>
class kt_dequeue_iterator : public kt_bidirectional_iterator<T> {

private:
	deqnode<T> * _node_pointer;

public:

	kt_dequeue_iterator(const kt_iterator<T> & other) : kt_bidirectional_iterator<T>(other) {}

	kt_dequeue_iterator(T *data_pointer) : kt_bidirectional_iterator<T>(data_pointer) {}

	kt_dequeue_iterator(deqnode<T> * node) : kt_bidirectional_iterator<T>() {
		_node_pointer = node;
		kt_iterator<T>::_pointer = &(_node_pointer->get_data());
		// std::cout << "node constructor: " << (int)kt_iterator<T>::_pointer << std::endl;
	}

	kt_iterator<T> & operator ++() {
		_node_pointer = _node_pointer->next();
		kt_iterator<T>::_pointer = &(_node_pointer->get_data());
		return *this;
	}

	kt_bidirectional_iterator<T> & operator --() {
		_node_pointer = _node_pointer->prev();
		kt_iterator<T>::_pointer = &(_node_pointer->get_data());
		return *this;
	}
	
	kt_iterator<T> operator ++(int i) {
		_node_pointer = _node_pointer->next();
		auto tmp = *this;
		kt_iterator<T>::_pointer = &(_node_pointer->get_data());
		return tmp;
	}

	kt_bidirectional_iterator<T> operator --(int i) {
		_node_pointer = _node_pointer->prev();
		auto tmp = *this;
		kt_iterator<T>::_pointer = &(_node_pointer->get_data());
		return tmp;
	}

};
}

#endif