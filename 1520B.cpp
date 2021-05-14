#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 100005
using namespace std;
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
		int n = read();
		if (n < 10)
		{
			printf("%d\n", n);
			continue;
		}
		int x = n;
		int mini = INF;
		int m = 0;
		while (x)
		{
			mini = min(mini, x % 10);
			x /= 10;
			m++;
		}
		int ans = (m - 1) * 9;
		int tem = 0;
		for (int i = 1; i <= m; i++)
			tem = tem * 10 + 1;
		for (int i = 1; i <= 9; i++)
			if (n >= i * tem)ans++;
		printf("%lld\n", ans);
	}
	return 0;
}