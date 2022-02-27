#ifndef __CONTROL_H__
#define __CONTROL_H__

double r, y, step;
double control(double &x)
{
	while (fabs(r - y) > 0.01 * r)
	{
		if (r > x)
			x += step;
		else if (r < x)
			x -= step;
	}
	return y;
}

#endif

