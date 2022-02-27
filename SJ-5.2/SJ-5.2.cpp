#include <iostream>
#include "time.h"
using namespace std;
double delta(int N);

int main()
{
	int N;
	cout << "Please input N:"<<endl;
	cin >> N;
	double S = distance(N);
	cout << S;
	return 0;
}