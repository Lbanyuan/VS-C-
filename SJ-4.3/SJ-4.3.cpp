#include <iostream>
using namespace std;
int main()
{
	int num[5][5] = { 0 };
	int i = 1;
	int j = 0;
	for (auto p = &num[0][0]; p < num[0] + 25; p++, i++)
	{
		if ((p - num[0]) % 5 == 0)
			cout << endl;
		*p += i;
		if ((p - num[0]) < 9)
			cout << '0' << *p << " ";
		else
			cout << *p << " ";
	}

	cout << endl;

	for (auto q = &num[0][0]; q < num[0] + 25; q++, j++)
	{
		if ((q - num[0]) % 5 == 0)
			cout << endl;
		int D = j % 5 - j / 5;
		if (D < 1)
		{
			if ((q - num[0]) < 9)
				cout << '0' << *q << " ";
			else
				cout << *q << " ";
		}
		else
			cout << "00" << " ";
	}

}
