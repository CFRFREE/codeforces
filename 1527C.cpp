#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 100005
using namespace std;
int m, ans;
vector<int>v[N], sum[N];
map<int, int>M;
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
	int T = read();
	while (T--)
	{	int n = read();
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			if (!M[x])M[x] = ++m;
			v[M[x]].push_back(i);
		}
		for (int i = 1; i <= m; i++)
		{
			sum[i].push_back(v[i][0]);
			for (int j = 1; j < v[i].size(); j++)
				sum[i].push_back(sum[i][j - 1] + v[i][j]);
			for (int j = 0; j < v[i].size(); j++)
			{
				ans += 1ll * (n + 1) * v[i][j] * (v[i].size() - j - 1);
				ans -= 1ll * v[i][j] * (sum[i][v[i].size() - 1] - sum[i][j]);
			}
		}
		printf("%lld\n", ans);
		ans = m = 0;
		for (int i = 0; i <= n; i++)
			v[i].clear(), sum[i].clear();
		M.clear();
	}
	return 0;
}
