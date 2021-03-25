#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n, L, R, a[N];
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
	n = read();
	L = 1, R = n;
	a[0] = INF, a[n + 1] = INF;
	while (L <= R)
	{
		if (L == R)
		{
			printf("! %d\n", L);
			return 0;
		}
		int mid = (L + R) >> 1;
		if (!a[mid])
		{
			printf("? %d\n", mid);
			fflush(stdout);
			a[mid] = read();
		}
		if (!a[mid + 1])
		{
			printf("? %d\n", mid + 1);
			fflush(stdout);
			a[mid + 1] = read();
		}
		if (a[mid] < a[mid + 1])
			R = mid;
		else
			L = mid + 1;
	}
	return 0;
}