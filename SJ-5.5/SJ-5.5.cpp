#include <iostream>
#include "secret.h"
using namespace std;

void secret(char* date);
void desecret(char date[]);
int main()
{
	
	char st[] = "This is a secret code!";//char st[] = "I am a boy!";
	cout << st << endl;
	secret(st);
	cout << st << endl;
	desecret(st);
	cout << st << endl;
	return 0;
}