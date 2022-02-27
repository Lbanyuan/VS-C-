#include <iostream>
using namespace std;

int main()
{
	int num, i, j = 0;
	int a[100];
	cin >> num;
	i = num;
	while (i)
	{
		a[j] = i % 2;
		i /= 2;
		++j;
	}
	for (i = j - 1; i >= 0; i--)
		cout << a[i];
	return 0;
}