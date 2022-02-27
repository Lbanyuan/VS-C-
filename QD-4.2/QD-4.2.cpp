#include <iostream>
using namespace std;

int main()
{
	constexpr int sz = 8;
	int que[sz] = { 0 };
	int i = 0;
	while (i >= 0)
	{
		int k = 0;
		while (k < i)
		{
			if (que[k] != que[i] && (abs(que[i] - que[k]) != abs(i - k)))
				k++;
			else
				break;
		}
		if (k < i)
		{
			++que[i];
			while (que[i] == sz)
			{
				que[i] = 0;
				--i;
				if (i < 0)
					break;
				++que[i];
			}
			continue;
		}
		else
		{
			++i;
			if (i < sz)
				continue;
			cout << "找到一个方案：";
			for (k = 0; k < sz; ++k)
				cout << que[k];
			cout << endl;
			break;
		}
	}
	return 0;
}




