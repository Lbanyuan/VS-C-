#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
int main()
{
	char play;
	int computer, you;
	do
	{
		do
		{
			do
			{
				srand(time(0));
				computer = rand() % 3;
				cout << "Please input you:" << endl;
				cin >> you;
			} while (you < 0 || you > 2);
			switch (you - computer)
			{
			case-1:case 2:
				cout << "你赢了" << endl;
				break;
			case-2:case 1:
				cout << "你输了" << endl;
				break;
			case 0:
				cout << "平手" << endl;
				break;
			}
		} while (computer == you);
		cout << "还要继续玩吗？" << endl;
		cin >> play;
	} while (play == 'Y' || play == 'y');
	return 0;
}
