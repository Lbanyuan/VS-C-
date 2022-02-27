#include <iostream>
#include "find.h"
using namespace std;

void index(int array[], int *size, int key, int &sub);		//int *b
int main()
{
	int array[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,
					43,47,53,59,61,67,71,73,79,83,89,97 };
	int size = 25, key, sub;
	cout << "请输入要寻找的数字:" << endl;
	cin >> key;
	do
	{
		index(array, array+24, key, sub);						//&sub
		if (sub != -1)
			cout << "对应元素下标为:" << sub << endl;
		else
			cout << "未找到。" << endl;
		cout << "重新输入要查找的数字:" << endl;
		cin >> key;
	} while (key);
	return 0;
}