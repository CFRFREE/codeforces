#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 400005
using namespace std;
int T, n, a, b, k, boy[N], girl[N];
vector<int> bf[N],gf[N];
LL ans;
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
		a = read(), b = read(), k = read();
		for (int i = 1; i <= a; i++)
		{
			boy[i] = read();
		}
		for (int i = 1; i <= b; i++)
		{
			girl[i] = read();
			gf[boy[i]].push_back(girl[i]);
			bf[girl[i]].push_back(boy[i]);
		}
		for (int i = 1; i <= a; i++)
		{
			LL s = 0;
			for (int j = 0; j < gf[i].size(); j++)
				s += bf[ gf[i][j] ].size();
			ans += gf[i].size() * (k - s - 1);
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= a; i++)
			gf[i].clear();
		for (int i = 1; i <= b; i++)
			bf[i].clear();
		ans = 0;
	}
	return 0;
}