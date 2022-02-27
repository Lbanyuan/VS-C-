#include <iostream>

using namespace std;
int main()
{
	char x;
	cout << "Please input:"<<endl;
	
	do
	{
		x = cin.get();
		if (x >= 65 && x <= 90)
			x += 32;
		else if(x>=97&&x<=122)
			x -= 32;
		cout << x;	
	} while (x != EOF);
	return 0;
}