#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
int L[N], R[N];
LL dp[N][2];
vector<int>a[N];
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
void dfs(int x, int fa)
{
	for (auto y : a[x])
	{
		if (y == fa)continue;
		dfs(y, x);
		dp[x][0] += max(abs(L[x] - L[y]) + dp[y][0], abs(L[x] - R[y]) + dp[y][1]);
		dp[x][1] += max(abs(R[x] - L[y]) + dp[y][0], abs(R[x] - R[y]) + dp[y][1]);
	}
}
int main()
{
	int T = read();
	while (T--)
	{
		int n = read();
		for (int i = 1; i <= n; i++)
			L[i] = read(), R[i] = read();
		for (int i = 1; i < n; i++)
		{
			int x = read(), y = read();
			a[x].push_back(y);
			a[y].push_back(x);
		}
		dfs(1, 0);
		printf("%lld\n", max(dp[1][0], dp[1][1]));
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			dp[i][0] = dp[i][1] = 0;
		}

	}
	return 0;
}