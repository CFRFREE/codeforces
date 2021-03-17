#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 105
using namespace std;
int ok[N];
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
		int n = read(), q = read();
		memset(ok, 0, sizeof(ok));
		ok[q] = 1;
		for (int i = 1; i <= q - 1; i++)
			ok[i * 10 + q] = 1;
		for (int i = q; i <= 10 * (q - 1) + q; i++)
			if (ok[i])
			{
				int j=i;
				while (j <= q * 9)
					ok[j+=q] = 1;
			}
		for (int i = 1; i <= n ; i++)
		{
			int x = read();
			if (x >= q * 10 || ok[x])
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}