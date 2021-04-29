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
		int ans = 0;
		int n = read();
		if (n % 2050)
			ans = -1;
		else
		{
			int x = n / 2050;
			while (x)
			{
				ans += x % 10;
				x /= 10;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}