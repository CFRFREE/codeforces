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
		if(n%2)//奇数
		{
			for(int i=n-1;i>=1;i--)
			{
				int s=1;
				for(int j=1;j<=i;j++)
				{
					printf("%d ", s);
					s*=-1;
				}
			}
		}
		else
		{
			for(int i=1;i<=n-1;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(j==i+1&&i%2==1)
						printf("0 ");
					else
					{
						if((i+j)%2)printf("-1 ");
							else printf("1 ");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}