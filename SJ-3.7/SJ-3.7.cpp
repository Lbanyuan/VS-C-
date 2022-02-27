#include <iostream>

using namespace std;
int main()
{
	int n, i,count=40,star, line=1;
	cout << "Please give n:";
	cin >> n;
	do
	{
		i=count--;
		for (; i >= 0; i--)
		{
			cout << " ";
		}
		star = 2 * line - 1;
		while (star)
		{
			cout << '*';
			star--;
		}
		cout << endl;
		line++;
	} while (n>=line);
}
