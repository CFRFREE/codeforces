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
	int T;
	T=read();
	while(T--)
	{
		int w=read(),h=read(),n=read();
		int cnt=1;
		while(w%2==0 || h%2==0)
		{
			cnt<<=1;
			if(w%2==0)
				w/=2;
			else 
				h/=2;	
		}
		if(cnt>=n)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}	