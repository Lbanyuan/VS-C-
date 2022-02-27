# include <iostream>
# include <cstdlib>
using namespace std;

int main()
{
	srand(0);
	const int sz = 30;
	int score[30];
	int mean = 0;
	for (auto i : score)
	{
		i = 50 + rand() % 51;
		mean += i;
	}
	mean /= sz;
	double dev = 0;
	for (int n = 0; n < sz; n++)
	{
		dev += pow(score[n] - mean, 2);
	}
	dev = sqrt(dev / sz);
	cout << "Æ½¾ù³É¼¨=" << mean << endl << "±ê×¼²î=" << dev;
	return 0;
}
