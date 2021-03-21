#include <bits/stdc++.h>
#define INF 2147483647
#define int unsigned long long
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
int ok(int x)
{
	for (int i = 1; i * i * i < x; i++)
	{
		int l = 1, r = 10000;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			int ans = mid * mid * mid + i * i * i;
			// if(i==5779)
			// 	cout<<mid<<ans<<endl;
			if (ans == x)
				return 1;
			else if (ans < x)
				l = mid + 1;
			else 
				r = mid - 1;
		}
	}
	return 0;
}
signed main()
{
	int T = read();
	while (T--)
	{
		int x = read();
		if (ok(x))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}