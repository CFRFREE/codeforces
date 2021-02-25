#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int a[N],b[N];
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
		for(int i = 1; i<= n; i++)
		{
			a[i]=read();
			b[i]=read();
		}
		sort(a+1,a+n+1);
		LL ans_x=a[(n+2)/2]-a[(n+1)/2]+1;
		sort(b+1,b+n+1);
		LL ans_y=b[(n+2)/2]-b[(n+1)/2]+1;
		printf("%lld\n", ans_y*ans_x);
	}
	return 0;
}