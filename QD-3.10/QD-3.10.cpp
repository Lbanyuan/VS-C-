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
				cout << "��Ӯ��" << endl;
				break;
			case-2:case 1:
				cout << "������" << endl;
				break;
			case 0:
				cout << "ƽ��" << endl;
				break;
			}
		} while (computer == you);
		cout << "��Ҫ��������" << endl;
		cin >> play;
	} while (play == 'Y' || play == 'y');
	return 0;
}
