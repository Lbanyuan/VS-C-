#include <iostream>
using namespace std;

int* index(int array[], int num)
{
	return &array[num];
}
int main()
{
	int array[] = { 2,4,6,8,10 };
	*index(array, 3) = 16;
	for (int i = 0; i < 5; i++)
		cout << *index(array, i) << " ";
	cout << endl;
	return 0;
}


/*
#include <iostream>
using namespace std;

int main()
{
	int array[] = { 2,4,6,8,10 };
	index(array, 3) = 16;
	for (int i = 0; i < 5; i++)
		cout << index(array, i) << " ";
	cout << endl;
	return 0;
}
*/