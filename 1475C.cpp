#include <bits/stdc++.h>
#define INF 2147483647
#define int long long
#define N 200005
using namespace std;
int a[N],b[N],boy[N],girl[N];
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
	{
		int qaq = read(), free = read(), k = read();
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int ans = 0;
		for (int i = 1; i <= k; i++)
		{
			int x = read();
			boy[i] = x;
			a[x]++;
		}
		for (int i = 1; i <= k; i++)
		{
			int y = read();
			girl[i] = y;
			b[y]++;
		}
		for (int i = 1; i <= k; i++)
			ans += (k - a[boy[i]] - b[girl[i]] + 1);
		printf("%lld\n", ans/2);
	}
	return 0;
}