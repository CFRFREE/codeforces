#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int x[N], y[N];
LL ans_x, ans_y, n;
int d, min_x, min_y,p;
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
LL work1(int pos)
{
	LL sum = 0;
	for (int i = 1; i <= n; i++)
		sum += abs(x[i] - pos);
	return sum;
}
LL work2(int pos)
{
	LL sum = 0;
	for (int i = 1; i <= n; i++)
		sum += abs(y[i] - pos);
	return sum;
}
int main()
{
	int T = read();
	while (T--)
	{
		n = read();
		ans_x = ans_y = 1;
		min_x = min_y = INF;
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		for (int i = 1; i <= n; i++)
			x[i] = read(), y[i] = read();
		for (int i = 1; i <= n; i++)
		{
			min_x = min((LL)min_x, work1(x[i]));
			min_y = min((LL)min_y, work2(y[i]));
		}
		for (int i = 1; i <= n; i++)
			if (min_x == work1(x[i]))
			{
				p = i;
				break;
			}
		d = 1;
		while (min_x == work1(x[p] + d))
			d++;
		ans_x += d - 1;
		d = 1;
		while (min_x == work1(x[p] - d))
			d++;
		ans_x += d - 1;
		for (int i = 1; i <= n; i++)
			if (min_y == work2(y[i]))
			{
				p = i;
				break;
			}
		d = 1;
		while (min_y == work2(y[p] + d))
			d++;
		ans_y += d - 1;
		d = 1;
		while (min_y == work2(y[p] - d))
			d++;
		ans_y += d - 1;
		printf("%lld\n", ans_x*ans_y);
	}
	return 0;
}
