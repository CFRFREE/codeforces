#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 200005
using namespace std;
int a[N],b[N],m1,m2;
LL ans=INFF;
LL sum;
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
struct Node
{
	int w,id;
}c[N],d[N];
inline int cmp(Node x,Node y)
{
	return x.w>y.w;
}
int main()
{
	int n=read();
	for(int i = 1; i<= n; i++)
		a[i]=read();
	for(int i = 1; i<= n; i++)
	{
		b[i]=read();
		if(a[i]<b[i])
		{
			c[++m1].w=b[i]-a[i];
			c[m1].id=i;
		}
		else if(b[i]<a[i])
		{
			d[++m2].w=a[i]-b[i];
			d[m2].id=i;
		}
		sum+=abs(a[i]-b[i]);
	}
	sort(c+1,c+m1+1,cmp);
	sort(d+1,d+m2+1,cmp);

	m1=min(3000,m1);
	m2=min(3000,m2);
	if(m1*m2==0)
	{
		printf("%lld\n",sum);
		return 0;
	}
	ans=sum;
	for(int i=1;i<=m1;i++)
		for(int j=1;j<=m2;j++)
		{
			int x=c[i].id;
			int y=d[j].id;
			ans=min(ans,sum-abs(a[x]-b[x])-abs(a[y]-b[y])+abs(a[x]-b[y])+abs(a[y]-b[x]));
			//printf("%d %d\n%d %d\n",abs(a[x]-b[x]),abs(a[y]-b[y]),abs(a[x]-b[y]),abs(a[y]-b[x]));
		}
	
	printf("%lld\n",ans);	
	return 0;
}