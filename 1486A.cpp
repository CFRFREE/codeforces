#include <bits/stdc++.h>
#define INF 2147483647
#define int long long
#define N 100005
using namespace std;
int n,T,sum,p;
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
	T=read();
	while(T--)
	{
		n=read();
		sum=0;
		p=0;
		for(int i = 1; i<= n; i++)
		{
			int x=read();
			sum+=x;
			if(sum*2<(i-1)*i)
				p=1;
		}
		if(p)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}