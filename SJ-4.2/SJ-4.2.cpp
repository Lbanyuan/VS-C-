#include <iostream>
using namespace std;

int main()
{
	int value[10];
	for (int i = 1; i <= 10; i++)
	{
		cout << "�������" << i << "������:" << endl;
		cin >> value[i - 1];
	}
	cout << "���������" << endl;
	for (int i = 9; i >= 0; i--)
	{
		cout << value[i] << ' ';
	}
	return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
	int value[10];
	for (int i = 1; i <= 10; i++)
	{
		cout << "�������" << i << "������:" << endl;
		cin >> value[i - 1];
	}
	cout << "���������" << endl;
	for (int *i = value,j=9; j >= 0; j--)
	{
		cout << i[j]<< ' ';  //cout <<*(i+j)<<' ';
	}
	return 0;
}

*/

