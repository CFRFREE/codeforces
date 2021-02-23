#include <bits/stdc++.h>
#define INF 2147483647
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
		int p = read(), a = read(), b = read(), c = read();

		if (p % a == 0 || p % b == 0 || p % c == 0)
			printf("0\n");
		else
		{
			int ans1 = ((p / a) + 1) * a - p;
			int ans2 = ((p / b) + 1) * b - p;
			int ans3 = ((p / c) + 1) * c - p;
			printf("%lld\n", min(min(ans1, ans2), ans3));
		}
	}
	return 0;
}