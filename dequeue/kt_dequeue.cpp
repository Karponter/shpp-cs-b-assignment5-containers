#ifndef KTDEQUEUE
#define KTDEQUEUE

#include <iostream>
#include "deqnode.cpp"
#include "kt_dequeue_iterator.cpp"

namespace KT {

template <class T>
class kt_dequeue {
private:

	deqnode<T> *_head, *_rear;

	// initialization of empty queue with the first element data
	void init(const T &unit) {
		deqnode<T> * tmp = new deqnode<T>(unit);
		// std::cout << "initialized unit pointer: " << ((unsigned int) & (tmp->get_data())) << std::endl;
		tmp->next(_head);
		tmp->prev(_rear);
		_head->prev(tmp);
		_rear->next(tmp); 
	}

public:

	// define deq's local iterator type
	typedef kt_dequeue_iterator<T> iterator;

	// empry constructor
	kt_dequeue() {
		T data;
		_head = new deqnode<T>(data);
		_rear = new deqnode<T>(data);
	}

	// copy constructor
	kt_dequeue(const kt_dequeue<T> & other) {
		auto fr = (other.begin())++;
		auto to = other.end();
		kt_dequeue(fr, to);
	} 

	// ITERATOR range constructor
	kt_dequeue(kt_forward_iterator<T> &from, kt_forward_iterator<T> &to) {
		T data;
		_head = new deqnode<T>(data);
		_rear = new deqnode<T>(data);
		while (from != to) {
			// std::cout << "R_C_loop: " << *this << std::endl;
			T tmp = *from;
			enqueue(tmp);
			from++;
		}
	} 

	// checks if the container is empty
	bool empty() const { 
		// std::cout << "i'm rear " << (_rear->next() == NULL) << std::endl;
		return _rear->next() == NULL; 
	}

	// Adds new node to container's head
	// STACK_MODE
	void push(const T &unit) {
		// std::cout << "just smth " << std::endl << *this << std::endl;
		if (empty()) { init(unit); return; }
		auto tmp = new deqnode<T>(unit);
		_head->prev()->prev(tmp);
		tmp->prev(_head->prev());
		tmp->next(_head);
		_head->prev(tmp);
	}

	// Removes element from the head
	// STACK_MODE
	void pop() {
		_head->prev(_head->prev()->prev());
		_head->prev()->next(NULL);
	}

	// Returnes head-element
	// STACK_MODE
	T head() { return _head->prev()->get_data(); }

	// Adds new node to container's rear
	void unshift(const T &unit) {
		if (empty()) { init(unit); return; }
		auto tmp = new deqnode<T>(unit);
		_rear->next()->prev(tmp);
		tmp->next(_rear->next());
		tmp->prev(_rear);
		_rear->next(tmp);
	}

	// Removes element from the rear
	void shift() {
		_rear->next(_rear->next()->next());
		_rear->next()->prev(NULL);
	}

	// Returnes rear-element
	T rear() { return _rear->next()->get_data(); }

	// Adds element to the end of queue (rear)
	// QUEUE_MODE
	virtual void enqueue (const T &unit) { unshift(unit); }

	// Get the element from queue head and return it
	// QUEUE_MODE
	virtual T dequeue () {
		auto retVal = head();
		pop();
		return retVal;
	}

	// iterator to an end of a queue, pointing position before rear
	iterator begin() const { iterator tmp(_rear); return tmp; }

	// iterator to an end of a queue, pointing position after head
	iterator end() const { iterator tmp(_head); return tmp; }

	// overloading ostream << operator (using with cout)
	friend std::ostream & operator <<(std::ostream &os, const kt_dequeue<T> &dec) { 
		if (dec.empty()) return os;
		kt_dequeue<T>::iterator it = dec.begin();
		// std::cout << "before: ";
		// it.dump();
		++it;
		// std::cout << "after: ";
		// it.dump();
		while (it != dec.end()) {
			// std::cout << ".";
			// it.dump();
			os << *it << " ";
			++it;
		}
		return os;
	}

	// dequeue destructor
	virtual ~kt_dequeue() {if (_rear != NULL) delete _rear;}
	
};

}
#endif