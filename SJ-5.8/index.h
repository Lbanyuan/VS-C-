#ifndef __INDEX_H__
#define __INDEX_H__

int* index(int array[], int num)
{
	return &array[num];				
}								
/*

int& index(int array[], int num)
{
	return array[num];
}

*/
#endif 

