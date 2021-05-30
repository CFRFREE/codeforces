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
	while (isdigit(ch))
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
void work()
{
	int x = read();
	for (int i = 0; i * 111 <= x; i++)
		if ((x - 111 * i) % 11 == 0)
		{
			printf("YES\n");
			return;
		}
	printf("NO\n");
	return;
}
int main()
{
	int T = read();
	while (T--)
		work();
	return 0;
}