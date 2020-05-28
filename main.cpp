#include "Class.hpp"
#include <iostream>
using namespace std;


int main()
{


	Container<List<int>> cont;
	List<int> a, b, c;
	a.push_front(5);
	a.push_front(6);
	a.push_front(9);
	b.push_front(556);
	b.push_front(-45);
	b.push_front(74);
	c.push_front(111);
	c.push_front(-95);
	c.push_front(74);


	cont.Add(a);
	cont.Add(b);
	cont.Add(c);

	cout << "________________Iterator with custom Class______________________________" << endl;
	Iterator<List<int>, Container<List<int>>>* it2 = cont.CreateIterator();
	for (it2->First(); !it2->IsDone(); it2->Next()) {
		for (int i = 0; i < it2->Current()->GetSize(); i++)
			cout << it2->Current()->operator[](i) << endl;
	}

	return 0;
}

