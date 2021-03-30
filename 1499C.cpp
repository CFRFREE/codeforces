#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 100005
using namespace std;
int a[N], b[N];
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
		int mina = INF;
		int minb = INF;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				int x = read();
				a[(i + 1) / 2] = x;
				mina = min(mina, x);
			}
			else
			{
				int x = read();
				b[(i + 1) / 2] = x;
				minb = min(minb, x);
			}
		}
		for (int i = 1; i <= (n + 1) / 2; i++)
			if (a[i] != mina)
				ans += a[i];
			else
			{
				ans += (n + 1 - i) * mina;
				break;
			}
		for (int i = 1; i <= n - (n + 1) / 2; i++)
			if (b[i] != minb)
				ans += b[i];
			else
			{
				ans += (n + 1 - i) * minb;
				break;
			}
		printf("%lld\n", ans);
	}
	return 0;
}