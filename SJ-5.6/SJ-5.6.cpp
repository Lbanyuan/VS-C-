#include <iostream>
#include "max.h"
using namespace std;

int max_value(const int array[][4], int n);
int main()
{
	int a[3][4] = { {1,3,6,7},{2,4,6,8},{15,17,34,12} };
	cout << max_value(a, 3) << '\n';
	cout << "ÐÐ:" << line  << endl;
	cout << "ÁÐ:" << row << endl;
	return 0;
}