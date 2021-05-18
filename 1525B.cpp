#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
int a[N];
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
		int n = read();
		int p = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i] = read();
			if (a[i] < a[i - 1])p = 1;
		}
		if (!p)printf("0\n");
		else if (a[1] == n  && a[n] == 1)printf("3\n");
		else if (a[1] != 1 && a[n] != n)printf("2\n");
		else printf("1\n");
	}
	return 0;
}