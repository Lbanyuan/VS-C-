#ifndef __SECRET_H__
#define __SECRET_H__
using namespace std;
const int sec = 100;

int x[100] = { 0 };
void secret( char* data)
{
	for (int j=0; *data; data++,j++)
	{
		x[j] = (*data + sec) / 128;
		*data = (*data + sec) % 128;	
	}
}
void desecret(char data[])
{
	for (int i = 0; data[i]; i++)
	{	
		data[i] = x[i] * 128 + data[i] - sec;
	}
}

/*
void secret( char* data)
{
	for (; *data; data++)
	{
		if (96<*data && *data <122)
			(*data)++;
		else if (*data == 122)  //if (*data == 122)
			*data = 'a';			//*data = 'a'
	}
}
void desecret(char data[])
{
	for (int i=0; data[i]; i++)
	{
		if (97 < data[i] && data[i] < 123)
			data[i]--;
		else if (data[i] == 97)	//if (data[i] == 97)
			data[i] = 'z';		//data[i] = 'z';
	}
}
*/

#endif 

