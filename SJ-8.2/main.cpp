#include"Stack.h"
#include"Calculator.h"

int main()
{
	string exp; 
	Calculator cal;
	while (getline(cin, exp))

		cout << exp << cal.doIt(exp) << endl;
}