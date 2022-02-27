#include <iostream>

using namespace std;
int main()
{
	int cnt = 0;
	char x;
	do
	{
		x = cin.get();
		if (x >= '0' && x <= '9')
			cnt++;
	} while (x != EOF);
	cout << cnt;
}
