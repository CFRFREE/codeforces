#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 115
using namespace std;
int f[N][N];
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
	for (int i = 1; i < N; i++)
	{
		f[i][1] = i - 1;
		for (int j = 2; j < N; j++)
		{
			f[i][j] = f[i][j - 1] + i;
		}
	}
	while (T--)
	{
		int n = read(), m = read(), k = read();
		if (f[n][m] == k)printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}