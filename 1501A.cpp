#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int a[N], b[N], t[N], ans;
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
		int n = read();
		ans = 0;
		for (int i = 1; i <= n; i++)
			a[i] = read(), b[i] = read();
		for (int i = 1; i <= n; i++)
			t[i] = read();
		for (int i = 1; i <= n; i++)
			t[i] += a[i] - b[i - 1];

		for (int i = 1; i < n; i++)
		{
			ans += t[i];
			int x = (b[i] - a[i] + 1) / 2;
			ans += max(x, b[i] - ans);
		}
		printf("%d\n", ans+t[n]);
	}
	return 0;
}