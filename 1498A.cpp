#include <bits/stdc++.h>
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 100005
using namespace std;
int ans;
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
	int T = read();
	while (T--)
	{
		int x = read();
		while(1)
		{
			int X=x;
			int sum=0;
			while(X>0)
			{
				sum+=X%10;
				X/=10;
			}
			if(__gcd(sum,x)>1)
			{
				printf("%lld\n",x);
				break;
			}
			x++;
		}
	}
	return 0;
}