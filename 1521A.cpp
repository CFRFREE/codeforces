#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
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
int main()
{
	int T = read();
	while (T--)
	{
		LL n = read(), m = read();
		if (m == 1)
		{
			printf("NO\n");
		}
		else if (m == 2)
		{
			printf("YES\n%lld %lld %lld\n", n, n * 3, n * 4);
		}
		else
		{
			printf("YES\n%lld %lld %lld\n", n, n * (m - 1), n * m);
		}

	}
	return 0;
}