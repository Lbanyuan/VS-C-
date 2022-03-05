
#include <iostream>
#include "MyVector.h"
#include <vector>

using namespace std;

int main()
{
	//MyVector<int>a(10,2);
	MyVector<int>ba = { 4,2,3,7,54,78,56,23,34};
	/*cout << b.size() << endl;;
	cout << ba[3] << endl;
	cout << ba.at(3)<<endl;
	cout << ba.front()<<endl;*/
	/*cout << ba[2];
	ba.push_back(3);
	cout << ba[2];
	ba.pop_back();
	ba.insert(3, 4, 5);*/
	// ba.erase(1, 3);
	/*cout << ba.at(1);
	ba.clear();
	MyVector<int> b = ba;
	cout << b[0];*/
	// ba.sort();
	ba.binary_search(54);
	return 0;
}