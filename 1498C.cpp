#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 1005
using namespace std;
int dp[N][N];
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
	for (int i = 1; i < N; i++)
		dp[i][1] = 1;
	for (int i = 1; i < N; i++)
		dp[1][i] = 2;
	for (int i = 1; i < N; i++)
		dp[0][i] = 1;
	while (T--)
	{
		int n = read(), k = read();
		for (int j = 1; j <= k; j++)
			for (int i = 1; i <= n; i++)
				dp[i][j] = (dp[i - 1][j] + dp[n - i][j - 1]) % P;
		printf("%d\n", dp[n][k]);
	}
	return 0;
}