#pragma once
#include <ostream>
#include <string>
using namespace std;
template <typename T> 
class AbstrSet
{
private:
	virtual const T& doAdd(const T&) = 0;
	virtual bool doDel(const unsigned) = 0;
protected:
	unsigned _size = 0;
	virtual int getIndex(const T&) const;
	virtual const T& operator[](const unsigned) const = 0;
public:
	class SetError;

	const T& add(const T& elem) {
		if (in(elem))
			throw SetError("Already present");
		return doAdd(elem); 
	};
	bool del(const T& elem) {
		if (empty())
			throw SetError("Empty set");
		int i = this->getIndex(elem);
		if (i < 0) return false;
		return doDel(i); 
	};
	bool in(const T& elem) const;
	bool empty() const { return _size == 0; };
	unsigned size() const { return _size; };
	ostream& show(ostream&) const;
};

template <typename T>
ostream& operator<<(ostream& os, const AbstrSet<T>& set) {return set.show(os);}

template <typename T>
const AbstrSet<T> operator+(const AbstrSet<T>&, const AbstrSet<T>&);

template <typename T>
const AbstrSet<T> operator*(const AbstrSet<T>&, const AbstrSet<T>&);

template <typename T>
class AbstrSet<T>::SetError
{
private:
	string str;
public:
	SetError(const string& str) : str(str) {};
	~SetError() {};
	void diagnose(ostream& os) const { os << str << endl; }
};

template <typename T>
bool AbstrSet<T>::in(const T& elem) const {
	return (getIndex(elem) > 0);
}

template <typename T>
int AbstrSet<T>::getIndex(const T& elem) const {
	for (unsigned i = 0; i < _size; i++)
		if (elem == (*this)[i])
			return i;
	return -1;
}

template <typename T>
ostream& AbstrSet<T>::show(ostream& os) const {
	for (unsigned i = 0; i < _size; i++)
		os << (*this)[i] << ',';
	return (os << endl);
}