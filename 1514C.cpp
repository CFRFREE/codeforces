#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 100005
using namespace std;
int ans[N];
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
	int n = read();
	int s = 1;
	for (int i = 1; i <= n; i++)
	{
		if (__gcd(i, n) == 1)
		{
			ans[i] = 1;
			s = (s * i) % n;
			ans[0]++;
		}
	}
	if (s != 1)
	{
		ans[s] = 0;
		ans[0]--;
	}
	printf("%d\n", ans[0]);
	for (int i = 1; i <= n - 1; i++)
		if (ans[i])
			printf("%lld ", i);

	return 0;
}