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
	int T=read();
	while(T--)
	{
		int x=read(),y=read();
		int ans=0;
		for(int i = 1; i*i<=x; i++)
			ans+=max(min(y,x/i-1)-i,(int)0);
		printf("%lld\n", ans);
	}
	return 0;
}