#include <bits/stdc++.h>
#define INF 2147483647
#define int long long
#define N 100005
using namespace std;
int A, B, n;
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
struct Node
{
	int a, b;
} m[N];
inline int cmp(Node x, Node y)
{
	return x.a < y.a;
}
int ok()
{
	for (int i = 1; i <= n; i++)
	{
		int x = m[i].b / A;
		if (x * A!=m[i].b)x++;
		if (B <= (x - 1) * m[i].a)
			return 0;
		B -= x * m[i].a;
		if (B <= 0)
		{
			if (i == n)
				return 1;
			else
				return 0;
		}
	}
	return 1;
}
signed main()
{
	int T = read();
	while (T--)
	{
		A = read(), B = read(), n = read();
		for (int i = 1; i <= n; i++)
			m[i].a = read();
		for (int i = 1; i <= n; i++)
			m[i].b = read();
		sort(m + 1, m + n + 1, cmp);
		if (ok())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}