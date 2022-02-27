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
		cout << "猜猜0-100内的数" << endl;
		do
		{
			do
			{
				cout << "Please input your guess" << endl;
				cin >> guess;
			} while (guess >= 100 || guess < 0);

			if (guess > target)
			{
				cout << "你猜大了！" << endl;
			}
			else if (guess < target)
			{
				cout << "你猜小了！" << endl;
			}
			else
			{
				cout << "你猜对了" << endl;
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
		cout << "猜猜0-100内的数" << endl;
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
				cout << "猜小了" << endl; break;
			case-1:
				cout << "猜大了" << endl; break;
			case 0:
				cout << "猜对了" << endl; break;
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