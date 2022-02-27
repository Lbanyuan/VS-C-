#include <iostream>
#include "area.h"
using namespace std;

const double PI = 3.14159;
int main()
{
	cout << "点的面积为:" << area() << '\n';
	cout << "矩形的面积为:" << area(1, 1) << '\n';
	cout << "圆的面积为:" << area(0.5) << '\n';
	cout << "梯形的面积为:" << area(1,0.5,1) << '\n';
	cout << "三角形的面积为:" << area(1,sqrt(1+0.5*0.5),sqrt(1+0.5*0.5),0)  << '\n';
	return 0;
}

double area(double radius)
{
	return PI * radius * radius;
}
double area(double length, double height)
{
	return length * length;
}
double area(double bootom, double top, double height)
{
	return(0.5 * (bootom + top) * height);
}
double area(double edge1, double edge2, double edge3, int)
{
	double s = 0.5 * (edge1 + edge2 + edge3);
	return sqrt(s * (s - edge1) * (s - edge1) * (s - edge1));
}
