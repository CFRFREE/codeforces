#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 200005
using namespace std;
LL ans[N];
LL id[N];
vector<LL>v[N];
int cmp(LL x, LL y)
{
	return x >= y;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &id[i]);
		for (register int i = 1; i <= n; i++)
		{
			LL x;
			scanf("%lld", &x);
			v[id[i]].push_back(x);
		}

		for (register int i = 1; i <= n; i++)
		{
			sort(v[i].begin(), v[i].end(), cmp);
			for (register int j = 1; j < v[i].size(); j++)
				v[i][j] += v[i][j - 1];
			int m = v[i].size();
			for (register int j = 1; j <= m; j++)
				ans[j] += v[i][m - (m % j) - 1];
		}
		for (register int i = 1; i <= n; i++)
		{
			printf("%lld ", ans[i]);
			v[i].clear();
		}
		printf("\n");
		memset(ans, 0, sizeof(ans));
	}
	return 0;
}