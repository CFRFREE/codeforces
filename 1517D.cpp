#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 505
using namespace std;
int a[N][N][3], dp[N][N][25];
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
	int n = read(), m = read(), K = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++)
			a[i][j][1] = read();
	for (int j = 1; j <= m; j++)
		for (int i = 1; i < n; i++)
			a[i][j][2] = read();

	if (K % 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("-1 ");
			printf("\n");
		}
		return 0;
	}
	for (int k = 1; k <= (K / 2); k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j][k] = INF;
				if (i != 1)dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - 1] + a[i - 1][j][2]);
				if (i != n)dp[i][j][k] = min(dp[i][j][k], dp[i + 1][j][k - 1] + a[i][j][2]);
				if (j != 1)dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k - 1] + a[i][j - 1][1]);
				if (j != m)dp[i][j][k] = min(dp[i][j][k], dp[i][j + 1][k - 1] + a[i][j][1]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%lld ", dp[i][j][K / 2] * 2);
		printf("\n");
	}

	return 0;
}