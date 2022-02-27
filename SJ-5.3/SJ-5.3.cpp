#include<iostream>
#include "control.h"
using namespace std;
double control(double& x);

int main()
{
	cout << "Please input设定量r:" << ' ' << "被控量y:" << ' ' << "控制量step:" << endl;
	cin >> r >> y >> step;
	cout << control(y);
}