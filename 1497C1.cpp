#include <bits/stdc++.h>
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
		int n = read(), k = read();
		if (n % 2 == 1)
			printf("1 %d %d\n", n / 2, n / 2);
		else if (n % 4 == 0)
			printf("%d %d %d\n", n / 4, n / 4, n / 2);
		else
			printf("2 %d %d\n", n / 2 - 1, n / 2 - 1);
	}

	return 0;
}