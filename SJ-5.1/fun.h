
#ifndef __FUN_H__
#define __FUN_H__
using namespace std;

int value1=300, value2=400, value3=500;
void funa(int value3)
{
	static int value1 = 5;
	value1 += value3;
	cout << value1 << ' ' << value3 << '\n';
}
void funb(int value1)
{
	value1 = value2;
	cout << value1 << "\n";
}
void func()
{
	int value3 = 0;
	cout << value1 << ' ' << value2 << ' ' << value3 << '\n';
	::value3 -= 100;
}


#endif
