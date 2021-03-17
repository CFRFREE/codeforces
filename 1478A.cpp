#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int a[N];
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
	while(T--)
	{
		int n=read();
		int ans=1;
		for(int i=1;i<=n;i++)
			a[i]=read();
		int s=1;
		for(int i = 2; i<= n; i++)
			if(a[i]==a[i-1])
				s++;
			else
			{
				ans=max(ans,s);
				s=1;
			}
		ans=max(ans,s);
		printf("%d\n", ans);
	}
	return 0;
}