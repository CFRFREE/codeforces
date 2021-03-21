#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int a[3];
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
int work()
{
	if (a[0] >= 0 && a[1] >= 0 && a[2] <= 0)
		return (a[0] * 2 + a[1]);
	if (a[0] >= 0 && a[1] <= 0 && a[2] >= 0)
		return (a[0] + a[2] * 2);
	if (a[0] >= 0 && a[1] <= 0 && a[2] <= 0)
		return ((-a[1]) + (-2 * a[2]));
	if (a[0] <= 0 && a[1] <= 0 && a[2] >= 0)
		return (-a[0] - 2 * a[1]);
	if (a[0] <= 0 && a[1] >= 0 && a[2] <= 0)
		return (-2 * a[0] - a[2]);
	if (a[0] <= 0 && a[1] >= 0 && a[2] >= 0)
		return (a[1]*2+a[2]);
}
int main()
{
	int T = read();
	while (T--)
	{
		int n = read();
		a[0] = a[1] = a[2] = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			a[x % 3]++;
		}
		int x = n / 3;
		a[0] -= x, a[1] -= x, a[2] -= x;
		printf("%d\n", work());
	}
	return 0;
}