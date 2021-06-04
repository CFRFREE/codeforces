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
void work()
{
	int n = read();
	int M = n;
	int tep = 0;
	int s = 0;
	int last = 0;
	while (n)
	{
		if (n % 2)
		{
			last = (1 << tep);
			s += (1 << tep);
		}
		tep++;
		n >>= 1;
	}
	printf("%d\n", M - s + last - 1);
}
int main()
{
	int T = read();
	while (T--)
		work();
	return 0;
}