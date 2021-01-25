#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 300005
using namespace std;
int n, T, ans, vis[N];
vector<int> a;
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
	T = read();
	while (T--)
	{
		n = read();
		memset(vis, 0, sizeof(vis));
		a.clear();
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			a.push_back(x);
		}
		n = unique(a.begin(), a.end()) - a.begin();
		//a.resize(n);
		for (int i = 0; i < n; i++)
		{
			vis[a[i]]++;
			//printf("%d ", a[i]);
		}
		//printf("\n");
		vis[a[0]]--, vis[a[n - 1]]--;
		ans = INF;
		for (int i = 0; i < n; i++)
			ans = min(ans, vis[a[i]] + 1);
		printf("%d\n", ans);
	}
	return 0;
}