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
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		if(n%2==0)
		{
			if(k%n==0)printf("%d\n", n);
				else printf("%d\n", k%n);
		}
		else
		{
			int x=n/2;
			int y=x+1;
			int zu=k/x;
			int djg=k%x;
			if(djg==0)djg=x;
			else zu++;
			int ans=(djg+(zu-1)*y)%n;
			if(ans==0)ans=n;
			printf("%d\n", ans);
		}

	}
	return 0;
}