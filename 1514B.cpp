#include<bits/stdc++.h>
#define int long long
#define MAXN 100005

using namespace std;
int a, b, k;
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
int qpow(int x, int y, int k)
{
	int res = 1;
	x %= k;
	while (y)
	{
		if (y & 1)
			res = res * x % k;
		x = x * x % k;
		y >>= 1;
	}
	return res;
}

signed main()
{
	int T = read();
	while (T--)
	{
		int n = read(), k = read();
		printf("%d\n", qpow(n, k, 1000000007));
	}
	return 0;
}