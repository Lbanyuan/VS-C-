#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	while (1)
	{
		srand(time(0));
		int target = rand() % 100;
		int guess;
		cout << "�²�0-100�ڵ���" << endl;
		do
		{
			do
			{
				cout << "Please input your guess" << endl;
				cin >> guess;
			} while (guess >= 100 || guess < 0);

			if (guess > target)
			{
				cout << "��´��ˣ�" << endl;
			}
			else if (guess < target)
			{
				cout << "���С�ˣ�" << endl;
			}
			else
			{
				cout << "��¶���" << endl;
			}
		} while (guess != target);
			char play;
			cin >> play;
			if (play == 'n' || play == 'N')
				break;					
	}
	return 0;
}

/*
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	while (1)
	{
		srand(time(0));
		int target = rand() % 100;
		int guess;
		cout << "�²�0-100�ڵ���" << endl;
		do
		{
			do
			{
				cout << "Please input your guess" << endl;
				cin >> guess;
			} while (guess >= 100 || guess < 0);
			int val = (target > guess) - (target < guess);
			switch(val)
			{
			case 1:
				cout << "��С��" << endl; break;
			case-1:
				cout << "�´���" << endl; break;
			case 0:
				cout << "�¶���" << endl; break;
			}
		} while (guess != target);
		char play;
		cin >> play;
		if (play == 'n' || play == 'N')
			break;
	}
	return 0;
}
*/