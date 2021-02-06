#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n,T,a[N],b[N],c[N],ans,now;
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
	T = read();
	while (T--)
	{
		n = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		for (int i = 1; i <= n; i++)
			b[i] = read();
		for (int i = 1; i <= n; i++)
			c[i] = read();
		now = a[n];
		ans = 0;
		for (int i = n; i >= 2; i--)
		{
			int x = b[i], y = c[i];
			if (x == y)
			{
				ans = max(ans, now + 1);
				now = a[i - 1];
			}
			else if (x < y)
			{
				now += x + (a[i - 1] - y + 1);
			}
			else
			{
				now += a[i - 1];
			}
			ans = max(ans, now);
		}
		printf("%d\n", ans);
	}
	return 0;
}