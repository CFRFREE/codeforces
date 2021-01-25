#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int T,n,vis[N],id[N],a[N];
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
	T=read();
	while(T--)
	{
		int p=0;
		n=read();
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			vis[a[i]]++;
			id[a[i]]=i;
		}
		sort(a+1,a+n+1);
		for(int i = 1; i<= n; i++)
			if(vis[a[i]]==1)
			{
				printf("%d\n", id[a[i]]);
				p=1;
				break;
			}
		if(!p)
			printf("-1\n");
	}
	return 0;
}