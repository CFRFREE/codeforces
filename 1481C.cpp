#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n, m, a[N], b[N], c[N], pos[N], ans[N];
stack<int>num[N];
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
void work()
{
	int flag=0;
	for (int i = m; i >= 1; i--)
	{
		if (num[c[i]].size())
		{
			flag = num[c[i]].top();
			ans[i] = num[c[i]].top();
			num[c[i]].pop();
		}
		else if (pos[c[i]])
		{
			ans[i] = pos[c[i]];
			flag = pos[c[i]];
		}
		else if(flag)
			ans[i]=flag;
		else
		{
			printf("No\n");
			return;
		}
	}
	for (int i = 1; i <= n; i++)
		if (num[b[i]].size())
		{
			printf("NO\n");
			return;
		}
	printf("YES\n");
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	printf("\n");
}
int main()
{
	int T = read();
	while (T--)
	{
		n = read(), m = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		for (int i = 1; i <= n; i++)
		{
			b[i] = read();
			pos[b[i]] = i;
			if (b[i] != a[i])
				num[b[i]].push(i);
		}
		for (int i = 1; i <= m; i++)
			c[i] = read();
		work();
		memset(pos, 0, sizeof(pos));
		for (int i = 1; i <= n; i++)
			while (num[b[i]].size())
				num[b[i]].pop();
	}
	return 0;
}