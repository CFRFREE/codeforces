#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 5005
using namespace std;
int a[N], b[N];
int dp[N][N], sum[N], ans;
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
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		b[i] = read();
		if (n == 1)
		{
			printf("%lld\n", a[i]*b[i]);
			return 0;
		}
		sum[i] = sum[i - 1] + (int)a[i] * b[i];
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = sum[n];
	for (int len = 2; len <= n; len++)
	{
		for (int i = 1; i + len - 1 <= n; i++)
			dp[i][i + len - 1] = dp[i + 1][i + len - 2] - (int)a[i + len - 1] * b[i + len - 1] - (int)a[i] * b[i]
			                     + (int)a[i + len - 1] * b[i] + (int)a[i] * b[i + len - 1];
	}
	for (int i = 1; i < n; i++)
		for (int j = i; j <= n; j++)
			ans = max(ans, dp[i][j]);
	printf("%lld\n", ans);
	return 0;
}