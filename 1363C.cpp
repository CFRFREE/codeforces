#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int d[N],n,s;
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
		n=read(),s=read();
		memset(d,0,sizeof(d));
		for(int i = 1; i <= n-1; i++)
		{
			int x=read(),y=read();
			d[x]++;
			d[y]++;
		}
		if(d[s]<=1||n%2==0)
			printf("Ayush\n");
		else
			printf("Ashish\n");
	}
	return 0;
}