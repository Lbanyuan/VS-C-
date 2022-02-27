#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	const int size = 100;
	char str[size];
	int i, len, is_palindrome = 1;
	cout << "Please input string:";
	cin.get(str, size);
	len = strlen(str);
	for (i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
			is_palindrome = 0;
			break;
	}
	if (is_palindrome)
		cout << "The string is a palindrome";
	else
		cout << "The string isn't a palindrome";
	return 0;
}



/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int len, j = 0, is_palindrome = 1;
	const int size = 100;
	string str(size,0), x;
	cout << "Please input a sting:" << endl;
	getline(cin, x);
	len = x.size();
	for (; len > 0; len--)
	{
		if ((('A' < x[len - 1]) && (x[len - 1] < 'Z')) || (('a' < x[len - 1]) && (x[len - 1] < 'z')))
		{
			str.at(j) = x.at(len - 1);
			j++;
		}
	}
	for (int n = 0; n < j / 2; n++)
	{
		bool TF = ((str[n] != str[j - n - 1] + 32) && (str[n] != str[j - n - 1] - 32)) && (str[n] != str[j - n - 1]);
		if (TF)
			is_palindrome = 0;
			break;	
	}
	if (is_palindrome)
		cout << "The string is a palindrome";
	else
		cout << "The string isn't a palindrome";
	return 0;
}
*/

/*
#include <iostream>
#include <string>

using namespace std;
int main()
{
	const int size = 100;
	string str(size,0);
	int i=0, len, is_palindrome = 1;
	cout << "Please input string:"<< endl;
	getline(cin, str);
	len = str.size();
	for (auto p=str; i < len / 2; i++)  //for (auto p=&str[0]; p- &str[0] < len / 2;i=i+2,p++)
	{
		if (p[i] != p[len - i - 1])  //if (*p!= *(p+len-i))
			is_palindrome = 0;
		break;
	}
	if (is_palindrome)
		cout << "The string is a palindrome";
	else
		cout << "The string isn't a palindrome";
	return 0;
}
*/
