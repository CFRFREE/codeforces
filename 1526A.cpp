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
		n *= 2;
		for (int i = 1; i <= n; i++)
			a[i] = read();
		sort(a + 1, a + n + 1);
		int L = 1, R = n;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2)printf("%d ", a[L++]);
			else
				printf("%d ", a[R--]);
		}
		printf("\n");
	}
	return 0;
}