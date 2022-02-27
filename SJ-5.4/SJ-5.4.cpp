#include <iostream>
#include <stdlib.h>
#include "sroot.h"
using namespace std;
double sroot(double& val);

int main()
{
	double b=0;
	cout << "请输入要求平方根的数:" << endl;
	cin >> a;
	x1 = a / 2;
	while (a)
	{
		do 
		{
			b = x1;
			x1 = sroot(x1);
		} while (fabs(x1 - b) > 1E-5);
		break;
	}
	cout << x1;
}