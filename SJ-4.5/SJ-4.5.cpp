#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, j, i = 0;
	cout << "Please input n,m:";
	cin >> n >> m;
	j = n;
	vector<bool>con(n, 1);
	while (j - 1)
	{
		for (int num = 1; num <= m; )
		{
			if (con[i] == 0) {}
			else
			{
				if (num == m)
				{
					con[i] = 0;
					i++;
					if (i >= n)
						i = 0;
					break;
				}
				num++;
			}
			i++;
			if (i >= n)
				i = 0;
		}
		j--;
	}
	for (n = n - 1; n >= 0; n--)
	{
		if (con[n] == 1)
			cout << n + 1;
	}
}

/*

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cout << "Please input n,m:";
	cin >> n >> m;
	int L = n;
	vector<int>con(n);
	for(int i = 0; i < n; i++)
	{
		con[i] = i+1;
	}
	int j = 0;
	while (con.size() > 1)
	{
		j = (j + m - 1) % con.size();
		con.erase(con.begin()+j);
	}
		cout << con[0];
}

*/