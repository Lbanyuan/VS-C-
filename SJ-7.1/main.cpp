#include <iostream>
using namespace std;

template <typename T>
void Swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}
int main()
{
	double i, j;
	cout << "Please input two values:" << endl;
	cin >> i >> j;
	Swap(i, j);
	cout << i << " " << j << endl;

	string s1, s2;
	cout << "Please input two strings:" << endl;
	cin >> s1 >> s2;
	Swap(s1, s2);
	cout << s1 << " " << s2 << endl;
}