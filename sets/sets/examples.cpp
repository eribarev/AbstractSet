#include "examples.h"

using namespace std;

void vectorExample()
{
	cout << "\t\t==== Vector Example ====\n\n";

	AbstractSet<setAdapters::VectorAdapter<int>> s1 = {1, 2, 3, 4}, s2 = {2, 3, 4, 5};

	cout << "Sets:\n";
	s1.display();
	s2.display();

	auto sunion = s1.unionWith(s2);
	auto sintersect = s1.intersectWith(s2);
	auto scomplement = s1.complementWith(s2);
	auto sdifference = s1.differenceWith(s2);
	auto ssymmetricComplement = AbstractSet<setAdapters::VectorAdapter<int>>::symmetricComplement(s1, s2);
	auto cartesian = AbstractSet<setAdapters::VectorAdapter<int>>::cartesianProduct(s1, s2);

	cout << "Union: ";
	sunion.display();
	cout << "Intersection: ";
	sintersect.display();
	cout << "Complement: ";
	scomplement.display();
	cout << "Difference: ";
	sdifference.display();
	cout << "Symmetric Complement: ";
	ssymmetricComplement.display();

	cout << "Cartesian Product:\n";
	for (size_t i = 0; i < sqrt(cartesian.size()); i++) {
		for (size_t j = 0; j < sqrt(cartesian.size()); j++) {
			cout << '(' << cartesian[i * sqrt(cartesian.size()) + j].first << ", "
			     << cartesian[i * sqrt(cartesian.size()) + j].second << ") ";
		}
		cout << endl;
	}

	cout << endl;
}

void listExample()
{
	cout << "\t\t==== List Example ====\n\n";

	AbstractSet<setAdapters::ListAdapter<int>> s1 = {1, 2, 3, 4}, s2 = {2, 3, 4, 5};

	cout << "Sets:\n";
	s1.display();
	s2.display();

	auto sunion = s1.unionWith(s2);
	auto sintersect = s1.intersectWith(s2);
	auto scomplement = s1.complementWith(s2);
	auto sdifference = s1.differenceWith(s2);
	auto ssymmetricComplement = AbstractSet<setAdapters::ListAdapter<int>>::symmetricComplement(s1, s2);
	auto cartesian = AbstractSet<setAdapters::ListAdapter<int>>::cartesianProduct(s1, s2);

	cout << "Union: ";
	sunion.display();
	cout << "Intersection: ";
	sintersect.display();
	cout << "Complement: ";
	scomplement.display();
	cout << "Difference: ";
	sdifference.display();
	cout << "Symmetric Complement: ";
	ssymmetricComplement.display();

	cout << "Cartesian Product:\n";
	for (size_t i = 0; i < sqrt(cartesian.size()); i++) {
		for (size_t j = 0; j < sqrt(cartesian.size()); j++) {
			cout << '(' << cartesian[i * sqrt(cartesian.size()) + j].first << ", "
			     << cartesian[i * sqrt(cartesian.size()) + j].second << ") ";
		}
		cout << endl;
	}

	cout << endl;
}
