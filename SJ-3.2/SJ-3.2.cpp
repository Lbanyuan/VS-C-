#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double a, b, c, x1, x2,delta,Delta;
	do
	{
		cout << "Please input a b c:";
		cin >> a >> b >> c;
	} while (!a);
	delta = b * b - 4 * a * c > 0;
	Delta = sqrt(b * b - 4 * a * c);
		if (delta)
		{
			x1 = -b + Delta / 2 * a;
			x2 = -b - Delta / 2 * a;
			cout << "��x1= " << x1 << endl << "��x2= " << x2;
		}
		else if (delta)
			cout << "��һԪ���η���ʵ����" << endl;
		else
		{
			x1 = x2 = -b / 2 * a;
			cout << "��һԪ���η�����������ͬ�ĸ� x1=x2=" << x1;
		}
		return 0;
	}



