#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
int a[N], vis[N], ans1, ans2;
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
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		if (a[i])
		{
			int p = 0;
			for (int dis = 1; dis <= n; dis++)
			{
				if (i - dis >= 1 && !a[i - dis] && !p && !vis[i - dis])
				{
					p = 1;
					vis[i - dis] = 1;
					ans1 += dis;
				}
				if (i + dis <= n && !a[i + dis] && !p && !vis[i + dis])
				{
					p = 1;
					vis[i + dis] = 1;
					ans1 += dis;
				}
				if (p)break;
			}
		}
	memset(vis, 0, sizeof(vis));
	for (int i = n; i >= 1; i--)
		if (a[i])
		{
			int p = 0;
			for (int dis = 1; dis <= n; dis++)
			{
				if (i - dis >= 1 && !a[i - dis] && !p && !vis[i - dis])
				{
					p = 1;
					vis[i - dis] = 1;
					ans2 += dis;
				}
				if (i + dis <= n && !a[i + dis] && !p && !vis[i + dis])
				{
					p = 1;
					vis[i + dis] = 1;
					ans2 += dis;
				}
				if (p)break;
			}
		}
	printf("%d\n", min(ans1, ans2));
	return 0;
}