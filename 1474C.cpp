#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 1000005
using namespace std;
int n, T, a[1005], vis[N], v[N];
vector<int> ans;
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
int ok(int id)
{
	memcpy(vis, v, sizeof(v));
	ans.clear();
	vis[a[id]]--;
	vis[a[n]]--;
	int m = n - 2;
	int sum = a[n];
	while (m > 0)
	{
		int p = 0;
		for (int j = n - 1; j >= 1; j--)
			if (vis[a[j]])
			{
				if (a[j] * 2 != sum && vis[sum - a[j]] || a[j] * 2 == sum && vis[a[j]] >= 2)
				{
					vis[a[j]]--;
					vis[sum - a[j]]--;
					ans.push_back(a[j]);
					ans.push_back(sum - a[j]);
					m -= 2;
					sum = a[j];
				}
				else return 0;
			}
	}
	return 1;
}
int main()
{
	T = read();
	while (T--)
	{
		memset(v, 0, sizeof(v));
		n = read();
		n = n << 1;
		for (int i = 1; i <= n; i++)
		{
			a[i] = read();
			v[a[i]]++;
		}
		sort(a + 1, a + n + 1);
		int flag = 0;
		for (int i = 1; i <= n - 1; i++)
		{
			if (ok(i))
			{
				printf("YES\n%d\n%d %d\n", a[n] + a[i], a[i], a[n]);
				for (int j = 1; j <= ans.size() / 2 ; j++)
					printf("%d %d\n", ans[j * 2 - 2], ans[j * 2 - 1]);
				flag = 1;
				break;
			}
		}
		if (!flag)
			printf("NO\n");
	}
	return 0;
}
