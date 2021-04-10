#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 100005
using namespace std;
vector<int> a,b;
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
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		double ans=0;
		a.clear(),b.clear();
		for(int i = 1; i<= n*2; i++)
		{
			int x=read(),y=read();
			if(!x)
				b.push_back(abs(y));
			else
				a.push_back(abs(x));
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int i=0;i<n;i++)
			ans+=sqrt(a[i]*a[i]+b[i]*b[i]);
		printf("%.20f\n",ans);
	}
	return 0;
}