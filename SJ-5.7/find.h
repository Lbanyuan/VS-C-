#ifndef __FIND_H__
#define	__FIND_H__

void index(int array[], int *size, int key, int&sub)//int *sub
{
	sub = -1;									//*sub=-1;
	for (int i = 0;array!=size; array++,i++)
	{
		if (*array == key)
		{
			sub = i;								//*sub=i;
			break;
		}
	}
}

#endif 
