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
			cout << "x��3�ı�����������7�ı���" << endl;
		else
			cout << "x����3�ı�����Ҳ��7�ı���"<<endl;
	}
	else if (b == 0)
		cout << "x��7�ı�����������3�ı���"<<endl;
	else
		cout << "x�Ȳ���3�ı�����Ҳ����7�ı���"<<endl;
	return 0;
}