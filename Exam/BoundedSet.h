#pragma once
#include "AbstrSet.h"

template <typename T>
class BoundedSet : public AbstrSet<T>
{
private:
	virtual const T& doAdd(const T&);
	virtual bool doDel(const unsigned);
	const unsigned cap;
	T* a;
protected:
	virtual const T& operator[](const unsigned index) const { return a[index]; };
public:
	BoundedSet(const unsigned capacity);
	~BoundedSet();
	unsigned capacity() const { return cap; };
};

template <typename T>
BoundedSet<T>::BoundedSet(const unsigned capacity) : cap(capacity), a(new T[capacity]) {}

template <typename T>
BoundedSet<T>::~BoundedSet() {
	delete[] a;
}

template <typename T>
const T& BoundedSet<T>::doAdd(const T& elem) {
	if (this->size() == capacity())
		throw AbstrSet<T>::SetError("Full bounded set");
	a[this->size()] = elem;
	this->_size++;
	return elem;
}

template <typename T>
bool BoundedSet<T>::doDel(const unsigned i) {
	a[i] = a[this->size() - 1];
	this->_size--;
	return true;
}