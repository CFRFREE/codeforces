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
		int a[4];
		a[0] = read(), a[1] = read(), a[2] = read(), a[3] = read();
		int x = max(a[0], a[1]);
		int y = max(a[3], a[2]);
		sort(a, a + 4);
		if (x == a[3] && y == a[2] || x == a[2] && y == a[3])printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}