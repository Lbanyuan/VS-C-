#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector <int> num(13);
	string EAN_13;
	int code_odd, code_even, code_check_1, code_check_2;
	cout << "Please input EAN-13:" << endl;
	cin >> EAN_13;
	for (int i = 0; i <= 12; i++)
	{
		num[i] = static_cast<int>(EAN_13[i]) - 48;
	}
	code_odd = num[0] + num[2] + num[4] + num[6] + num[8] + num[10];
	code_even = (num[1] + num[3] + num[5] + num[7] + num[9] + num[11]) * 3;
	code_check_1 = (code_odd + code_even) % 10;
	code_check_2 = (10 - code_check_1) % 10;
	if (code_check_2 == num[12])
	{
		cout << "该条形码正确" << endl;
		if ((num[1] == 9&&num[0]==6) && (0 <= num[2] && num[2] <= 2))
		{
			cout << "该条形码属于中国" << endl;
			if (num[2] == 0 || num[2] == 1)
			{
				cout << "该厂商代码为";
				for (int i = 3; 3 <= i && i <= 6; i++)
					cout << num[i];
				cout << endl << "该商品项目代码为";
				for (int j = 7; 7 <= j && j <= 11; j++)
					cout << num[j];
			}
			else
			{
				cout << "该厂商代码为";
				for (int i = 3; 3 <= i && i <= 7; i++)
					cout << num[i];
				cout << endl << "该商品项目代码为";
				for (int j = 8; 8 <= j && j <= 11; j++)
					cout << num[j];
			}
			cout << endl << "该条形码校检码为" << num[12];
		}
		else
			cout << "该代码不属于中国";

	}
	else
		cout << "该条形码错误" << endl;
	return 0;
}