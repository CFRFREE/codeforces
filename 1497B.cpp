#include <bits/stdc++.h>
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
int a[N],cnt[N];
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
	int T = read();
	while (T--)
	{
		int ans=0;
		memset(cnt, 0, sizeof(cnt));
		int n = read(), m = read();
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			cnt[x % m]++;
		}
		if (cnt[0])ans++;
		for (int i = 1; i <= m / 2; i++)
		{
			if(cnt[i]+cnt[m-i]==0)continue;
			if (abs(cnt[i] - cnt[m - i]) > 1)
				ans+=abs(cnt[i] - cnt[m - i])-1;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}