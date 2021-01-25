#include <bits/stdc++.h>
#define INF 2147483647
#define int long long
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
signed main()
{
	int T = read();
	while (T--)
	{
		int p = 0;
		int n = read();
		while(n%2==0)n/=2;
		if(n%2&&n>1)
			printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}