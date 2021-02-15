#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n, a[N];
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
		n = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		sort(a + 1, a + n + 1);
		int i = 1;
		while (a[i] == a[1])
			i++;
		i--;
		printf("%d\n", n - i);
	}
	return 0;
}