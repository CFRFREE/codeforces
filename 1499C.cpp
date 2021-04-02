#include <bits/stdc++.h>
#define P 1000000007
#define INF 8223372036854775807
#define INFF 9223372036854775807
#define int unsigned long long
#define N 200005
using namespace std;
int a[N], b[N];
int suma[N], sumb[N];
signed main()
{
	int T;
	scanf("%lld", &T);
	while (T--)
	{
		int n;
		scanf("%lld", &n);
		int mina = INF;
		int minb = INF;
		int ans = INF;
		memset(suma, 0, sizeof(suma));
		memset(sumb, 0, sizeof(sumb));
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 1)
			{
				int x;
				scanf("%lld", &x);
				a[(i + 1) / 2] = x;
			}
			else
			{
				int x;
				scanf("%lld", &x);
				b[(i + 1) / 2] = x;
			}
		}
		for (int i = 1; i <= (n + 1) / 2; i++)
			suma[i] = suma[i - 1] + a[i];
		for (int i = 1; i <= n - (n + 1) / 2; i++)
			sumb[i] = sumb[i - 1] + b[i];
		for (int i = 1; i <= n; i++)
		{
			if (i % 2)
			{
				if (a[(i + 1) / 2] < mina)mina = a[(i + 1) / 2];
				int stepa = (i + 1) / 2;
				int stepb = i / 2;
				int ans_now = sumb[stepb] + minb * (n -stepb) + suma[stepa] + mina * (n - stepa);
				ans = min(ans, ans_now);
			}
			else
			{
				if (b[i / 2] < minb)minb = b[i / 2];
				int stepa = i / 2;
				int stepb = i / 2;
				int ans_now = sumb[stepb] + minb * (n - stepb) + suma[stepa] + mina * (n -stepa);
				ans = min(ans, ans_now);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
// 4 2 4
//3 1
