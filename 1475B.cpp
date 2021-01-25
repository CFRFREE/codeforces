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
		if(n<=2019)
			printf("NO\n");
		else
		{
			int p=0;
			for(int i=0;i*2020<=n;i++)
				for(int j=0;j*2021<=n;j++)
					if(i*2020+j*2021==n)
					{
						printf("YES\n");
						p=1;
						break;
					}
					if(!p)
						printf("NO\n");
		}
	}
	return 0;
}