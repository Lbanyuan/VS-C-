#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double i(1);
	double sum(0), pi, term(1.0);
	do
	{
		sum += term;
		i++;
		term *= (i - 1) / (2 * i - 1.0);
	} while (term >= 1.0e-10);
	pi = 2 * sum;
	cout << "pi=" <<fixed<<setprecision(10)<<pi<< endl;
	return 0;
}




















/*
#include <iostream>

using namespace std;
int main()
{
	double pi = 1.0, x = 1.0, sum = 0;
	long int n = 2;
	do
	{
		sum += x;
		x *= (n - 1) / (2 * n - 1.0);
		n++;
	} while (x >= 1.0e-10);
	pi = 2 * sum;
	cout << "pi=" << pi << endl;
	return 0;
}
*/
