#include<iostream>
#include<cmath>

using namespace std;
double step = 0.1,x=0.;
int val,i;
int main()
{
	do
	{
		val = 10 + 30 * (sin(x) + 1);
		for (i = 0; i < val; i++)
		{
			cout << " ";
		}
		cout << "*" << endl;
		x += step;
	} while (x <= 6.28);
	return 0;
}
