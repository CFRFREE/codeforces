#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int T, n;
LL sum, a[N], maxn;
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
		sum = 0;
		maxn = 0;
		for (int i = 1; i <= n; i++)
			a[i] = read();
		for (int i = 2; i <= n; i++)
			sum += abs(a[i] - a[i - 1]);
		for (int i = 2; i <= n - 1; i++)
			maxn = max(maxn, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1]));
		maxn = max(maxn, max(abs(a[1] - a[2]), abs(a[n] - a[n - 1])));
		printf("%lld\n", sum - maxn);
	}
	return 0;
}