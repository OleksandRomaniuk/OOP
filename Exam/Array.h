#ifndef _ARRAY_
#define _ARRAY_

#include <string>
#include <iostream>
using namespace std;

template<typename Elem>
class Array
{
public:
	class BadArray;
	explicit Array(size_t size);
	~Array();
	Elem& operator[] (size_t index);
	const Elem& operator[] (size_t index) const;
	size_t size() const;

private:
	size_t _size;
	Elem* _pElem;
	bool operator== (const Array&) const;
	Array(const Array&);
	Array& operator= (const Array&);
};

template<typename Elem>
class Array<Elem>::BadArray
{
private:
	string _reason;
	size_t _index;
public:
	BadArray(string reason = "", size_t index = 0)
		:_reason(reason), _index(index)
	{
		return;
	};
	~BadArray() {};
	ostream& diagnose(ostream& os) const
	{
		os << _reason << endl;
		if (_index != 0)
			os << ' ' << _index;
		os << endl;
		return;
	}
};
template<typename Elem>
ostream& operator<<(ostream& os, typename const Array<Elem>::BadArray& ba)
{
	return ba.diagnose(os);
}

template<typename Elem>
Array<Elem>::Array(size_t size) :_size(size), _pElem(new Elem[_size])
{
	if (_pElem == 0)
		throw BadArray("No more space in the system");
	return;
}
template<typename Elem>
Array<Elem>::~Array()
{
	delete[] _pElem;
}
template<typename Elem>
Elem& Array<Elem>::operator[] (size_t index)
{
	if (index >= _size)
		throw BadArray("Bad index: ", index);
	return _pElem[index];
}
template<typename Elem>
const Elem& Array<Elem>::operator[] (size_t index) const
{
	if (index >= _size)
		throw BadArray("Bad index: ", index);
	return _pElem[index];
}
template<typename Elem>
size_t Array<Elem>::size() const
{
	return _size;
}

#endif
