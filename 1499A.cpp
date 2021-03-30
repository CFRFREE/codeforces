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
		int n = read(), k1 = read(), k2 = read();
		int w = read(), b = read();
		if (min(k1, k2) + abs(k1 - k2) / 2 < w || min(n-k1,n-k2)+abs(k1 - k2) / 2 < b )
			printf("NO\n");
		else 
			printf("YES\n");
	}
	return 0;
}