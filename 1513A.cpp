#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
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
void work(int n,int k)
{
	if(n%2==1)
	{
		if(k>n/2)
		{
			printf("-1\n");
			return;
		}
		int pre=1,suf=n-k+1;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1||!k)
				printf("%d ",pre++);
			else if(k)
			{
				printf("%d ",suf++);
				k--;
			}
		}
		printf("\n");
		return;
	}
	if(k>n/2-1)
	{
		printf("-1\n");
		return;
	}
	int pre=1,suf=n-k+1;
	for(int i = 1; i<= n;i++)
	{
		if(i%2==1||!k)
			printf("%d ",pre++);
		else if(k)
		{
			printf("%d ",suf++);
			k--;
		}
	}
	printf("\n");
	return;
}
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		work(n,k);
	}
	return 0;
}