#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 1000005
using namespace std;
int prime[N];
vector<int>a;
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
	memset(prime,1,sizeof(prime));
	for(int i=2;i<=N;i++)
	{
		if(prime[i])
			for(int j=i<<1;j<=N;j+=i)
				prime[j]=0;
	}
	for(int i=2;i<=N;i++)
		if(prime[i])a.push_back(i);
	int T=read();
	while(T--)
	{
		int n=read();
		int x=upper_bound(a.begin(),a.end(),n)-a.begin();
		int a1=a[x];
		//printf("%d\n", a1);
		while(a[x+1]-a1<n)x++;
		printf("%lld\n", a[x+1]*a1);

	}
	return 0;
}