#include<iostream>

using namespace std;
const double pi = 3.14;
double radious, area;

int main()
{
	cout << "Please input radious:";
	cin >> radious;
	area = pi * radious * radious;
	cout << area;
}