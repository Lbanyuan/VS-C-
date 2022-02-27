#include <iostream>

using namespace std;
int main()
{
	{
		int i = 0, j = 0;
		const double d = 3.14159;
		i = d;
		i = 0, j = 0;
		i = j = 5;
		i = 2 + (j = 4);
		cout << i;
	}
	{
		int counter = 0, i = 1, j = 1;
		counter += 1;
		i *= j + 3;
		cout << i;
	}
	{
		int i = 1, j = 2;
		bool b = !i && ++j;
		cout << b;
	}
	{
		int i, j;
		i = (j = 3, j += 6, 5 + 6);
		cout << i;
	}
	{
		int a = 4, b = 5, c = 6, max;
		max = a > b ? a > c ? a : c : b > c ? b : c;
		cout << max;
	}
	{
		short a = 3, b = 5;
		cout << "~b" << ~b << endl;
		cout << "b<<" << (b << 1) << endl;
		cout << "b>>" << (b >> 1) << endl;
		cout << "a&b" << (a & b) << endl;
		cout << "a|b" << (a | b) << endl;
		cout << "a^b" << (a ^ b) << endl;
	}
	{
		double i = 5., j = 3.;
		int k = static_cast<int>(i / j);
		double d = i / (double)j;
		cout << d;
	}
	return 0;
}
