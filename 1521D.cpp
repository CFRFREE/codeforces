#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
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
void dfs(int x, int father)
{
	int son[x] = -1;
	fa[x] = father;
	if (!a[x])
		son[father]++;
	for (auto y : a[x])
	{
		if (y != fa[x])
			dfs(y, x);
	}
	if (d[x] <= 2)continue;
	if (son[x] % 2 == 0)
	{
		int son_now = a[x][0];
		for (int i = 1; i < a[x].size(); i++)
		{
			ans1.push_back(a[x][1]);
			ans2.push_back(x);
			ans3.push_back(son_now);
			ans4.push_back(a[x][i]);
			d[son_now++];
			d[x]--;
			son_now = a[x][i];
		}
	}
	else
	{

	}
}
int main()
{
	int T = read();
	while (T--)
	{
		int n = read();
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			int x = read(), y = read();
			a[x].push_back(y);
			a[y].push_back(x);
			d[x]++;
			d[y]++;
		}
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			if (d[i] == 1)ans++;
		}
		printf("%d\n", (ans + 1) / 2);
		dfs(1, 1)
	}
	return 0;
}