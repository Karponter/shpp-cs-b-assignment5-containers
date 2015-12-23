#ifndef KTVECTOR
#define KTVECTOR
#define INITIAL_VECTOR_SIZE 8

#include <iostream>
#include "kt_vector_iterator.cpp"

namespace KT {

template <class T>
class kt_vector {
private:

	T *_data;
	int _limit;
	int _size;

	// increase vector's capacity twice and dublicate data to a new storage
	void increase() {
		_limit *= 2;
		T *newData = new T[_limit];
		for (int i=0; i<_size; i++)
			newData[i] = _data[i];
		T *tmp = _data;
		_data = newData;
		delete tmp;
	}

	// checkes if the vector's storage memory is filled
	bool capped() { return _size >= _limit; }

public:

	// define vector's local iterator type
	typedef kt_vector_iterator<T> iterator;

	// empty constructor
	kt_vector() {
		_limit = INITIAL_VECTOR_SIZE;
		_data = new T[_limit];
		_size = 0;
	}	
	
	// copy constructor
	kt_vector(kt_vector<T> & other) {
		delete[] this->_data;
		this->_limit = other._limit;
		this->_data = new T[this->_limit];
		this->_size = 0;
		for (int i=0; i<other.size(); i++) {
			this->push_back(other[i]);
		}
	} 

	// ITERATOR range constructor
	kt_vector(kt_forward_iterator<T> & from, kt_forward_iterator<T> & to) {
		_limit = INITIAL_VECTOR_SIZE;
		_data = new T[_limit];
		_size = 0;
		while (from != to) {
			push_back(*from);
			from++;
		}
	}

	// return vector's size
	int size() const { return _size; }

	// alias of size()
	int length() const { return _size; }

	// adds an element to the end of vector
	int push_back(T &unit) {
		if (capped()) increase();
		_data[_size++] = unit;
		return _size;
	}

	// adds an constant element to the end of vector
	int push_back(const T &unit) {
		if (capped()) increase();
		_data[_size++] = unit;
		return _size;
	}

	// removes last element from vector
	void pop_back() { _size--; }

	// returns the last element of vector
	T last() { return _data[_size-1]; }

	// returns the last element of vector
	T first() { return _data[0]; }

	// removes an element from the end of vector and returns it
	T take_last() { return _data[--_size]; }

	// insert new value to a specified position, slides every posterior element
	void insert(int &position, T &unit) {
		if (position > _size-1) return;
		if (position == _size-1) {
			push_back(unit);
			return;
		}
		for (int i=++_size; i>position; i--)
			_data[i] = _data[i-1];
		_data[position] = unit;
	}

	// insert new const value to a specified position, slides every posterior element
	void insert(int &position, const T &unit) {
		if (position > _size) return;
		if (position == _size) {
			push_back(unit);
			return;
		}
		for (int i=++_size; i>position; i--)
			_data[i] = _data[i-1];
		_data[position] = unit;
	}

	// returns an indexed by inreger element of vector
	// supports negative indexing (counts from the end)
	T & at(int index) { return (index<0) ? _data[_size+index] : _data[index]; }

	// overloading square brackets operator (yup, just as simple array)
	T & operator [](int index) { return _data[index]; }

	// overloading setting operator
	kt_vector<T> & operator =(kt_vector<T> &other) {
		delete[] this->_data;
		this->_limit = INITIAL_VECTOR_SIZE;
		this->_data = new T[this->_limit];
		this->_size = 0;
		for (int i=0; i<other.size(); i++) {
			this->push_back(other[i]);
		}
		return *this;
	}

	// overloading concatination operator
	kt_vector<T> & operator +=(kt_vector<T> &other) {
		for (int i=0; i<other.size(); i++)
			this->push_back(other[i]);
		return *this;
	}

	// overloading equision operator
	friend bool operator ==(kt_vector<T> &u1, kt_vector<T> &u2) {
		if (u1.size() != u2.size())	return false;
		int limit=u1.size();
		for (int i=0; i<limit; i++)
			if (u1[i]!=u2[i]) return false;
		return true;
	}

	// overloading ostream << operator (using with cout)
	friend std::ostream & operator <<(std::ostream &os, kt_vector<T> &vec) { 
		int limit = vec.size();
		for (int i=0; i<limit; i++)
			os << vec[i] << " ";
		return os;
	}

	// list vector information to std output stream
	void dump() {
		std::cout << "/.Vector dump........" << std::endl;
		std::cout << "Limit: " << _limit << std::endl;
		std::cout << "Size: " << _size << std::endl;
		std::cout << "Data pointer: " << (int)_data << std::endl;
		std::cout << "Values: " << *this << std::endl;
		std::cout << "\\..................." << std::endl;
	}

	// returns iterator to a vector's begining
	kt_vector<T>::iterator begin() {
		kt_vector<T>::iterator retVal(&(_data[0]));
		return retVal;
	}

	// returns iterator to a vector's end (position after the last element)
	kt_vector<T>::iterator end() {
		kt_vector<T>::iterator retVal(&(_data[_size-1])+1);
		return retVal;
	}

	// default destructor
	~kt_vector() { delete[] _data; }

};

};
#endif
