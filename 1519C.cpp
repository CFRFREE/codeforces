#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 200001
using namespace std;
int id[N];
LL ans[N];
vector<LL>v[N];
set<int >s;
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
inline int cmp(int x, int y)
{
	return x > y;
}
int main()
{
	int T = read();
	while (T--)
	{
		int n = read();
		s.clear();
		memset(ans, 0, sizeof(ans));
		for (register int i = 1; i <= n; i++)
		{
			id[i] = read();
			s.insert(id[i]);
		}
		for (register int i = 1; i <= n; i++)
		{
			LL x = read();
			v[id[i]].push_back(x);
		}
		for (int x = 1; x <= n; x++)
		{
			sort(v[x].begin(), v[x].end(), cmp);
			int m = v[x].size();
			for (register int i = 1; i < m; i++)
				v[x][i] += v[x][i - 1];
			for (register int i = 1; i <= m; i++)
				ans[i] += v[x][m - m % i - 1];
			v[x].clear();
		}
		for (register int i = 1; i <= n; i++)
			printf("%lld ", ans[i]);
		printf("\n");
	}
	return 0;
}