#include<iostream>
#include "control.h"
using namespace std;
double control(double& x);

int main()
{
	cout << "Please input�趨��r:" << ' ' << "������y:" << ' ' << "������step:" << endl;
	cin >> r >> y >> step;
	cout << control(y);
}