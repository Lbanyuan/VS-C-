#ifndef __MAX_H__
#define __MAX_H__

int line, row;
int max_value(const int array[][4], int n)
{
	int i, j, max = array[0][0];
	for (i = 0; i < n; i++)
		for (j = 0; j < 4; j++)
			if (array[i][j] > max)
			{
				max = array[i][j];
				line = i + 1;
				row = j + 1;
			}
	return max;
}

#endif 
