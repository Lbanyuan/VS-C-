#include <iostream>

using namespace std;

int main()
{
	int input;
	cout << "Which number do you want to test:" << endl;
	cin >> input;
	if (input % 2==1)
		cout << "number " << input << " is odd.";
	else
		cout << "number " << input << " is even.";
	return 0;
}
