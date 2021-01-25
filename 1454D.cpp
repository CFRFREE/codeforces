#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 400005
#define int LL
using namespace std;
int T, n, m, maxn, now, s;
vector<int> v[N], ans;
unordered_map<LL, LL>cnt;
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
int prime(int x)
{
	if (x <= 2)
		return 1;
	for (int i = 2; i * i <= n; i++)
		if (x % i == 0)
			return 0;
	return 1;
}
signed main()
{
	T = read();
	while (T--)
	{
		n = read();
		maxn = 0;
		if (prime(n))
			printf("1\n%lld\n", n);
		else
		{
			int m = n;
			int i = 1;
			s = 0;
			cnt.clear();
			ans.clear();
			while (m > 1)
			{
				i++;
				if (m % i == 0)
				{
					s++;
					while (m % i == 0)
					{
						v[s].push_back(i);
						cnt[i]++;
						m /= i;
					}
					if (cnt[i] > maxn)
					{
						maxn = cnt[i];
						now = i;
					}
				}
			}
			printf("%lld\n", maxn);
			while (maxn--)
			{
				LL tot = 1;
				for (int i = 1; i <= s; i++)
				{
					if (!v[i].size())
						continue;
					tot *= v[i][0];
					v[i].pop_back();
				}
				ans.push_back(tot);
			}
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				printf("%lld ", ans[i]);
			printf("\n");
			for (int i = 1; i <= s; i++)
				v[i].clear();
		}
	}
	return 0;
}
