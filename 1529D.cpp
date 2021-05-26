#include <bits/stdc++.h>
#define P 998244353
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 1000005
using namespace std;
int dp[N], cnt[N], sum[N];
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
	sum[0] = 1, sum[1] = 2;
	dp[0] = 1, dp[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 1; i * j <= n; j++)
			dp[i * j]++;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = (dp[i] + sum[i - 1]) % P;
		sum[i] = (sum[i - 1] + dp[i]) % P;
	}
	printf("%lld\n", dp[n]);
	return 0;
}