#include <iostream>
#include <cmath>

using namespace std;
int main()

{
	double num1, num2, num3;
	double s, area;
	cout << "num1,num2,num3=";
	cin >> num1 >> num2 >> num3;
	s = (num1 + num2 + num3) / 2.0;
	area = sqrt(s * (s - num1) * (s - num2) * (s - num3));
	cout << "The area is=" << area << endl;
	return 0;
}




