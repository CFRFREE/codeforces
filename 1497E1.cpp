#include <bits/stdc++.h>
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 200005
using namespace std;
int ans;
int a[N];
LL maxn, mini;
unordered_set<LL>s;
vector<int>v;
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
void work(int x)
{
	for (register int i = 0; i < v.size(); i++)
	{
		if (x * v[i] > maxn)break;
		if (s.find(x * v[i]) != s.end())
		{
			ans++;
			s.clear();
			return;
		}
	}
	for (register int i = 0; i < v.size(); i++)
	{
		if (v[i]*mini > x)break;
		if ((x / v[i])*v[i] != x)continue;
		if (s.find(x / v[i]) != s.end())
		{
			ans++;
			s.clear();
			return;
		}
	}
}
int main()
{
	int T = read();
	while (T--)
	{
		int n = read(), k = read();
		s.clear();
		maxn = 0;
		for (register int i = 1; i <= n; i++)
		{
			a[i] = read();
			if (a[i] > maxn)maxn = a[i];
		}
		maxn = sqrt(maxn)+10;
		s.insert(a[1]);
		for (register int i = 1; i <= maxn; i++)
			v.push_back(i * i);
		maxn = a[1];
		mini = a[1];
		ans = 1;
		for (register int i = 2; i <= n; i++)
		{
			work(a[i]);
			s.insert(a[i]);
			if (a[i] > maxn)maxn = a[i];
			if (a[i] < mini)mini = a[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}