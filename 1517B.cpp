#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 205
using namespace std;
int a[N][N];
map<int, int>M;
vector<int>tot;
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
	int T = read();
	while (T--)
	{
		int n = read(), m = read();
		memset(a, 0, sizeof(a));
		tot.clear();
		M.clear();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				a[i][j] = read();
				tot.push_back(a[i][j]);
			}
			a[i][m + 1] = a[i][m];
		}
		sort(tot.begin(), tot.end());
		for (int i = 0; i < m; i++)
		{
			M[tot[i]] ++;
			//printf("%d\n", tot[i]);
		}
		for (int j = 1; j <= m; j++)
		{
			int p = 0;
			for (int i = 1; i <= n; i++)
			{
				if (M[a[i][j]] >= 1)
				{
					if (p)
						swap(a[i][j], a[i][j + 1]);
					else
					{
						M[a[i][j]]--;
						p = 1;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}

	}
	return 0;
}