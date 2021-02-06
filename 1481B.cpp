#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, k, a[N], cnt, i, sum;
vector<int>v[N], id[N];
inline int read()
{
	int X = 0, w = 0;
	char ch = 0;
	while (!isdigit(ch))
	{
		w |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
int main()
{
	T = read();
	while (T--)
	{
		n = read(), k = read();
		memset(a, 0, sizeof(a));
		for (i = 1; i <= n; i++)
			a[i] = read();
		cnt = 1;
		i = 2;
		sum = 0;
		while (i <= n)
		{
			if (a[i] >= a[i - 1])
			{
				v[cnt].push_back(a[i - 1]);
				id[cnt].push_back(i - 1);
				i++;
			}
			else
			{
				if (v[cnt].size())
				{
					v[cnt].push_back(a[i - 1]);
					id[cnt].push_back(i - 1);
				}
				while (a[i] < a[i - 1] && i <= n)i++;
				cnt++;
			}
		}
		if (a[n] >= a[n - 1])
		{
			v[cnt].push_back(a[n]);
			id[cnt].push_back(n);
		}
		/*		for(i=1;i<=cnt;i++)
				{
					if(!v[i].size())continue;
					for(int j=0;j<v[i].size();j++)
						printf("%d ", v[i][j]);
					printf("\n");
					for(int j=0;j<id[i].size();j++)
						printf("%d ", id[i][j]);
					printf("\n");
				}*/
		int tot = 0;
		for (i = 1; i <= cnt; i++)
		{
			if (!v[i].size())continue;
			for (int j = 0; j < v[i].size(); j++)
				tot += v[i][v[i].size() - 1] - v[i][j];
		}
		if (tot < k)printf("-1\n");
		else
		{
			for (i = 1; i <= cnt; i++)
			{
				if (!v[i].size())continue;
				int s = 0;
				for (int j = 0; j < v[i].size(); j++)
					s += v[i][v[i].size() - 1] - v[i][j];
				if (sum + s < k)
					sum += s;
				else
				{
					while (1)
					{
						//for (int j = 0; j < v[i].size(); j++)
						//printf("%d ", v[i][j]);
						//printf("\n");
						int p = 0;
						for (int j = 1; j < v[i].size(); j++)
							if (v[i][j] != v[i][j - 1])p = 1;
						if (!p)break;
						for (int j = 1; j < v[i].size(); j++)
						{
							if (v[i][j] == v[i][j - 1])continue;
							sum += v[i][j] - v[i][j - 1];
							v[i][j - 1] = v[i][j];
							if (sum >= k)
							{
								printf("%d\n", id[i][j - 1]);
								goto qaq;
							}
							break;
						}
					}
				}
			}
		}
qaq:;
		for (i = 1; i <= cnt; i++)
		{
			v[i].clear();
			id[i].clear();
		}
	}
	return 0;
}
