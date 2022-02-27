#include <iostream>
using namespace std;
int main()
{
	double radius, height, volume;
	cout << "Please input radius and height:";
	cin >> radius>>height;
	volume = 3.14 * radius * radius * height;
	cout << "The volume is:" << volume << endl;
	return 0;
}
