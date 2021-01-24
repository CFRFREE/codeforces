#include <bits/stdc++.h>
#define INF 2147483647
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
	int T,n,m,vis[N],ans;
	T=read();
	while(T--)
	{
		ans=0;
		memset(vis,0,sizeof(vis));
		int n=read(),m=read();
		for(int i=1;i<=n;i++)
		{
			int x=read();
			vis[x]=1;
		}
		for(int i = 1; i<= m; i++)
		{
			int x=read();
			if(vis[x])ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}