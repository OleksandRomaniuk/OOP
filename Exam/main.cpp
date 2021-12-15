#include <iostream>
#include "BoundedSet.h"
#include "UnboundedSet.h"
using namespace std;

int main() {
	/*
	{
		BoundedSet<int> a(10);
		for (unsigned i = 0; i < a.capacity(); i++)
			a.add(i);
		a.del(2);
		a.del(9);
		BoundedSet<char> b(100);
		try {
			b.del('a');
		}
		catch (const AbstrSet<char>::SetError& err) {
			err.diagnose(cerr);
		}
		cout << a << endl;
		a.add(2);
		a.add(9);
		try {
			a.add(11);
		}
		catch (const AbstrSet<int>::SetError& err) {
			err.diagnose(cerr);
		}
		try {
			a.add(1);
		}
		catch (const AbstrSet<int>::SetError& err) {
			err.diagnose(cerr);
		}
	}
	*/
	{
		UnboundedSet<char> a(10);
		for (unsigned i = 0; i < 100; i++)
			a.add('a' + i);
		cout << a << endl;
		//for (unsigned i = 0; i < 50; i++)
			//a.del('a' + i);
		cout << a << endl;
	}
	return 0;
}