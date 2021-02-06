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
		int n=read();
		int k=read();
		if(k%n==0)printf("%d\n", k/n);
		else if(n%k==0)printf("1\n");
		else if(n<k)printf("%d\n", k/n+1);
		else printf("2\n");

	}
	return 0;
}