#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int n, m, a[N], c[N], b[N];
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
int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++)
		b[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n - 1; i++)
		c[i] = a[i + 1] - a[i];
	sort(c + 1, c + n);
	// for(int i = 1; i<n; i++)
	// 	printf("%d ", c[i]);
	// printf("\n");
	int G = 0;
	for (int i = c[1]; i >= 1; i--)
	{
		int p = 0;
		for (int j = 1; j <= n - 1; j++)
			if (c[j] % i != 0)
			{
				p = 1;
				break;
			}
		if (!p)
		{
			G = i;
			break;
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", gcd(b[i] + a[1], G));
	return 0;
}
