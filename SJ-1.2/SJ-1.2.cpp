#include <iostream>

using namespace std;
double radius, square, volume;
int main()
{
	cout << "Please input radius of the ball:\n";
	cin >> radius;
	square = 4 * 3.14 * radius * radius;
	volume = 4.0 / 3.0 * 3.14 * radius * radius * radius;
	cout << square << "\t" << volume;

	return 0;
}



