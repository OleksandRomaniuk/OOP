#pragma once
#include "AbstrSet.h"
#include "Sequence.h"

template <typename T>
class UnboundedSet : public AbstrSet<T>
{
private:
	virtual const T& doAdd(const T&);
	virtual bool doDel(const unsigned);
	Sequence<T>* a;
protected:
	virtual const T& operator[](const unsigned i) const {
		return (*a)[i];
	};
public:
	UnboundedSet(const unsigned);
	~UnboundedSet();
};

template <typename T>
UnboundedSet<T>::UnboundedSet(const unsigned s) : a(new Sequence<T> (s)) {}

template <typename T>
UnboundedSet<T>::~UnboundedSet() { 
	delete a;
}

template <typename T>
const T& UnboundedSet<T>::doAdd(const T& elem) {
	(*a).add(elem);
	return elem;
}

template <typename T>
bool UnboundedSet<T>::doDel(const unsigned i) {

	a->remove(i);
	return true;
}
