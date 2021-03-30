#include <bits/stdc++.h>
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
int a[N], cnt[1000005], ans, tot;
vector<int>vis;
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
	while (T--)
	{
		memset(cnt, 0, sizeof(cnt));
		tot = 0;
		vis.clear();
		ans = 1;
		int n = read(), w = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			//printf("%d\n",a[i]);
			cnt[a[i]]++;
			if (cnt[a[i]] == 1)
				vis.push_back(a[i]);
		}
		while (tot != n)
		{
			ans++;
			int left = w;
			int flag = 0;
			do
			{
				int L = 0;
				int R = vis.size()-1;
				while (L <= R)
				{
					int mid = (L + R) >> 1;
					if (left >= vis[mid] && cnt[vis[mid]])
					{
						flag = 1;
						L = mid;
					}
					else
						R = mid;
				}
				if (flag)
				{
					tot++;
					left-=vis[L];
				}
			} while (flag);
		}
		printf("%d\n", ans);
	}
	return 0;
}
