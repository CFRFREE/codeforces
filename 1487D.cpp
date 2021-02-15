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
		int x=sqrt(n*2-1);
		if(x%2==0)x--;
		printf("%d\n", (x-3)/2+1);
	}
	// for(int a = 1; a<= 98; a++)
	// 	for(int b=a+1;b<=99;b++)
	// 		for(int c=b+1;c<=100;c++)
	// 		{
	// 			if(a*a+b*b==c*c&&c+b==a*a)
	// 				printf("%d %d %d\n", a,b,c);
	// 		}
	return 0;
}