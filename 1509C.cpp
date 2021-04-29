#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 2005
using namespace std;
int dp[N][N], a[N];
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
	sort(a + 1, a + n + 1);
	memset(dp, 0, sizeof(dp));
	for (int len = 1; len <= n - 1; len++)
		for (int i = 1; i + len <= n; i++)
			dp[i][i + len] = a[i + len] - a[i] + min(dp[i + 1][i + len], dp[i][i + len - 1]);
	printf("%lld\n", dp[1][n]);
	return 0;
}