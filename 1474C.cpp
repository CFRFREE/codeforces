#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 1005
using namespace std;
int n, a[N], vis[1000005], sum;
vector<int>ans;
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
		n = read();
		n<<=1;
		memset(vis, 0, sizeof(vis));
		memset(a, 0, sizeof(a));
		ans.clear();
		for (int i = 1; i <= n; i++)
		{
			a[i] = read();
			vis[a[i]]++;
		}
		sort(a + 1, a + n + 1);
		sum=a[n];
		int m = n - 1;
		int flag = 1;
		while (m != 1)
		{
			flag = 0;
			for (int i = 1; i <= n; i++)
				if ((vis[a[i]] && vis[sum - a[i]] && (a[i] << 1) != sum) || (a[i] << 1 == sum) && vis[a[i]] >= 2)
				{
					m -= 2;
					vis[a[i]]--;
					vis[sum - a[i]]--;
					ans.push_back(a[i]);
					ans.push_back(sum-a[i]);
					sum = max(a[i],sum-a[i]);
					flag = 1;
					break;
				}
			if (!flag)
			{
				printf("NO\n");
				goto qaq;
			}
		}
		printf("YES\n");
		for (int i = 1; i <= n; i++)
			if (vis[i])printf("%d\n%d %d\n",a[i]+a[n], a[i], a[n]);
		for (int i = 1; i <= ans.size() / 2; i++)
			printf("%d %d\n", ans[i * 2 - 2], ans[i * 2-1]);
qaq:;
	}
	return 0;
}
