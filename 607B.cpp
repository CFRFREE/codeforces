#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 505
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
	while (isdigit(ch))
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
int main()
{
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++)
		dp[i][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			dp[i][j] = 0;
	for (int i = 2; i <= n; i++)
		if (a[i] == a[i - 1])
			dp[i - 1][i] = 1;
		else
			dp[i - 1][i] = 2;

	for (int len = 3; len <= n; len++)
		for (int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			for (int k = i; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			if (a[i] == a[j])dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
		}
	printf("%d\n", dp[1][n]);
	return 0;
}