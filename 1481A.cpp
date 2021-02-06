#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;

int yjia,yjian,xjian,xjia;
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
	int T=read();
	int n,m;
	string st;
	while(T--)
	{
		n=read(),m=read();
		cin>>st;
		yjia=yjian=xjia=xjian=0;
		for(int i=0;i<st.size();i++)
		{
			if(st[i]=='U')yjia++;
			if(st[i]=='D')yjian++;
			if(st[i]=='R')xjia++;
			if(st[i]=='L')xjian++;
		}
		//printf("%d %d %d %d\n", xjia,xjian,yjia,yjian);
		if((n>=0&&xjia>=n||n<=0&&-xjian<=n)&&(m>=0&&yjia>=m||m<=0&&-yjian<=m))printf("YES\n");
			else printf("NO\n");	
	}
	return 0;
}