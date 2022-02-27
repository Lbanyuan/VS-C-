#ifndef __FUNCTION_H__
#define __FUNCTION_H__

double Pn(double x, int n)
{
	if (n > 1)
		return ((2 * n - 1)*Pn(x, n - 1) - (n - 1) * Pn(x, n - 2))/n;
	else if (n == 0)
		return 1;
	else if (n == 1)
		return x;
}

#endif 

