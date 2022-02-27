#include <iostream>

using namespace std;
int main()
{
	int r(0);
	const double pi = 3.1415926;
	auto area = 0., sum = 0.;
	area = pi * r * r;
	sum += area;
	cout << "The area is\t" << area << "\n The sum area is\t" << sum << endl;
	area = pi * static_cast<double>(r * r);
	{
		decltype(area)sum(0);
		sum += area;
		cout << "The sum area is\t" << sum << endl;
	}
	cout << "The area is" << area << "\nThe sum area is\t" << sum << endl;
	cout << "The size of r\t" << sizeof(r) << "\tThe size of int\t" << sizeof(int) << endl;
	cout << "The size of area\t" << sizeof(area) << "\tThe size of double\t" << sizeof(double) << endl;
	return 0;

}

