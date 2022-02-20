#include "AbstractSet.h"

#include <iostream>

using namespace std;

int main()
{
	AbstractSet<setAdapters::VectorAdapter<int>> s1 = {1, 2, 3, 4}, s2 = {2, 3, 4, 5};

	auto sunion = s1.unionWith(s2);
	auto sintersect = s1.intersectWith(s2);
	auto scomplement = s1.complementWith(s2);
	auto sdifference = s1.differenceWith(s2);
	auto ssymmetricComplement = AbstractSet<setAdapters::VectorAdapter<int>>::symmetricComplement(s1, s2);
	auto cartesian = AbstractSet<setAdapters::VectorAdapter<int>>::cartesianProduct(s1, s2);

	sunion.display();
	sintersect.display();
	scomplement.display();
	sdifference.display();
	ssymmetricComplement.display();
	
	for (size_t i = 0; i < sqrt(cartesian.size()); i++) {
		for (size_t j = 0; j < sqrt(cartesian.size()); j++) {
			cout << '(' << cartesian[i * sqrt(cartesian.size()) + j].first << ", "
			     << cartesian[i * sqrt(cartesian.size()) + j].second << ") ";
		}
		cout<<endl;
	}

	return 0;
}
