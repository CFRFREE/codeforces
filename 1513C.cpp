#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 200005
using namespace std;
int dp[10][N];
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
int work(int i, int j)
{
	if (dp[i][j])
		return dp[i][j] % P;
	if (i + j < 10)
	{
		dp[i][j] = 1;
		return 1;
	}
	dp[i][j] = (work(1, j + i - 10) + work(0, j + i - 10)) % P;
	return dp[i][j] % P;
}
int main()
{
	int T = read();
	while (T--)
	{
		int n = read(), k = read();
		int ans = 0;
		while (n)
		{
			ans = (ans + work(n % 10, k)) % P;
			n /= 10;
		}
		printf("%d\n", ans);
	}
	return 0;
}