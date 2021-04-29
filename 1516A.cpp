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
		int n = read(), k = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		int L = 1;
		int R = n;
		while (k-- && L < R)
		{
			a[L]--;
			a[R]++;
			while (a[L] < 0 && L < R)
			{
				a[L]++;
				L++;
				a[L]--;
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
	}
	return 0;
}