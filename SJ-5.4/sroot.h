#ifndef __SROOT_H__
#define __SROOT_H__

double a, x1, x2;
double sroot(double &val)
{
	x2 = (x1 + a / x1) / 2;
	return x2;
}

#endif 

