#include <iostream>
#include "function.h"
using namespace std;

double Pn(double x,int n);
int main()	
{
	double x, n;
	cout << "Please input x n:";
	cin >> x >> n;
	cout << Pn(x, n);
}