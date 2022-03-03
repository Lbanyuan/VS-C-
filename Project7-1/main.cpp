#include <iostream>
#include "Fraction.h"

using namespace std;


//const int& getMax(const int& a, const int& b)
//{
//	return a > b ? a : b;
//}
//
//const string& getMax(const string& a, const string b)
//{
//	return a > b ? a : b;
//}

template <typename T>
const T& getMax(const T& a, const T& b)
{
	return a > b ? a : b;
}

template <typename T, int size> //��ģ�����Ϊ�����Ͳ�����ʵ�α���ʱ����ʱ����
const T& maxElem(T(&arr)[size])
{
	T* p = &arr[0];
	for (int i = 0; i <= size - 1; ++i)
	{
		if (*p < arr[i])
			p = &arr[i];
	}
	return *p;
}

int main()
{
	/*cout << getMax(1.0, 2.4) << endl;
	Fraction a(1, 2), b(2, 3);
	cout << getMax(a, b) << endl;*/
	int arr[10] = { 1,2,3,4 };
	cout << maxElem(arr);
}