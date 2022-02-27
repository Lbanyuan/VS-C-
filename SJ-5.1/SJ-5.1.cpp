#include <iostream>
#include<cmath>
#include "fun.h"
using namespace std;
void funa(int value3);
void funb(int value1);
void func();

int main()
{
	funa(value1);
	funb(value2);
	funa(value2);
	func();
	cout << value1 << ' ' << value2 << ' ' << value3 << '\n';
	return 0;
}