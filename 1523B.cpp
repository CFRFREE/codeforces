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
		int n = read();
		for (int i = 1; i <= n; i++)
			int x = read();
		printf("%d\n", n * 3);
		for (int i = 1; i <= n / 2; i++)
		{
			int x = i * 2 - 1, y = i * 2;
			printf("%d %d %d\n", 2, x, y);
			printf("%d %d %d\n", 1, x, y);
			printf("%d %d %d\n", 1, x, y);
			printf("%d %d %d\n", 2, x, y);
			printf("%d %d %d\n", 1, x, y);
			printf("%d %d %d\n", 1, x, y);
		}
	}
	return 0;
}