#include <iostream>

using namespace std;
int main()
{
	char c;
	int nWhite = 0, nOther = 0, nDight = 0;
	c = cin.get();
	while (c != EOF)
	{
		switch (c)
		{
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			nDight++;
			break;
		case' ':case'\t':case'\n':
			nWhite++;
			break;
		default:
			nOther++;
			break;
		}
		c = cin.get();
	}
	cout << "Dights= " << nDight << endl;
	cout << "White space= " << nWhite << endl;
	cout << "Other chars= "  << nOther << endl;

	return 0;
}



/*

#include <iostream>

using namespace std;
int main()
{
	char c;
	int n=0;
	int nWords = 0, nLine = 0,nChar=0;
	c = cin.get();
	while (c != EOF)
	{
		n++;
		switch (c)
		{
		case' ':
			nWords++;
			break;
		case'\n':
			nLine++;
			break;
		}
		c = cin.get();
		nChar++;
	}
	cout << "Words= " << nWords<< endl;
	cout << "Line=" << nLine << endl;
	cout << "Char=" << nChar << endl;
	return 0;
}


*/