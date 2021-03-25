#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n, m, cnt, to[N], from[N], Next[N], dfn[N], low[N], in[N], ans, vis[N];
stack<int>s;
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
inline void add(int x, int y)
{
	to[++cnt] = y;
	Next[cnt] = from[x];
	from[x] = cnt;
}
void tarjan(int x)
{
	low[x] = dfn[x] = ++cnt;
	in[x] = 1;
	s.push(x);
	for (int i = from[x]; i; i = Next[i])
	{
		int y = to[i];
		if (!vis[y])continue;
		if (!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (in[y])
			low[x] = min(low[x], dfn[y]);
	}
	if (low[x] == dfn[x])
	{
		int sum = 1;
		while (s.top() != x)
		{
			in[s.top()] = 0;
			s.pop();
			sum++;
		}
		in[s.top()] = 0;
		s.pop();
		if (sum <= 1)ans += 1;
		else ans += sum + 1;
	}
}
int main()
{
	int T = read();
	while (T--)
	{
		n = read(), m = read();
		memset(to, 0, sizeof(to));
		memset(from, 0, sizeof(from));
		memset(Next, 0, sizeof(Next));
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(vis, 0, sizeof(vis));
		ans = 0;
		for (int i = 1; i <= m; i++)
		{
			int x = read(), y = read();
			if (x == y)continue;
			add(x, y);
			vis[x] = 1;
		}
		cnt = 0;
		for (int i = 1; i <= n; i++)
			if (!dfn[i] && vis[i])tarjan(i);
		printf("%d\n", ans);
	}
	return 0;
}