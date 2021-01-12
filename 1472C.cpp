#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int T,n,a[N],from[N],Next[N],to[N],v[N],vis[N],cnt,ans;
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
void add(int x,int y,int z)
{
	to[++cnt]=y;
	Next[cnt]=from[x];
	from[x]=cnt;
	v[cnt]=z;
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=from[x];i;i=Next[i])
	{
		int y=to[i];
		a[y]=max(a[y],a[x]+v[i]);
		if(!vis[y])dfs(y);
	}
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		memset(a,0,sizeof(a));
		memset(to,0,sizeof(to));
		memset(from,0,sizeof(from));
		memset(Next,0,sizeof(Next));
		memset(vis,0,sizeof(vis));
		cnt=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(i+a[i]<=n)
				add(i+a[i],i,a[i]);
			else
				add(n+1,i,a[i]);
		}
		memset(a,0,sizeof(a));
		dfs(n+1);
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		printf("%d\n", ans);
	}
	return 0;
}