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
		int a=read(),b=read();
		if(b>a)
			printf("1\n");
		else
		{
			int s=0;
			if(b==1)
			{
				b=2;
				s++;
			}
			while(a>0)
			{
				s++;
				if(log(a)*log(b+1)>log(a)*log(b)+log(b)*log(b+1))
					b+=1;
				else 
					a/=b;
			}
			printf("%d\n", s);
		}
	}
	return 0;
}