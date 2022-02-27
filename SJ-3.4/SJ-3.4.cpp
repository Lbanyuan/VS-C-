#include <iostream>

using namespace std;
int main()
{
	int x, a, b;
	cout << "Please input x:" << endl;
	cin >> x;
	a = x % 3;
	b = x % 7;
	if (!a)
	{
		if (b >= 1 && b <= 6)
			cout << "x是3的倍数，但不是7的倍数" << endl;
		else
			cout << "x既是3的倍数，也是7的倍数"<<endl;
	}
	else if (b == 0)
		cout << "x是7的倍数，但不是3的倍数"<<endl;
	else
		cout << "x既不是3的倍数，也不是7的倍数"<<endl;
	return 0;
}