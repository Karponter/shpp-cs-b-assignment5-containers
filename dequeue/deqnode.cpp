#ifndef KTDEQNODE
#define KTDEQNODE

#include <iostream>

namespace KT {

template <class T> 
class deqnode {
private:

	T _data;			// stored data
	deqnode *_next;		// prevoius queue unit connection
	deqnode *_prev;		// next queue unit connection

public:

	// data parametered constructor
	deqnode(T &unit) {
		_data = unit;
		_next = NULL;
		_prev = NULL;
	}

	// constant data parametered constructor
	deqnode(const T &unit) {
		_data = unit;
		_next = NULL;
		_prev = NULL;
	}

	// connection setters
	void next(deqnode<T> *next) { _next = next; }
	void prev(deqnode<T> *prev) { _prev = prev; }

	// connection getters
	deqnode<T> * next() { return _next; }
	deqnode<T> * prev() { return _prev; }

	// get stored data
	T & get_data() { return _data; }

	// overloading ostream << operator (using with cout)
	friend std::ostream &operator<< (std::ostream &os, deqnode<T> &node) { 
		return os << node.get_data() << " ";
	}

	// smart destructor
	~deqnode() {
		if (_next == NULL) {
			if (_prev != NULL) _prev->next(NULL);
		} else {
			if (_prev != NULL) {
				_prev->next(_next);
				_next->prev(_prev);
			} else {
				delete _next;
			}
		}
	}
};

}
#endif