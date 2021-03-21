#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 105
using namespace std;
int a[N];
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
		int ans = 0;
		for (int i = 1; i <= n; i++)
			a[i] = read();
		for (int i = 1; i <= n - 1; i++)
		{
			int x = max(a[i], a[i + 1]);
			int y = min(a[i], a[i + 1]);
			int lg = 1;
			while ((y << lg) < x)
				lg++;
			ans += (lg-1);
		}
		printf("%d\n", ans);
	}
	return 0;
}