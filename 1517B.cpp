#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 105
using namespace std;
map<int, int >M;
vector<int>tot;
int a[N][N], vis[N];
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
signed main()
{
	int T = read();
	while (T--)
	{
		int n = read(), m = read();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				a[i][j] = read();
				tot.push_back(a[i][j]);
			}
		sort(tot.begin(), tot.end());
		for (int i = 0; i < m; i++)
			M[tot[i]]++;
		tot.clear();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (M[a[i][j]])
				{
					for (int k = 1; k <= m; k++)
						if (!vis[k])
						{
							vis[k] = 1;
							M[a[i][j]]--;
							swap(a[i][j], a[i][k]);
							break;
						}
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%lld ", a[i][j]);
			printf("\n");
		}
		M.clear();
	}
	return 0;
}