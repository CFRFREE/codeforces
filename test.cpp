#include<bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n, cnt[N], ans=1;
int main()
{
	scanf("%d", &n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d", &x);
		int m=sqrt(x);
		for(int j=2;j<=m;j++)
			if(x%j==0)
			{
				
				cnt[j]++;
				ans=max(ans,cnt[j]);
				while(x%j==0)
					x/=j;
			}
		if(x>1)
		{
			cnt[x]++;
			ans=max(ans,cnt[x]);
		}
	}
	printf("%d", ans);
	return 0;
}