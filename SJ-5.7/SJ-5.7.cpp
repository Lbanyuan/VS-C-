#include <iostream>
#include "find.h"
using namespace std;

void index(int array[], int *size, int key, int &sub);		//int *b
int main()
{
	int array[25] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,
					43,47,53,59,61,67,71,73,79,83,89,97 };
	int size = 25, key, sub;
	cout << "������ҪѰ�ҵ�����:" << endl;
	cin >> key;
	do
	{
		index(array, array+24, key, sub);						//&sub
		if (sub != -1)
			cout << "��ӦԪ���±�Ϊ:" << sub << endl;
		else
			cout << "δ�ҵ���" << endl;
		cout << "��������Ҫ���ҵ�����:" << endl;
		cin >> key;
	} while (key);
	return 0;
}