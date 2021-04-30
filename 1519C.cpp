#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 200005
using namespace std;
int ans;
vector<int>v[N];
vector<int>sum[N];
struct Node
{
	int id, w;
} a[N];
set<int>s;
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
int cmp(int x, int y)
{
	return x > y;
}
signed main()
{
	int T = read();
	while (T--)
	{
		int n = read();
		s.clear();
		for (int i = 1; i <= n; i++)
		{
			a[i].id = read();
			s.insert(a[i].id);
		}
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i].w = read();
			v[a[i].id].push_back(a[i].w);
		}
		for (auto i : s)
			sort(v[i].begin(), v[i].end(), cmp);

		for (auto i : s)
		{
			sum[i].push_back(v[i][0]);
			if (v[i].size() > maxn)maxn = v[i].size();
			int x = v[i][0];
			for (int j = 1; j < v[i].size(); j++)
			{
				sum[i].push_back(x + v[i][j]);
				x += v[i][j];
			}
		}
		for (int k = 1; k <= n; k++)
		{
			ans = 0;
			if (k <= maxn)
				for (auto i : s)
				{
					if (v[i].size() < k)
						continue;
					int x = v[i].size() / k * k - 1;
					ans += sum[i][x];
				}
			printf("%lld ", ans);
		}
		for (auto i : s)
		{
			v[i].clear();
			sum[i].clear();
		}
		printf("\n");
	}
	return 0;
}