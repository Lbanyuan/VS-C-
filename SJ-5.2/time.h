#ifndef __TIME_H__
#define __TIME_H__
#include <ctime>

double delta(int N)
{
	double del = 0;
	clock_t start = clock();
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 10000; ++j)
		{
			for (int k = 0; k < 10000; ++k);
		}
	}
	clock_t ends = clock();
	del = (double)(ends - start) / CLOCKS_PER_SEC;
	return del;
}
double distance(int N)
{
	double d = delta(N) * 170;
	return d;
}

#endif