#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int a[N], Next[N], pos[N], ans;
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
	for (int i = 0; i <= n; i++)
		pos[i] = n + 1;
	for (int i = n; i >= 0; i--)
	{
		Next[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	int x = 0;
	int y = 0;
	for (int i = 1; i <= n; i++)
	{
		int z = a[i];
		if (a[x] == z)
		{
			ans += (z != a[y]);
			y = i;
		}
		else if (a[y] == z)
		{
			ans += (z != a[x]);
			x = i;
		}
		else if (Next[x] < Next[y])
		{
			ans += (z != a[x]);
			x = i;
		}
		else
		{
			ans += (z != a[y]);
			y = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
