#include <iostream>
#include "AbstractSet.h"

using namespace std;

int main()
{
	vector<int> v = {1, 2, 3};
	setAdapters::VectorAdapter<int> va(v);
	AbstractSet<setAdapters::VectorAdapter<int>> s(va);

	return 0;
}
