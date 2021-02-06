#include <bits/stdc++.h>
#define INF 2147483647
#define int long long
#define N 100005
using namespace std;
int T, n, sum, ans, now, k;
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
	T = read();
	while (T--)
	{
		n = read(), k = read();
		sum = read();
		ans = 0;
		for (int i = 2; i <= n; i++)
		{
			now = read();
			if (now * 100 / k > sum)
			{
				ans += double(now * 100.0 / k* 1.0 + 0.5) - sum;
				sum =  double(now * 100.0 / k * 1.0 + 0.5);
			}
			else sum += now;
		}
		printf("%lld\n", ans);
	}
	return 0;
}